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
// const double kEps   = 10e-8;
// const int kMax      = 1000;
// const int kInf      = 1 << 30;
// endregion

bool enough(vector<int64>& barbers, int64 t, int64 N) {
    int64 count = 0;
    for (int64 b : barbers) {
        count += t / b;
        if (t % b != 0) {
            count++;
        }
    }
    return count >= N;
}

int findBarber(vector<int64>& barbers, int64 B, int64 N) {
    int64 fastest = *std::min_element(barbers.begin(), barbers.end());
    int64 l = -1, h = 1000000001 * fastest;
    while (l < h) {
        int64 m = l + (h - l + 1) / 2;
        if (!enough(barbers, m, N)) {
            l = m;
        } else {
            h = m - 1;
        }
    }
    int64 t = h;
    vector<pair<double, int>> v;
    int64 count = 0;
    for (int i = 0; i < B; i++) {
        int64 b = barbers[i];
        if (t % b == 0) {
            v.push_back({100.0, i});
        } else {
            double p = 100.0 * (t % b) / b;
            v.push_back({100.0 - p, i});
        }
        count += t / barbers[i];
    }
    std::sort(v.begin(), v.end());
    N -= count;
    return v[N-1].second + 1;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int64 B, N;
        cin >> B >> N;
        vector<int64> barbers(B);
        for (int64& b : barbers) {
            cin >> b;
        }
        cout << "Case #" << tc << ": " << findBarber(barbers, B, N) << "\n";
    }
    return EXIT_SUCCESS;
}
