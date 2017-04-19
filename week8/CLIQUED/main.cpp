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
const int kInf      = 1 << 30;
const int kCity     = 0;
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K, X, M, S;
        cin >> N >> K >> X >> M >> S;
        vector<vector<pair<int, int>>> graph(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (u <= K) {
                u = kCity;
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            } else if (v <= K) {
                v = kCity;
                graph[v].push_back({u, w});
                graph[u].push_back({v, w});
            } else {
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
        }
    }
    return EXIT_SUCCESS;
}
