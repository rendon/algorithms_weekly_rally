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

int find(vector<int64>& S, int a, int b, int64 sum) {
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
    if (S[r] - S[l-1] == 0) {
        return r - l;
    }

    int64 total = S[r] - S[l-1];

    if (l == r || (total % 2 != 0)) {
        return 0;
    }
    int ans = 0;
    int start = l;
    if (start == -1) {
        return 0;
    }
    for (int i = start; i <= r; i++) {
        int64 ls = S[i] - S[l-1];
        int64 rs = S[r] - S[i];
        if (ls == rs) {
            ans = std::max(ans, std::max(f(S, l, i), f(S, i + 1, r)) + 1);
        } else if (ls > rs) {
            break;
        }
    }
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

