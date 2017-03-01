/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// const double kEps   = 10e-8;
// const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

struct Node {
    int cost;
    int node;
    bool operator>(const Node& that) const {
        return this->cost > that.cost;
    }
};

class GridSequence {
public:
    GridSequence(const vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        graphSize = N * M + 2;
        this->grid = grid;
    }

    int findMinimalSequenceCost() {
        setupNodesCosts(grid);
        graph = vector<vector<int>>(graphSize, vector<int>());
        connectSourceToGraph();
        connectTargetToGraph();
        connectMainGraph();
        return dijkstra(0, graphSize - 1);
    }
private:
    int N, M;
    int graphSize;
    vector<vector<int>> grid;
    vector<int> costs;
    vector<vector<int>> graph;

    void setupNodesCosts(vector<vector<int>>& grid) {
        costs = vector<int>(N * M + 2);
        costs[0] = 0;
        int u = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                costs[u++] = grid[i][j];
            }
        }
        costs[u] = 0;
    }

    //     __ x x ...
    //   /
    // s ---- x x ...
    //   \ __ x x ...
    void connectSourceToGraph() {
        int u = 1;
        for (int i = 1; i <= N; i++) {
            graph[0].push_back(u);
            graph[u].push_back(0);
            u += M;
        }
    }

    // ... x x _
    //           \
    // ... x x  -- t
    // ... x x _ /
    void connectTargetToGraph() {
        int u = M;
        for (int i = 1; i <= N; i++) {
            graph[u].push_back(graphSize - 1);
            graph[graphSize-1].push_back(u);
            u += M;
        }
    }

    // . . a . .
    // . . | . .
    // d - x - b
    // . . | . .
    // . . c . .
    void connectMainGraph() {
        int u = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (j + 1 <= M) {
                    int v = u + 1;
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
                if (i + 1 <= N) {
                    int v = u + M;
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
                u++;
            }
        }
    }

    int dijkstra(int s, int t) {
        vector<int> dist(graph.size(), kInf);
        dist[s] = 0;
        priority_queue<Node, vector<Node>, std::greater<Node>> Q;
        Q.push({0, s});
        while (!Q.empty()) {
            Node top = Q.top();
            Q.pop();
            if (top.cost > dist[top.node]) {
                continue;
            }
            for (int v : graph[top.node]) {
                if (top.cost + costs[v] < dist[v]) {
                    dist[v] = top.cost + costs[v];
                    Q.push({dist[v], v});
                }
            }
        }
        return dist[t];
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (auto& row : grid) {
        for (auto& cell : row) {
            cin >> cell;
        }
    }
    GridSequence gridSequence(grid);
    cout << gridSequence.findMinimalSequenceCost() << endl;
    return EXIT_SUCCESS;
}
