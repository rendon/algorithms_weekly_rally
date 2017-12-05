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
const int kMax      = 100000;
const int kInf      = 1 << 30;
// endregion

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    vector<string> grid(n);
    for (string& row : grid) {
        std::cin >> row;
    }
    vector<std::pair<int, int>> centers(kMax);
    bool found = false;
    for (int x = 1; x < std::max(n, m) && !found; x++) {
        int size = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - x < 0 || i + x >= n || j - x < 0 || j + x >= m) {
                    continue;
                }
                if (grid[i][j] != '*') {
                    continue;
                }
                if (grid[i-x][j] != '*' || grid[i+x][j] != '*') {
                    continue;
                }
                if (grid[i][j-x] != '*' || grid[i][j+x] != '*') {
                    continue;
                }
                centers[size].first = i;
                centers[size].second = j;
                size++;
            }
        }
        if (k <= size) {
            int r = centers[k-1].first;
            int c = centers[k-1].second;
            std::cout << r + 1 << " " << c + 1 << std::endl;
            std::cout << (r - x + 1) << " " << (c + 1) << std::endl;
            std::cout << (r + x + 1) << " " << (c + 1) << std::endl;
            std::cout << (r + 1) << " " << (c - x + 1) << std::endl;
            std::cout << (r + 1) << " " << (c + x + 1) << std::endl;
            found = true;
        } else {
            k -= size;
        }
    }
    if (!found) {
        std::cout << -1 << std::endl;
    }
    return EXIT_SUCCESS;
}
