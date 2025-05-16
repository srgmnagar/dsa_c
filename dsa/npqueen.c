#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 4

int board[N];

// Check if placing a queen at row and col is safe
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check same column or diagonal
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Try placing queen row by row
bool solve(int row) {
    if (row == N) {
        // All queens placed
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return true;  // return false here if you want all solutions
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;  // Place queen
            if (solve(row + 1))
                return true;
            // backtrack
        }
    }
    return false;
}

int main() {
    if (!solve(0))
        printf("No solution exists\n");
    return 0;
}
