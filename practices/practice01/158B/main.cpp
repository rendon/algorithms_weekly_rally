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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int g[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g[x]++;
    }
    // for (int i = 1; i <= 4; i++) {
    //     cout << g[i] << endl;
    // }
    // cout << endl;
    int ans = g[4];

    int g31 = std::min(g[3], g[1]);
    ans += g31;
    g[3] -= g31;
    g[1] -= g31;
    ans += g[3];

    ans += g[2] / 2;
    g[2] %= 2;
    if (g[2] > 0) {
        int x = std::min(g[1], 2);
        ans++;
        g[1] -= x;
    }

    ans += g[1] / 4;
    g[1] %= 4;
    if (g[1] > 0) {
        ans++;
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}
