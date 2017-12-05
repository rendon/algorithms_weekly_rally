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
#include <numeric>
#include <iomanip>
#include <algorithm>

using std::string;
using std::vector;
using std::map;
using std::set;
using std::queue;

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

struct Cell {
    int pos, steps;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<string> grid(n);
    for (string& row : grid) {
        std::cin >> row;
    }
    vector<vector<int>> dist(n, vector<int>(m, kInf));
    for (int i = 0; i < n; i++) {
        queue<Cell> Q;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                Q.push({j, 0});
            }
        }
        while (!Q.empty()) {
            Cell next = Q.front();
            Q.pop();
            if (dist[i][next.pos] < next.steps) {
                continue;
            }

            dist[i][next.pos] = next.steps;

            int r = (next.pos + 1) % m;
            Q.push({r, next.steps + 1});

            int l = (next.pos - 1 + m) % m;
            Q.push({l, next.steps + 1});
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int c : dist[i]) {
    //         std::cout << c << " ";
    //     }
    //     std::cout << std::endl;
    // }
    int ans = kInf;
    for (int j = 0; j < m; j++) {
        int cost = 0;
        bool noway = false;
        for (int i = 0; i < n; i++) {
            if (dist[i][j] == kInf) {
                noway = true;
                break;
            }
            cost += dist[i][j];
        }
        if (noway) {
            continue;
        }
        ans = std::min(ans, cost);
    }
    if (ans == kInf) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ans << std::endl;
    }
    return EXIT_SUCCESS;
}
