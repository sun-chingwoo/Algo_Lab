#include <stdio.h>
#define INF 99
int main(){
    int n, i, j, k;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int dist[n][n];

    printf("Enter the adjacency matrix:\n");
    printf("(Use %d for INF/no edge)\n", INF);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    
    printf("\nShortest Distance Matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
