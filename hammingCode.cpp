#include<bits/stdc++.h>
using namespace std;
void receiver(int v[])
{
    //calculate parities 
    //if all zero implies no error 
    //the parities which are zeroes gives us the bit position where the error has occured
    int p1, p2, p4, p8;
    //sum should be even
    p1 = v[1] + v[3] + v[5] + v[7] + v[9] + v[11];
    p2 = v[2] + v[3] + v[6] + v[7] + v[10] + v[11];
    p4 = v[4] + v[5] + v[6] + v[7];
    p8 = v[8] + v[9] + v[10] + v[11];

    p1 = p1%2;//0
    p2 = p2%2;//1
    p4 = p4%2;//2
    p8 = p8%2;//4

    if(!p1 && !p2 && !p4 && !p8) 
    {
        cout<<"No error in transmission"<<endl;
    }
    else
    {
        int pos = p1*1 + p2*2 + p4*4 + p8*8;
        cout<<"The error occured at bit position "<<pos<<endl;
        cout<<"Transmitted bit value - "<<v[pos]<<endl;
        cout<<"Original bit value - ";
        if(v[pos]) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }


}
int redundantVal(int vec[], int r)
{
    int count=0;
    for(int i=11;i>=1;i--)
    {
        if(r==1)
        {
            if((i==1 || i==3 || i==5 || i==7 || i==9 || i==11) && vec[i] == 1)
            count++;
            
        }
        if(r==2)
        {
            if((i==2 || i==3 || i==6 || i==7 || i==10 || i==11) && vec[i] == 1)
            count++;
        }
        if(r==3)
        {
            if((i==4 || i==5 || i==6 || i==7) && vec[i] == 1)
            count++;
            
        }
        if(r==2)
        {
            if((i==8 || i==9 || i==10 || i==11) && vec[i] == 1)
            count++;
        }

    }
    if(count%2==0)
    return 0;
    return 1;

}
void sender(int a[])
{
    int v[12];
    
    int j=7;
    for(int i=11;i>=1;i--)
    {
        if(i==1 || i==2 || i==4 || i==8)
        {
            v[i] = 0;
            continue;
        }
        else
        v[i] = a[j--];

    }

    v[1] = redundantVal(v,1);
    v[2] = redundantVal(v,2);
    v[4] = redundantVal(v,3);
    v[8] = redundantVal(v,4);

    cout<<"String sent - "<<endl;
    
    for(int i=11;i>=1;i--)
    { 
        cout<<v[i]<<" ";
    }
    cout<<endl;

    
    receiver(v);
    

}

int main()
{
    int arr[8];
    cout<<"Enter the bits of data one by one "<<endl;
    
    for(int i=7;i>=1;i--)
    cin>>arr[i];

    sender(arr);




}