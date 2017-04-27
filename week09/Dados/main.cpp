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
const int kUndefined = -1;
// endregion

int64 dp[35][35];
int64 f(vector<int>& sides, int i, int d) {
    if (i == int(sides.size())) {
        return 1;
    }
    int64& ans = dp[i][d];
    if (ans != kUndefined) {
        return ans;
    }
    ans = 0;
    for (int j = d; j <= sides[i]; j++) {
        ans += f(sides, i + 1, j);
    }
    return ans;
}

int main() {
    int D;
    cin >> D;
    vector<int> sides(D);
    for (int& s : sides) {
        cin >> s;
    }
    memset(dp, kUndefined, sizeof dp);
    std::sort(sides.begin(), sides.end());
    cout << f(sides, 0, 1) << endl;
    return EXIT_SUCCESS;
}
