#include <stdio.h>
#include <string.h>
int main()
{
    int count,src,i,j,k,w,v,min;

    int cost[100][100],dist[100],last[100];
    int vis[100];

    printf("\n Enter the no of routers");
    scanf("%d",&count); 

    //while inputting cost add -1 for nodes that are not connected directly
    printf("\n Enter the cost matrix values:");
    for(i=0;i<count;i++)
        {
            for(j=0;j<count;j++)
            {
                printf("\n%d->%d:  ",i,j);
                scanf("%d",&cost[i][j]);
                if(cost[i][j]<0)cost[i][j]=1000;
            }
        }
    
    printf("\n Enter the source router:");
    scanf("%d",&src);
    
    for(v=0;v<count;v++)
    {
        vis[v]=0;
        last[v]=src;
        dist[v]=cost[src][v];
    }
    vis[src]=1;

    for(i=0;i<count;i++)
    {
        min=1000;
            for(w=0;w<count;w++)
            {
                if(!vis[w]){
                    if(dist[w]<min)
                {
                    v=w;
                    min=dist[w];
                }
                }
                
            }
            vis[v]=1;
            for(w=0;w<count;w++){
                if(!vis[w]){
                    if(min+cost[v][w]<dist[w])
                    {
                    dist[w]=min+cost[v][w];
                    last[w]=v;
                    }
                }
                
        }
    }
    for(i=0;i<count;i++)
    {
        printf("\n%d==>%d:Path taken:%d",src,i,i);
        w=i;
        while(w!=src){
        printf("\n<--%d",last[w]);w=last[w];
        }

        printf("\n Shortest path cost:%d",dist[i]);
    }
}