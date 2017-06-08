/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 252

int grid[MAX_N][MAX_N];
int diff[MAX_N][MAX_N];

void index_grid(int N, int B) {
    int i, j, k;
    int min, max;
    int set[MAX_N];
    for (i = N - B; i >= 0; i--) {
        memset(set, 0, sizeof set);
        for (k = 0; k < B; k++) {
            for (j = N - B + 1; j <= N; j++) {
                set[grid[i+k][j]]++;
            }
        }
        for (j = N - B; j >= 0; j--) {
            for (k = 0; k < B; k++) {
                set[grid[i+k][j+B]]--;
                set[grid[i+k][j]]++;
            }
            min = 0;
            for (k = 0; k < MAX_N; k++) {
                if (set[k] > 0) {
                    min = k;
                    break;
                }
            }
            max = MAX_N;
            for (k = MAX_N - 1; k >= 0; k--) {
                if (set[k] > 0) {
                    max = k;
                    break;
                }
            }
            diff[i][j] = max - min;
        }
    }
}

int main() {
    int N, B, K;
    int i, j;
    int r, c;
    scanf("%d %d %d", &N, &B, &K);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    index_grid(N, B);
    for (i = 0; i < K; i++) {
        scanf("%d %d", &r, &c);
        printf("%d\n", diff[r-1][c-1]);
    }
    return EXIT_SUCCESS;
}
