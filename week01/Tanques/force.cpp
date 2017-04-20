/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const int kOffset = 1000;
const int kMax = 5001;
// endregion


struct Tank {
    int x, y;

    bool operator<(const Tank& that) const {
        if (this->x != that.x) {
            return this->x < that.x;
        }
        return this->y < that.y;
    }

};

map<Tank, int> dp[kMax];
Tank tanks[kMax];

int f(int p, int x, int y) {
    Tank tank = tanks[p];
    if (p == 0) {
        return min(abs(tank.x - x), abs(tank.y - y));
    }
    Tank prev{x, y};
    if (dp[p].count(prev) == 1) {
        return dp[p][prev];
    }

    int gox = f(p - 1, tank.x, y) + abs(tank.x - x);
    int goy = f(p - 1, x, tank.y) + abs(tank.y - y);
    dp[p][prev] = min(gox, goy);
    return dp[p][prev];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> tanks[i].x >> tanks[i].y;
        tanks[i].x += kOffset;
        tanks[i].y += kOffset;
    }
    reverse(tanks, tanks + T);
    cout << f(T - 1, kOffset, kOffset) << endl;
    return EXIT_SUCCESS;
}
