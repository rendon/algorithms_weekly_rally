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
const int kMax      = 30;
const int kInf      = 1 << 30;
// endregion

int f[kMax][kMax];

bool check(int r1, int r2, int c1, int c2) {
    int a = f[r2][c2];
    int b = f[r1-1][c2];
    int c = f[r2][c1-1];
    int x = f[r1-1][c1-1];
    return a - b - c + x == 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid;
    grid.push_back(string(m, '.'));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        grid.push_back("." + row);
    }

    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '1') {
                s++;
            }
            f[i][j] = f[i-1][j] + s;
        }
    }

    int best = 0;
    for (int r1 = 1; r1 <= n; r1++) {
        for (int r2 = r1; r2 <= n; r2++) {
            for (int c1 = 1; c1 <= m; c1++) {
                for (int c2 = c1; c2 <= m; c2++) {
                    if (check(r1, r2, c1, c2)) {
                        int h = 2 * (r2 - r1 + 1);
                        int w = 2 * (c2 - c1 + 1);
                        best = std::max(best, h + w);
                    }
                }
            }
        }
    }

    cout << best << endl;
    return EXIT_SUCCESS;
}
