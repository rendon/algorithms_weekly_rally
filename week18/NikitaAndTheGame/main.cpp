/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <bits/stdc++.h>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int upperBound(vector<int64>& S, int a, int b, int64 sum) {
    int l = a;
    int h = b + 1;
    while (l < h) {
        int m = l + (h - l) / 2;
        int64 x = S[m] - S[a-1];
        if (x > sum) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int lowerBound(vector<int64>& S, int a, int b, int64 sum) {
    int l = a;
    int h = b + 1;
    while (l < h) {
        int m = l + (h - l) / 2;
        int64 x = S[m] - S[a-1];
        if (x >= sum) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    if ((S[l] - S[a-1] != sum) || l >= b) {
        return -1;
    }
    return l;
}

int f(vector<int64>& S, int l, int r) {
    if (l == r) {
        return 0;
    }
    int64 total = S[r] - S[l-1];
    if (total == 0) {
        return r - l;
    }

    if (total % 2 == 1) {
        return 0;
    }

    int ans = 0;
    //int start = l;
    int start = lowerBound(S, l, r, total / 2);

    if (start == -1) {
        return 0;
    }

    int end = upperBound(S, l, r, total / 2);
    ans = std::max(ans, std::max(f(S, l, start), f(S, end, r)) + 1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64> S(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            S[i] = S[i-1] + x;
        }
        cout << f(S, 1, n) << endl;
    }
    return EXIT_SUCCESS;
}

