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

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int main() {
    string S;
    cin >> S;
    vector<int64> f(256, 0);
    vector<int64> g(256, 0);
    int n = S.length();
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
        g[int(S[i])]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        int k = int(S[i]);
        g[k]--;
        f[k]++;
        ans += f[k];
        ans += g[k];
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}
