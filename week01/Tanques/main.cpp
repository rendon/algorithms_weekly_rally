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
const int kMaxN = 2005;
const int kVertical = 0;
const int kHorizontal = 1;
// endregion


struct Tank {
    int x, y;
};

int dp[2][2][kMaxN];
Tank tanks[kMax];

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
    tanks[T] = {kOffset, kOffset};

    // Base case
    for (int p = 0; p < T; p++) {
        for (int d = 0; d <= 1; d++) {
            for (int v = 0; v < kMaxN; v++) {
                Tank tank = tanks[p];
                int x, y;
                if (d == kVertical) {
                    x = tanks[p+1].x;
                    y = v;
                } else {
                    y = tanks[p+1].y;
                    x = v;
                }

                int curr = p % 2;
                if (p == 0) {
                    dp[curr][d][v] = std::min(abs(tank.x - x), abs(tank.y - y));
                    continue;
                }
                int prev = (p + 1) % 2;
                int gox = dp[prev][kVertical][y] + abs(tank.x - x);
                int goy = dp[prev][kHorizontal][x] + abs(tank.y - y);
                dp[curr][d][v] = std::min(gox, goy);
            }
        }
    }

    cout << dp[(T-1)%2][0][kOffset] << endl;
    return EXIT_SUCCESS;
}
