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

int main() {
    int64 x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<int64> points;
    points.push_back(l - 1);
    points.push_back(r + 1);
    for (int64 xx = 1; xx <= r; ) {
        for (int64 yy = 1; yy <= r; ) {
            int64 n = xx + yy;
            if (l <= n && n <= r) {
                points.push_back(n);
            }
            if (yy < numeric_limits<int64>::max() / y) {
                yy *= y;
            } else {
                break;
            }
        }
        if (xx < numeric_limits<int64>::max() / x) {
            xx *= x;
        } else {
            break;
        }
    }
    std::sort(points.begin(), points.end());
    int64 ans = 0;
    for (int i = 1; i < int(points.size()); i++) {
        ans = std::max(ans, points[i] - points[i-1] - 1);
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}
