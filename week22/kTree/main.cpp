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
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int64 kMod = 1000000007;
int64 dp[105][105];
int k, d;

int64 f(int n, int c)
{
    if (n == 0) {
        return c > 0 ? 1 : 0;
    }

    int64 &ans = dp[n][c];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            ans = (ans + f(n - i, c + (i >= d))) % kMod;
        }
    }

    return ans;
}

int main(int argc, char **argv)
{
    int n;
    std::cin >> n >> k >> d;
    memset(dp, -1, sizeof dp);

    std::cout << f(n, 0) << std::endl;
    return EXIT_SUCCESS;
}
