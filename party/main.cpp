/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Templat
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <numeric>
#include <limits>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const int kUnprocessed = numeric_limits<int>::max();
// endregion


bool isBipartite(vector<vector<int>>& graph, vector<int>& colors, int node) {
    queue<int> Q;
    Q.push(node);
    colors[node] = 0;
    vector<int> nodes;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        nodes.push_back(u);
        for (int v : graph[u]) {
            if (colors[v] == kUnprocessed) {
                Q.push(v);
                colors[v] = 1 - colors[u];
            }
        }
    }
    for (int u : nodes) {
        for (int v : graph[u]) {
            if (colors[u] == colors[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> colors(N, kUnprocessed);
    vector<vector<int>> graph(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    bool possible = true;
    for (int node = 0; node < N; node++) {
        if (colors[node] == kUnprocessed) {
            possible &= isBipartite(graph, colors, node);
        }
    }
    printf("%s\n", possible ? "YES" : "NO");
    return EXIT_SUCCESS;
}
