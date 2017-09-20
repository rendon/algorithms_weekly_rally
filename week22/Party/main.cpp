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

int dfs(vector<vector<int>>& tree, int u) {
    int depth = 0;
    for (int v : tree[u]) {
        depth = std::max(depth, dfs(tree, v));
    }
    return depth + 1;
}

int main() {
    int n;
    std::cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; i++) {
        int p;
        std::cin >> p;
        if (p != -1) {
            tree[p-1].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, dfs(tree, i));
    }
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
