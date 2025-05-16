#include <stdio.h>

int main() {
    int n = 3; // number of items
    float weight[] = {10, 20, 30};
    float profit[] = {60, 100, 120};
    float capacity = 50;

    // Calculate profit/weight ratio
    float ratio[100];
    for (int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort by ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // swap ratio
                float temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                // swap profit
                temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
                // swap weight
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
            }
        }
    }

    float totalProfit = 0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            totalProfit += profit[i];
            capacity -= weight[i];
        } else {
            totalProfit += ratio[i] * capacity;
            capacity = 0;
        }
    }

    printf("Maximum Profit: %.2f\n", totalProfit);
    return 0;
}
