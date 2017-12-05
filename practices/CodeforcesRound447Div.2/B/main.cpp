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

void print(int mask, int n, int m) {
    std::cout << "n = " << n << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = i * n + j;
            if (mask & (1 << idx)) {
                std::cout << "1";
            } else {
                std::cout << "0";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void simulate(int64 n, int64 m, int64 k) {
    std::cout << n << " " << m << ": ";
    int64 power = 1LL << (n * m);
    vector<vector<int>> grid(n, vector<int>(m));
    int ans = 0;
    for (int mask = 0; mask < power; mask++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int idx = i * n + j;
                if (mask & (1 << idx)) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = -1;
                }
            }
        }
        bool valid = true;
        for (int i = 0; i < n; i++) {
            int p = 1;
            for (int j = 0; j < m; j++) {
                p *= grid[i][j];
            }
            if (p != k) {
                valid = false;
            }
        }
        for (int j = 0; j < m; j++) {
            int p = 1;
            for (int i = 0; i < n; i++) {
                p *= grid[i][j];
            }
            if (p != k) {
                valid = false;
            }
        }
        if (valid) {
            ans++;
            print(mask, n, m);
        }
    }
    std::cout << "Ans = " << ans << "\n";
}

int main() {
    int64 n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            simulate(i, j, k);
        }
    }
    return EXIT_SUCCESS;
}
