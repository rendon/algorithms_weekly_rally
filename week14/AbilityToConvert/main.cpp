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
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

const int64 kLimit = 1000000000000000000LL;
int64 dp[64];
string str;
int64 f(int p, const int n) {
    if (p == 0) {
        return 0LL;
    }

    int64& ans = dp[p];
    if (ans != -1) {
        return ans;
    }
    cout << "p = " << p << endl;
    if (str[p] == '0') {
        return ans = kLimit;;
    }
    ans = numeric_limits<int64>::max();
    int64 v = 0;
    int d = log10(n) + 1;
    for (int i = 0; i < d && p - i >= 1; i++) {
        v = v * n + str[p-i] - '0';
        // if (v >= n) {
        //     break;
        // }
        cout << "v = " << v <<endl;
        int64 x = f(p - i - 1, n);
        if (v + x <= kLimit) {
            ans = std::min(ans, v + x);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n >> str;
    std::reverse(str.begin(), str.end());
    str = "." + str;
    memset(dp, -1, sizeof dp);
    cout << "k = " << str << endl;
    cout << f(str.length() - 1, n);
    return EXIT_SUCCESS;
}
