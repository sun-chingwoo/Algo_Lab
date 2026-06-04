// Online C compiler to run C program online
#include <stdio.h>
#define INF 999
int cost[5][5] = {
    {0,   4,   8,   999, 999},
    {4,   0,   3,   6,   999},
    {8,   3,   0,   999, 2},
    {999, 6,   999, 0,   10},
    {999, 999, 2,   10,  0}
};
int n;

int main(){
    n=5;
    int src;
    printf("enter souce");
    scanf("%d",&src);
    
    int distance[n];
    int visited[n];
    for(int i=0;i<n;i++){
        distance[i]=cost[src][i];
        visited[i]=0;
    }
    distance[src]=0;
    visited[src]=1;
    
    int count=1;
    while(count < n-1 ){
        int mindis=INF;
        int nextnode;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(distance[i]<mindis){
                    mindis=distance[i];
                    nextnode=i;
                }
            }
        }
        
        visited[nextnode]=1;
        
        for(int i=0;i<n;i++){
            if(!visited[i] && distance[nextnode]+cost[nextnode][i]<distance[i]){
                distance[i]= distance[nextnode]+cost[nextnode][i];
            }
        }
        count++;
    }
    
    printf("the final distances are:");
    for(int i=0;i<n;i++){
        printf(" %d ",distance[i]);
    }
    return 0;
}
