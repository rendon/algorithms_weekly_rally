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

/*
bool test(int N, int K, int m, const string& S) {
    int w = 1;
    char p = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] == p) {
            w++;
            p = S[i];
            if (w > m) {
                if (K < 1) {
                    return false;
                }
                K--;
                w = 1;
                p = (S[i] == '1') ? '0' : '1';
            }
        } else {
            w = 1;
            p = S[i];
        }
    }
    return true;
}
*/

bool test(int N, int K, int m, const vector<int>& segments) {
    int size = segments.size();
    int p = 0;
    for (int i = 0; i < size; i++) {
        int s = segments[i];
        if (s <= m) {
            p = s;
            continue;
        }
        if (s == 2) {
            if (p >= m && (i + 1) < size) {
                return false;
            }
        }
        while (s > m) {
            if (K < 1) {
                return false;
            }
            K--;
            s -= m + 1;
            p = 1;
        }
        if (s > 0) {
            p = s;
        }
    }
    return true;
}

int solve(int N, int K, const string& S) {
    int l = 1;
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
