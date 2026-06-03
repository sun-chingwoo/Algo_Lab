#include <stdio.h>

#define MAX 50

int id[MAX], weight[MAX], profit[MAX];
float ratio[MAX];

int main() {
    int n, i, j, W;
    int temp;
    float temp1;
    float total_profit = 0;

    printf("Enter number of goods: ");
    scanf("%d", &n);

    printf("Enter maximum weight: ");
    scanf("%d", &W);

    for(i = 0; i < n; i++) {
        printf("Enter id, weight and profit: ");
        scanf("%d %d %d", &id[i], &weight[i], &profit[i]);

        ratio[i] = (float)profit[i] / weight[i];
    }

    // Bubble sort (descending ratio)
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(ratio[j] < ratio[j+1]) {

                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;

                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp = id[j];
                id[j] = id[j+1];
                id[j+1] = temp;

                temp1 = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp1;
            }
        }
    }

    // Greedy selection
    for(i = 0; i < n; i++) {
        if(W <= 0) break;

        if(weight[i] <= W) {
            total_profit += profit[i];
            W -= weight[i];
            printf("%d\t%d\t%d\t%d\n", id[i], weight[i], profit[i], W);
        }
        else {
            float w = W;
            total_profit += ratio[i] * w;
            W = 0;

            printf("%d\t%.0f\t%.2f\t%d\n", id[i], w, ratio[i] * w, W);
        }
    }

    printf("\nTotal profit: %.2f\n", total_profit);

    return 0;
}
