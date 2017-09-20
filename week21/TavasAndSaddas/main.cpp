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
#include <numeric>
#include <iomanip>
#include <algorithm>

using std::string;
using std::vector;
using std::map;
using std::set;
using std::queue;

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 20;
const int kInf      = 1 << 30;
// endregion

int dp[kMax][2];
int f(int i, bool lt, const string& v) {
    if (i == int(v.length())) {
        return 1;
    }
    int& ans = dp[i][lt];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    int x = v[i] - '0';
    for (int d = 0; d <= x || (lt && d < 9); d++) {
        if (d == 4 || d == 7) {
            ans += f(i + 1, lt | (d < x), v);
        }
    }
    return ans;
}

int g(int len) {
    return 1 << len;
}

int main() {
    int n;
    std::cin >> n;
    std::stringstream ss;
    ss << n;
    string v = ss.str();
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (int i = 1; i < v.length(); i++) {
        ans += g(i);
    }
    ans += f(0, false, v);
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
