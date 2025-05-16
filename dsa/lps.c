#include <stdio.h>
#include <string.h>
#define MAX 100

void computeLPS(char *pattern, int m, int lps[]) {
    int len = 0;  // length of the previous longest prefix suffix
    int ci = 1;   // current index

    lps[0] = 0;  // lps[0] is always 0

    while (ci < m) {
        if (pattern[ci] == pattern[len]) {
            len++;
            lps[ci] = len;
            ci++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[ci] = 0;
                ci++;
            }
        }
    }
}

void KMP(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[MAX];

    computeLPS(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    printf("Pattern found at positions: ");
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("%d ", i - j);  // match found
            j = lps[j - 1];        // continue searching
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    printf("\n");
}

int main() {
    char text[MAX], pattern[MAX];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    KMP(text, pattern);

    return 0;
}
