#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(char num[], int len)
{
    int dec_value = 0;
    int base = 1;

    for (int i = len-1; i >= 0; i--) 
    {
    
        if (num[i] == '1')
        dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
int sender(int data, int frameSize)
{
    //converting data into boolean 
    char arr[100];
    int p=0;
    while(data)
    {
        if(data%2==0)
        arr[p++] = '0';
        else
        arr[p++] = '1';

        data /= 2;

    }
    reverse(arr, arr+p);
    cout<<"The data in binary is = ";
    for(int i=0;i<p;i++)
    cout<<arr[i];
    cout<<endl;

    //finding out the number of frames and filling up the values
    int noOfFrames = p/frameSize;
    if(p%frameSize != 0)
    noOfFrames += 1;

    char v[100][100];
    int x=0, n = p/frameSize;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<frameSize;j++)
        v[i][j] = arr[x++];
    }
    
    if(noOfFrames==n+1)
    {
        for(int i=0;i<frameSize;i++)
        {
            if(x < p)
            v[n][i] = arr[x++];
                
            else
            v[n][i] = '0';
            
        }

    }
    cout<<"The frames are = ";
    for(int i=0;i<noOfFrames;i++)
    {
        for(int j=0;j<frameSize;j++)
        cout<<v[i][j];
        cout<<" ";
    }
    cout<<endl<<endl;
    

    //taking each row, converting the value into decimal and adding them up
    int sum=0;
    for(int i=0;i<noOfFrames;i++)
    {
        int decimal = binaryToDecimal(v[i], frameSize);
        sum += decimal;
    }
    int checksum = ~sum;

    return checksum;
    
}
bool receiver(int data, int checksum, int frameSize)
{
    //first three steps are same 
    //add checksum to the sum obtained
    //if we get 0 then answer is correct else its wrong
    //converting data into boolean 
    char arr[100];
    int p=0;
    while(data)
    {
        if(data%2==0)
        arr[p++] = '0';
        else
        arr[p++] = '1';

        data /= 2;

    }
    reverse(arr, arr+p);

    //finding out the number of frames and filling up the values
    int noOfFrames = p/frameSize;
    if(p%frameSize != 0)
    noOfFrames += 1;

    char v[100][100];
    int x=0, n = p/frameSize;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<frameSize;j++)
        v[i][j] = arr[x++];
    }
    
    if(noOfFrames==n+1)
    {
        for(int i=0;i<frameSize;i++)
        {
            if(x < p)
            v[n][i] = arr[x++];
                
            else
            v[n][i] = '0';
            
        }

    }

    //taking each row, converting the value into decimal and adding them up
    int sum=0;
    for(int i=0;i<noOfFrames;i++)
    {
        int decimal = binaryToDecimal(v[i], frameSize);
        sum += decimal;
    }

    sum += checksum;
    sum = ~sum;
    
    if(sum==0)
    return true;
    else
    return false;


}
int main()
{
    int data;
    cout<<"Enter the data to be sent - "<<endl;
    cin>>data;

    int frameSize;
    cout<<"Enter the frame size(in bits) - ";
    cin>>frameSize;

    cout<<endl;
    int checksum = sender(data, frameSize);
    cout<<endl<<"The checksum is "<<checksum<<endl;
    
    if(receiver(data, checksum, frameSize))
    cout<<"NO ERROR IN TRANSMISSION"<<endl;
    else
    cout<<"ERROR DETECTED"<<endl;
    
    

}