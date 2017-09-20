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
const int kMax      = 100005;
const int kInf      = 1 << 30;
// endregion

int T[kMax];
int C[kMax];

void update(int idx, int v) {
    while (idx < kMax) {
        T[idx] += v;
        idx += idx & -idx;
    }
}

int read(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += T[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int f(vector<vector<int>>& tree, int u, int i, int prev, const int m) {
    update(i, C[u]);
    if (i >= m && (read(i) - read(i - m)) == m) {
        if (C[u] == 1) {
            update(i, -C[u]);
        }
        return 0;
    }
    
    int ans = 0;
    int children = 0;
    for (int v : tree[u]) {
        if (v != prev) {
            ans += f(tree, v, i + 1, u, m);
            children++;
        }
    }
    update(i, -C[u]);
    if (children == 0) {
        return 1;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> C[i];
    }
    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    std::cout << f(tree, 1, 1, -1, m + 1) << std::endl;
    return EXIT_SUCCESS;
}
