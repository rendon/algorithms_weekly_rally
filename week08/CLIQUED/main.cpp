/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
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
const int kMax      = 1000;
const int64 kInf      = 1LL << 60;
const int kCity     = 0;
// endregion

typedef vector<vector<pair<int, int64>>> Graph;

struct PQNode {
    int id;
    int64 weight;
    bool operator>(const PQNode& that) const {
        return this->weight > that.weight;
    }
};

class Clique {
public:
    Clique() {}
    Clique(int N, int K, int X, int S, Graph& graph) {
        this->N = N;
        this->K = K;
        this->X = X;
        this->S = S;
        this->graph = graph;
    }

    void solve() {
        priority_queue<PQNode, vector<PQNode>, greater<PQNode>> Q;
        vector<int64> dist(N + 1, kInf);
        dist[S] = 0;
        Q.push({S, 0});
        bool pushed = false;
        if (S <= K) {
            for (int u = 1; u <= K; u++) {
                if (u == S) {
                    continue;
                }
                Q.push({u, int64(X)});
                dist[u] = int64(X);
            }
            pushed = true;
        }
        while (!Q.empty()) {
            PQNode top = Q.top();
            Q.pop();
            if (top.weight > dist[top.id]) {
                continue;
            }
            for (auto e : graph[top.id]) {
                int v = e.first;
                int64 w = e.second;
                if (top.weight + w < dist[v]) {
                    dist[v] = top.weight + w;
                    Q.push({v, dist[v]});
                }
            }

            if (top.id <= K && !pushed) {
                for (int v = 1; v <= K; v++) {
                    if (v == top.id) {
                        continue;
                    }
                    if (top.weight + X < dist[v]) {
                        dist[v] = top.weight + X;
                        Q.push({v, top.weight + X});
                    }
                }
                pushed = true;
            }
        }
        for (int i = 1; i <= N; i++) {
            cout << dist[i] << " ";
        }
        cout << "\n";
    }
private:
    Graph graph;
    int N, K, X, S;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K, X, M, S;
        cin >> N >> K >> X >> M >> S;
        Graph graph(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        Clique clique(N, K, X, S, graph);
        clique.solve();
    }
    return EXIT_SUCCESS;
}
