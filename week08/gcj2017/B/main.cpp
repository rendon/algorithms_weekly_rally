/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
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
const int64 kInf = 1LL << 60;
const int kUndefined = -1;
// endregion

int64 dp[20][10][2];
int64 f(const string& digits, int p, int l, bool gt) {
    if (p == int(digits.length())) {
        return l == 0 ? -kInf : 0;
    }
    int64& ans = dp[p][l][gt];
    if (ans != kUndefined) {
        return ans;
    }

    int64 b = 1;
    for (int i = 0; i < (int(digits.length()) - p - 1); i++) {
        b *= 10;
    }
    ans = -kInf;
    int v = digits[p] - '0';
    for (int d = l; d <= 9; d++) {
        if (d <= v || gt) {
            ans = std::max(ans, b * d + f(digits, p + 1, d, gt || (d < v)));
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int64 N;
        cin >> N;
        char buf[20];
        sprintf(buf, "%llu", N);
        memset(dp, kUndefined, sizeof dp);
        cout << "Case #" << tc << ": " << f(string(buf), 0, 0, false) << "\n";

    }
    return EXIT_SUCCESS;
}
