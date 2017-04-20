/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const int kMax      = 512;
// endregion

int matrix[kMax][kMax];

bool check(int M[kMax][kMax], int n, int k) {
    int zeros = 0;
    int required = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 0) {
                zeros++;
            }
            if (abs(j - i) > k) {
                required++;
            }
        }
    }
    return zeros >= required;
}

int f(int M[kMax][kMax], int n) {
    int l = 0;
    int h = n - 1;
    while (l < h) {
        int k = l + (h - l) / 2;
        if (check(M, n, k)) {
            h = k;
        } else {
            l = k + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << f(matrix, N) << "\n";
    }
    return EXIT_SUCCESS;
}
