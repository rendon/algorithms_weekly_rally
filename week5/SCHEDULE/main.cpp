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

bool test(int N, int K, int m, const vector<int>& segments) {
    int size = segments.size();
    for (int i = 0; i < size; i++) {
        int s = segments[i];
        if (s <= m) {
            continue;
        }
        while (s > m) {
            if (K < 1) {
                return false;
            }
            K--;
            s -= m + 1;
        }
    }
    return true;
}

bool canAlternate1(const string& S, int K) {
    for (int f = 0; f <= 1; f++) {
        int flips = 0;
        int bit = f;
        for (char c : S) {
            // cout << "c = " << c << "bit = " << (bit + '0')<< endl;
            if (c != bit + '0') {
                flips++;
            }
            bit = 1 - bit;
        }
        if (flips <= K) {
            // cout << "flips = " << flips << " K = " << K << endl;
            return true;
        }
    }
    return false;
}

int solve(int N, int K, const string& S) {
    if (canAlternate1(S, K)) {
        return 1;
    }
    int l = 2;
    int h = N + 1;
    vector<int> segments;
    int w = 1;
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i-1]) {
            w++;
        } else {
            segments.push_back(w);
            w = 1;
        }
    }
    segments.push_back(w);
    while (l < h) {
        int m = l + (h - l) / 2;
        if (test(N, K, m, segments)) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return l;
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
