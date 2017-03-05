/* Copyright 2016 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// Problem: Words (http://coj.uci.cu/24h/problem.xhtml?pid=1167)
// region Template
#include <bits/stdc++.h>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

struct PriorityNode {
    int cost;
    int node;
    bool operator<(const PriorityNode& that) const {
        return this->cost < that.cost;
    }
};

inline bool connected(const string& u, const string& v) {
    return u[u.length()-1] == v[0];
}

int dijkstra(vector<string>& words, int root) {
    int M = words.size();
    vector<int> dist(M, -kInf);
    dist[root] = words[root].length();
    vector<bool> locked(M, false);
    priority_queue<PriorityNode> Q;
    Q.push({dist[root], root});
    while (!Q.empty()) {
        auto top = Q.top();
        Q.pop();
        if (locked[top.node]) {
            continue;
        }
        locked[top.node] = true;
        int u = top.node;
        for (int v = 0; v < M; v++) {
            if (v == u) {
                continue;
            }
            if (!connected(words[u], words[v])) {
                continue;
            }
            if (top.cost + int(words[v].length()) > dist[v]) {
                dist[v] = top.cost + words[v].length();
                Q.push({dist[v], v});
            }
        }
    }
    int maxLength = 0;
    for (int d : dist) {
        if (d != -kInf) {
            maxLength = std::max(maxLength, d);
        }
    }
    return maxLength;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;
        vector<string> words(M);
        for (string& word : words) {
            cin >> word;
        }
        
        int maxPathLength = 0;
        for (int u = 0; u < M; u++) {
            maxPathLength = std::max(maxPathLength, dijkstra(words, u));
        }
        cout << maxPathLength << endl;
    }
    return EXIT_SUCCESS;
}

