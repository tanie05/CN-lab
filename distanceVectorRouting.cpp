#include<iostream>
using namespace std;
struct node
{
    unsigned dist[20];
    unsigned from[20];
}
rt[10];

int main()
{
    int costmat[20][20];
    int nodes,i,j,k,count=0;

    cout<<"Enter the number of nodes "<<endl;
    cin>>nodes;
    
    cout<<"Enter the cost matrix"<<endl;

    
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            cin>>costmat[i][j];
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<nodes;i++){

                for(j=0;j<nodes;j++){
                
                for(k=0;k<nodes;k++){
                
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                {
                    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    rt[i].from[j]=k;
                    count++;
                }
            }
            }
            }
            
            
                
        }
        while(count!=0);
        
        for(i=0;i<nodes;i++)
        {
            cout<<endl<<endl<<"For router "<<i+1<<endl;
            for(j=0;j<nodes;j++)
            {
                printf("\t\nnode %d via %d Distance %d ",j+1,rt[i].from[j]+1,rt[i].dist[j]);
            }
        }
    cout<<endl<<endl;
    
}