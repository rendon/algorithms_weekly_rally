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
using std::priority_queue;

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int64 kInf      = 1LL << 60;
// endregion

struct Edge {
    int node;
    int64 cost;
};

struct Node {
    int node;
    int64 cost;

    bool operator<(const Node& that) const {
        return cost < that.cost;
    }

    bool operator>(const Node& that) const {
        return cost > that.cost;
    }
};

int64 findShortesPath(vector<vector<Edge>>& graph, vector<map<int, int>>& delays) {
    priority_queue<Node, vector<Node>, std::greater<Node>> Q;
    int n = graph.size();
    vector<int64> cost(n, kInf);
    cost[0] = 0;
    Q.push({0, 0});
    while (!Q.empty()) {
        Node top = Q.top();
        Q.pop();
        int u = top.node;
        // if (cost[u] < top.cost) {
        //     continue;
        // }
        int t = top.cost;
        int d = delays[u][t];
        for (Edge e : graph[u]) {
            int v = e.node;
            if(t + d + e.cost < cost[v]) {
                cost[v] = t + d + e.cost;
                Q.push({v, cost[v]});
            }
        }
    }
    if (cost[n-1] == kInf) {
        return -1LL;
    }
    return cost[n-1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<vector<int>> arrivals(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int t;
            std::cin >> t;
            arrivals[i].push_back(t);
        }
    }
    vector<map<int, int>> delays(n);
    for (int i = 0; i < n; i++) {
        vector<int>& arrival = arrivals[i];
        map<int, int>& delay = delays[i];
        int size = arrival.size();
        int count = 1;
        for (int j = size - 1; j >= 0; j--) {
            delay[arrival[j]] = count;
            if (j > 0 && (arrival[j-1] + 1 == arrival[j])) {
                count++;
            } else {
                count = 1;
            }
        }
    }
    std::cout << findShortesPath(graph, delays) << std::endl;
    return EXIT_SUCCESS;
}
