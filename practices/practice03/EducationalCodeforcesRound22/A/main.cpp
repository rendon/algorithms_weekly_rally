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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    int t = 0;
    for (int& a : A) {
        cin >> a;
        t += a;
    }

    int m;
    cin >> m;
    int ans = -1;
    for (int i = 0; i < m && ans == -1; i++) {
        int a, b;
        cin >> a >> b;
        for (int s = a; s <= b; s++) {
            if (s >= t) {
                ans = s;
                break;
            }
        }
    }
    cout << ans;
    return EXIT_SUCCESS;
}
