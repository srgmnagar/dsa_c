#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char x[MAX], y[MAX];
    printf("Enter string 1: ");
    scanf("%s", x);
    printf("Enter string 2: ");
    scanf("%s", y);

    int m = strlen(x);
    int n = strlen(y);

    int l[m+1][n+1];  // DP table for LCS length

    // Build the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                l[i][j] = 0;  // Base case: empty substring
            } else if (x[i-1] == y[j-1]) {
                l[i][j] = l[i-1][j-1] + 1;  // If chars match
            } else {
                l[i][j] = (l[i-1][j] > l[i][j-1]) ? l[i-1][j] : l[i][j-1]; // Take max of left or top
            }
        }
    }

    // Print the length of LCS
    printf("Length of LCS: %d\n", l[m][n]);

    // Now reconstruct the LCS from the table
    int index = l[m][n];
    char lcs[index+1];
    lcs[index] = '\0';  // Null terminate the string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            lcs[index-1] = x[i-1];  // Put current char in result
            i--; j--; index--;
        } else if (l[i-1][j] > l[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS: %s\n", lcs);

    return 0;
}
