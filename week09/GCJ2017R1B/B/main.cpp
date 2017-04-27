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
const int kRed = 0;
const int kYellow = 1;
const int kBlue = 2;
const int kNo = 0;
const int kYes = 1;
// endregion

const int kMax = 1002;
map<tuple<int, int, int, int>, int> dp[kMax];
map<tuple<int, int, int, int>, int> nextColor[kMax];
int N;
int f(int p, const int start, int prev, int red, int yellow, int blue) {
    if (p == N) {
        if (prev != start) {
            return kYes;
        }
        return kNo;
    }
    tuple<int, int, int, int> conf{prev, red, yellow, blue};
    if (dp[p].count(conf) == 1) {
        return dp[p][conf];
    }
    if (red > 0 && prev != kRed) {
        if (f(p + 1, start, kRed, red - 1, yellow, blue) == kYes) {
            nextColor[p][conf] = kRed;
            return kYes;
        }
    }
    if (yellow > 0 && prev != kYellow) {
        if (f(p + 1, start, kYellow, red, yellow - 1, blue) == kYes) {
            nextColor[p][conf] = kYellow;
            return kYes;
        }
    }
    if (blue > 0 && prev != kBlue) {
        if (f(p + 1, start, kBlue, red, yellow, blue - 1) == kYes) {
            nextColor[p][conf] = kBlue;
            return kYes;
        }
    }
    nextColor[p][conf] = -1;
    dp[p][conf] = kNo;
    return kNo;
}

void printSolution(int color) {
    map<int, char> colorMap{{kRed, 'R'}, {kYellow, 'Y'}, {kBlue, 'B'}};
    cout << colorMap[color] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int R, O, Y, G, B, V;
        cin >> N;
        cin >> R >> O >> Y >> G >> B >> V;
        cout << "Case #" << tc << ": ";
        // R
        // Y
        // B
        if (R > 0 && f(1, kRed, kRed, R - 1, Y, B) == kYes) {
            for (int i = 0; i < kMax; i++) {
                dp[i].clear();
                nextColor[i].clear();
            }
            printSolution(kRed);
        } else if (Y > 0 && f(1, kYellow, kYellow, R, Y - 1, B) == kYes) {
            for (int i = 0; i < kMax; i++) {
                dp[i].clear();
                nextColor[i].clear();
            }
            printSolution(kYellow);
        } else if (B > 0 && f(1, kBlue, kBlue, R, Y, B - 1) == kYes) {
            for (int i = 0; i < kMax; i++) {
                dp[i].clear();
                nextColor[i].clear();
            }
            printSolution(kYellow);
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return EXIT_SUCCESS;
}
