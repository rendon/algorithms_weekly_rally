/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cctype>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// const double kEps   = 10e-8;
const int kMax      = 1002;
const int kInf      = 1 << 30;
const int kUndefined = -1;
const int kNoLetter = 26;
// endregion

int dp[kMax][27];

int f(int pos, int prev, const vector<vector<int>>& chunks) {
    if (pos < 0) {
        return 0;
    }
    int& ans = dp[pos][prev];
    if (ans != kUndefined) {
        return ans;
    }
    vector<int> chunk = chunks[pos];
    int len = chunk.size();
    if (len == 1) {
        ans = (chunk[0] == prev) ? 0 : 1;
        ans += f(pos - 1, chunk[0], chunks);
    } else {
        ans = kInf;
        for (int i = 0; i < len; i++) {
            int v = (chunk[i] == prev) ? len - 1 : len;
            for (int j = 0; j < len; j++) {
                if (j == i) {
                    continue;
                }
                ans = std::min(ans, v + f(pos - 1, chunk[j], chunks));
            }
        }
    }
    return ans;
}

int solve(int k, const string& S) {
    int n = S.length();
    vector<vector<int>> chunks;
    for (int i = 0; i < n; i += k) {
        map<char, bool> m;
        for (int j = 0; j < k; j++) {
            m[S[i+j]] = true;
        }
        vector<int> letters;
        for (auto e : m) {
            letters.push_back(e.first - 'a');
        }
        chunks.push_back(letters);
    }
    memset(dp, kUndefined, sizeof dp);
    return f(n / k - 1, kNoLetter, chunks);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int k;
        string S;
        cin >> k >> S;
        cout << solve(k, S) << "\n";
    }
    return EXIT_SUCCESS;
}
