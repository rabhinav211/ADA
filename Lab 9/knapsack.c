#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}
 
void knapsack(int n, int W, int weights[], int values[]) {
    int i, w;
    int dp[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("DP Table:\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            printf("%d\t", dp[i][w]);
        }
        printf("\n");
    }

    printf("Selected items: ");
    int res = dp[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == dp[i-1][w])
            continue;
        else {
            printf("%d ", i);
            res = res - values[i-1];
            w = w - weights[i-1];
        }
    }
    printf("\nMaximum profit: %d\n", dp[n][W]);
}

int main() {
    int n = 4; 
    int weights[] = {2, 3, 4, 5}; 
    int values[] = {3, 4, 5, 8}; 
    int W = 5;

    knapsack(n, W, weights, values);
    return 0;
}
