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
const int kInf = 1 << 30;
// endregion

struct Edge {
    int node, weight;
};

struct PQNode {
    int weight, node, state;
    bool operator>(const PQNode& that) const {
        return weight > that.weight;
    }
};

class SyncShopping {
public:
    int findMinimumTime() {
        vector<vector<int>> dist(N + 1, vector<int>(1 << K, kInf));
        dist[1][centers[1]] = 0;
        vector<vector<bool>> seen(N + 1, vector<bool>(1 << K, false));
        priority_queue<PQNode, vector<PQNode>, greater<PQNode>> Q;
        Q.push({0, 1, centers[1]});
        vector<pair<int, int>> results;
        while (!Q.empty()) {
            PQNode top = Q.top();
            int u = top.node;
            int w = top.weight;
            int s = top.state;
            Q.pop();
            seen[u][s] = true;
            if (u == N) {
                results.push_back({s, w});
            }

            for (Edge e : graph[top.node]) {
                int v = e.node;
                int ns = s | centers[v];
                if (!seen[v][ns]) {
                    if (w + e.weight < dist[v][ns]) {
                        dist[v][ns] = w + e.weight;
                        Q.push({dist[v][ns], v, ns});
                    }
                }
            }
        }
        int goal = (1 << K) - 1;
        int ans = kInf;
        int size = results.size();
        for (int i = 0; i < size; i++) {
            int us = results[i].first;
            int uw = results[i].second;
            if (us == goal) {
                ans = std::min(ans, uw);
            }
            for (int j = i + 1; j < size; j++) {
                int vs = results[j].first;
                int vw = results[j].second;
                if ((us | vs) == goal) {
                    ans = std::min(ans, std::max(uw, vw));
                }
            }
        }
        return ans;
    }

    int solve() {
        cin >> N >> M >> K;
        centers.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            int elements;
            cin >> elements;
            int mask = 0;
            for (int j = 0; j < elements; j++) {
                int t;
                cin >> t;
                mask |= (1 << (t - 1));
            }
            centers[i] = mask;
        }
        graph.resize(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        return findMinimumTime();
    }
private:
    int N, M, K;
    vector<vector<Edge>> graph;
    vector<int> centers;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SyncShopping syncShopping;
    cout << syncShopping.solve() << endl;
    return EXIT_SUCCESS;
}
