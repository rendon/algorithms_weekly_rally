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
#include <iomanip>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 53;
const int kInf      = 1 << 30;
// endregion

int dist[kMax][kMax][kMax*kMax];
struct State {
    int row, col, cost;
};

int solve(vector<string>& grid, int k) {
    for (int a = 0; a < kMax; a++) {
        for (int b = 0; b < kMax; b++) {
            for (int i = 0; i < kMax * kMax; i++) {
                dist[a][b][i] = kInf;
            }
        }
    }

    queue<State> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = true;
    int n = grid.size();
    int m = grid[0].length();
    int best = kInf;
    while (!Q.empty()) {
        State state = Q.front();
        Q.pop();
        int r = state.row;
        int c = state.col;
        if (grid[r][c] == '*') {
            if (state.cost <= k) {
                cout << r << " " << c << " : " << state.cost << endl;
                best = std::min(best, state.cost);
            }
            continue;
        }

        if (r > 0) {
            int x = state.cost + 1;
            if (grid[r][c] == 'U') {
                x--;
            }
            if (x < dist[r-1][c][x]) {
                dist[r-1][c][x] = x;
                Q.push({r - 1, c, x});
            }
        }

        if (r + 1 < n) {
            int x = state.cost + 1;
            if (grid[r][c] == 'D') {
                x--;
            }
            if (x < dist[r+1][c][x]) {
                dist[r+1][c][x] = x;
                Q.push({r + 1, c, x});
            }
        }

        if (c > 0) {
            int x = state.cost + 1;
            if (grid[r][c] == 'L') {
                x--;
            }
            if (x < dist[r][c-1][x]) {
                dist[r][c-1][x] = x;
                Q.push({r, c - 1, x});
            }
        }

        if (c + 1 < m) {
            int x = state.cost + 1;
            if (grid[r][c] == 'R') {
                x--;
            }
            if (x < dist[r][c+1][x]) {
                dist[r][c+1][x] = x;
                Q.push({r, c + 1, x});
            }
        }
    }
    if (best == kInf) {
        return -1;
    }
    return best;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (string& row : grid) {
        cin >> row;
    }
    for (string row : grid) {
        cout << row << endl;
    }
    cout << solve(grid, k) << endl;
    return EXIT_SUCCESS;
}
