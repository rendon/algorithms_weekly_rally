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
// endregion

const int kUndef = -1;
// const int kInf = numeric_limits<int>::max();
const int kInf = 1 << 30;

int fdp[55][128];
int f(std::vector<int>& a, int p, int mask, const int goal) {
    if (p == int(a.size())) {
        if (mask == goal) {
            return 0;
        }
        return kInf;
    }
    int& ans = fdp[p][mask];
    if (ans != kUndef) {
        return ans;
    }

    ans = std::min(f(a, p + 1, mask, goal), f(a, p + 1, mask | a[p], goal) + 1);
    return ans;
}

long long gdp[55][55][64];
long long g(vector<int>& a, int p, int s, int mask, const int mc) {
    if (p == int(a.size())) {
        if (s > 0 && mask / s == mc) {
            return 1;
        }
        return 0;
    }
    long long& ans = gdp[p][s][mask];
    if (ans != kUndef) {
        return ans;
    }
    ans = g(a, p + 1, s, mask, mc) + g(a, p + 1, s + 1, mask | a[p], mc);
    return ans;
}

long long coolSubsets(std::vector<int> a) {
    int maxCoolness = 0;
    for (int goal = 1; goal < 64; goal++) {
        memset(fdp, kUndef, sizeof fdp);
        int minWays = f(a, 0, 0, goal);
        if (minWays != kInf) {
            maxCoolness = std::max(maxCoolness, goal / minWays);
        }
    }
    memset(gdp, kUndef, sizeof gdp);
    return g(a, 0, 0, 0, maxCoolness);
}

int main() {
    vector<int> a{1, 7, 2, 7};
    cout << coolSubsets(a) << endl;
    return EXIT_SUCCESS;
}
