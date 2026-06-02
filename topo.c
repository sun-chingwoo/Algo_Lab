// Online C compiler to run C program online
#include <stdio.h>
#define M 100
int adj[M][M];
int indegree[M];
int q[M];
int v,e;
int ans[M];

void topo_sort(){
    int front=0,rear=0,i;
    for(i=0;i<v;i++){
        if(indegree[i]==0){
            q[rear]=i;
            rear++;
        }
    }
    int count=0;
    int curr;
    while(front<rear){
        curr=q[front];
        ans[count]=curr;
        front++;
        count++;
        for(i=0;i<v;i++){
            if(adj[curr][i]==1){
                indegree[i]--;
                if(indegree[i]==0){
                    q[rear]=i;
                    rear++;
                }
            }
        }
    }
    if(count!=v){
        printf("loops ");
        return;
    }
    for(i=0;i<v;i++){
        printf("%d",ans[i]);
    }
    return;
}

int main() {
    int i,j,x,y;
    printf("enter number of vertices");
    scanf("%d",&v);
    printf("enter number of edges");
    scanf("%d",&e);
    
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            adj[i][j]=0;
        }
    }
    for(i=0;i<v;i++){
        indegree[i]=0;
    }
    printf("enter the edges from to ");
    for(i=0;i<e;i++){
        scanf("%d%d",&x,&y);
        adj[x][y]=1;
        indegree[y]+=1;
    }
    topo_sort();

    return 0;
}
