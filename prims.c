// Online C compiler to run C program online
#include <stdio.h>
int adj[200][200];
int n;
int minnode(int key[],int mstset[]){
    int min=999,mi;
    for(int i=0;i<n;i++){
        if(mstset[i]==0 && key[i]<min){
            min=key[i];
            mi=i;
        }
    }
    return mi;
}

void printmst(int key[],int parent[]){
    printf("edges are from ");
    int ans=0;
    for(int  i=0;i<n;i++){
        printf("%d to %d of cost %d \n",parent[i],i,key[i]);
        ans+=key[i];
    }
    printf("min wrihgt %d",ans);
}

void prims(){
    int key[n],parent[n],mstset[n];
    for(int i=0;i<n;i++){
        key[i]=999;
        mstset[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    
    for(int i=0;i<n;i++){
        int node=minnode(key,mstset);
        mstset[node]=1;
        
        for(int j=0;j<n;j++){
            if(adj[node][j]!=0 && mstset[j]==0 && adj[node][j]<key[j]){
                key[j]=adj[node][j];
                parent[j]=node;
            }
        }
    }
    printmst(key,parent);
}

int main() {
    n = 4;

    int temp[4][4] = {
        {0, 2, 3, 0},
        {2, 0, 1, 4},
        {3, 1, 0, 5},
        {0, 4, 5, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = temp[i][j];
        }
    }

    prims();

    return 0;
}
