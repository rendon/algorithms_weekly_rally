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
const int kInf      = 1 << 30;
const int kCameron = 0;
const int kJamie = 1;
const int kUndef = -1;
const int MINUTES_PER_DAY = 24 * 60;
// endregion

int dp[MINUTES_PER_DAY+5][721][2];

int f(int minute, int ft, int person, int day[], const int started) {
    if (minute == MINUTES_PER_DAY + 1) {
        if (ft == 0) {
            return 0;
        }
        return kInf;
    }
    int& ans = dp[minute][ft][person];
    if (ans != kUndef) {
        return ans;
    }
    ans = kInf;
    int m = minute + 1;
        int t = (m + 1) - minute;
        if (person != kCameron) {
            t = 0;
        }
        if (day[m+1] == person) {
            ans = std::min(ans, f(m + 1, ft - t, 1 - person, day, started) + 1);
            break;
        }
        int x = 0;
        if (m + 1 <= MINUTES_PER_DAY) {
            x++;
        } else if (started != person) {
            x++;
        }

        if (person == kCameron) {
            if (ft - t >= 0) {
                int v = f(m + 1, ft - t, 1 - person, day, started) + x;
                ans = std::min(ans, v);
            } else {
                break;
            }
        } else {
            int v = f(m + 1, ft, 1 - person, day, started) + x;
            ans = std::min(ans, v);
        }
    }
    return ans;
}

int solve(int day[]) {
    int ans = kInf;
    memset(dp, kUndef, sizeof dp);
    if (day[1] != kCameron) {
        ans = std::min(ans, f(1, 720, kCameron, day, kCameron));
    }
    if (day[1] != kJamie) {
        ans = std::min(ans, f(1, 720, kJamie, day, kJamie));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int day[24*60+5];
    for (int tc = 1; tc <= T; tc++) {
        int Ac, Aj;
        cin >> Ac >> Aj;
        memset(day, -1, sizeof day);
        for (int i = 0; i < Ac; i++) {
            int c, d;
            cin >> c >> d;
            for (int j = c; j <= d; j++) {
                day[j] = kCameron;
            }
        }
        for (int i = 0; i < Aj; i++) {
            int c, d;
            cin >> c >> d;
            for (int j = c; j <= d; j++) {
                day[j] = kJamie;
            }
        }
        cout << "Case #" << tc << ": " << solve(day) << "\n";
    }
    return EXIT_SUCCESS;
}
