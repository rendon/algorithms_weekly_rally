/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <cmath>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// const double kEps   = 10e-8;
// const int kMax      = 1000;
// const int kInf      = 1 << 30;
// endregion

bool dfs(map<int, vector<int>>& graph, int u, int p, vector<bool>& visited) {
    if (graph.empty()) {
        return true;
    }
    visited[u] = true;
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }
        if (visited[v]) {
            return false;
        }
        if (!dfs(graph, v, u, visited)) {
            return false;
        }
    }
    return true;
}

string solve(map<int, vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n + 1, false);
    bool is = dfs(graph, 1, 0, visited);
    for (int u = 1; u <= n; u++) {
        is &= visited[u];
    }
    if (is) {
        return "a tree";
    } else {
        return "not a tree";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> ids;
    map<int, vector<int>> graph;
    int u, v;
    int nextId = 1;
    int k = 1;
    while (cin >> u >> v) {
        if (u == -1 && v == -1) {
            break;
        } else if (u == 0 && v == 0) {
            cout << "Case " << k << " is " << solve(graph) << ".\n";
            ids.clear();
            graph.clear();
            nextId = 1;
            k++;
            continue;
        }
        if (ids.count(u) == 0) {
            ids[u] = nextId++;
        }
        if (ids.count(v) == 0) {
            ids[v] = nextId++;
        }
        graph[ids[u]].push_back(ids[v]);
        graph[ids[v]].push_back(ids[u]);
    }
    return EXIT_SUCCESS;
}
