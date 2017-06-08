/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000005;
const int kInf      = 1 << 30;
const int kUndef = -1;
const int kMod = 1000000007;
// endregion

int dp[kMax][2][2];

int g(int n) {
    // p  t  s
    dp[1][1][1] = 1;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    dp[1][0][0] = 0;
    for (int p = 2; p <= n; p++) {
        for (int t = 0; t <= 1; t++) {
            for (int start = 0; start <= 1; start++) {
                int& ans = dp[p][t][start];
                ans = 0;
                if (t == 0) {
                    ans = dp[p-1][1-t][start];
                } else {
                    ans = dp[p-1][1-t][start] + dp[p-1][t][start];
                    if (ans >= kMod) {
                        ans -= kMod;
                    }
                }
            }
        }
    }
    return (dp[n][0][0] + dp[n][1][1]) % kMod;
}

int main() {
    int n;
    cin >> n;
    cout << g(n) << "\n";
    return EXIT_SUCCESS;
}
