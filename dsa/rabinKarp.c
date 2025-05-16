#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 256   // Total possible characters
#define PRIME_MOD 101       // A prime number for hashing

void rabinKarp(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int textHash = 0;         // Hash value for current window of text
    int patternHash = 0;      // Hash value for pattern
    int hashMultiplier = 1;
    int i, j;

    // Calculate (ALPHABET_SIZE ^ (patternLength - 1)) % PRIME_MOD
    for (i = 0; i < patternLength - 1; i++)
        hashMultiplier = (hashMultiplier * ALPHABET_SIZE) % PRIME_MOD;

    // Calculate the hash of the pattern and first window of text
    for (i = 0; i < patternLength; i++) {
        patternHash = (ALPHABET_SIZE * patternHash + pattern[i]) % PRIME_MOD;
        textHash = (ALPHABET_SIZE * textHash + text[i]) % PRIME_MOD;
    }

    // Slide the pattern over the text
    for (i = 0; i <= textLength - patternLength; i++) {
        // If hash values match, compare the actual characters
        if (patternHash == textHash) { 
            for (j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == patternLength)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash for the next window
        if (i < textLength - patternLength) {
            textHash = (ALPHABET_SIZE * (textHash - text[i] * hashMultiplier) + text[i + patternLength]) % PRIME_MOD;

            // Convert negative hash to positive
            if (textHash < 0)
                textHash = textHash + PRIME_MOD;
        }
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    rabinKarp(text, pattern);
    return 0;
}
