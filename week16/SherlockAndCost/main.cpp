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
const int kMax      = 100005;
const int kInf      = 1 << 30;
// endregion

int dp[kMax][2];

int f(int i, int t, vector<int>& B) {
    if (i == 0) {
        return 0;
    }
    int& ans = dp[i][t];
    if (ans != -1) {
        return ans;
    }
    int v = (t == 1) ? B[i] : 1;
    int a = std::abs(v - 1) + f(i -1, 0, B);
    int b = std::abs(v - B[i-1]) + f(i - 1, 1, B);
    return ans = std::max(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> B(N);
        for (int& b : B) {
            cin >> b;
        }
        memset(dp, -1, sizeof dp);
        cout << std::max(f(N - 1, 0, B), f(N - 1, 1, B)) << "\n";
    }
    return EXIT_SUCCESS;
}
