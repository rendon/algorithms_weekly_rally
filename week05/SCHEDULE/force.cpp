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
// endregion

int solve(int N, int K, const string& S) {
    int best = 1000;
    for (int mask = 0; mask < (1 << N); mask++) {
        int diff = 0;
        for (int i = 0; i < N; i++) {
            char b = (mask & (1 << i)) ? '1' : '0';
            if (S[i] != b) {
                diff++;
            }
        }
        if (diff > K) {
            continue;
        }
        int mw = 1;
        int w = 1;
        bool p = (mask & 1) != 0;
        for (int i = 1; i < N; i++) {
            bool c = (mask & (1 << i)) != 0;
            if (c == p) {
                w++;
            } else {
                w = 1;
            }
            mw = std::max(mw, w);
            p = c;
        }
        mw = std::max(mw, w);
        best = std::min(best, mw);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        string S;
        cin >> N >> K >> S;
        cout << solve(N, K, S) << "\n";
    }
    return EXIT_SUCCESS;
}
