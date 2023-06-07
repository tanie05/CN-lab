//write a program to compute hamming distance between two codewords
#include<bits/stdc++.h>
using namespace std;
int hammingDist(int a[], int b[], int n)
{
    int c[n];
    int d=0;
    for(int i=0;i<n;i++)
    {
        c[i] = a[i] xor b[i];
        if(c[i]==1)
        d++;

    }
    return d;
    

}
int main()
{
    int n;
    cout<<"Enter number of bits in codewords - ";
    cin>>n;

    int a[n], b[n];
    cout<<"Enter the first codeword bit by bit"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"Enter the second codeword bit by bit"<<endl;
    for(int i=0;i<n;i++)
    cin>>b[i];

    cout<<"The hamming distance between the two codewords is "<<hammingDist(a, b, n)<<endl;


}
