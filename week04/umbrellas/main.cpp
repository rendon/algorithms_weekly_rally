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
// const double kEps   = 10e-8;
// const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int f(int p, int v, const vector<int>& X) {
    int l = 0;
    int h = p;
    while (l < h) {
        int m = (l + h + 1) / 2;
        if (X[m] < v) {
            l = m;
        } else {
            h = m - 1;
        }
    }
    return h;
}

int64 minimumPurchaseCost(const vector<int>& X, const vector<int>& C) {
    int N = X.size() - 1; // Original size
    vector<int64> dp(N + 1, kInf);

    int M = C.size() - 1;
    vector<int> minCostIdx(M + 1);
    int minIdx = M;
    for (int i = M; i >= 1; i--) {
        if (C[i] < C[minIdx]) {
            minIdx = i;
        }
        minCostIdx[i] = minIdx;
    }

    // Base case
    dp[0] = 0;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= j; i++) {
            int64 d = X[j] - X[i] + 1;
            int w = minCostIdx[d];
            int cost = C[w];
            dp[j] = std::min(dp[j], cost + dp[f(i - 1, X[j] - w + 1, X)]);
        }
    }
    return dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    for (int& x : X) {
        cin >> x;
    }
    std::sort(X.begin(), X.end());
    vector<int> C(M);
    for (int& c : C) {
        cin >> c;
    }

    // Sentinel values to use indexes from 1 to length, inclusive
    X.insert(X.begin(), 0);
    C.insert(C.begin(), 0);
    cout << minimumPurchaseCost(X, C) << endl;
    return EXIT_SUCCESS;
}
