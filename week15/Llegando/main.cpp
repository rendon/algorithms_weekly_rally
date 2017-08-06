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
#include <algorithm>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 5005;
const int kInf      = 1 << 30;
// endregion

struct State {
    int node, turn, dist;
};

int paths[kMax][2];

void compute(vector<vector<int>>& graph, int root) {
    memset(paths, -1, sizeof paths);
    queue<State> Q;
    Q.push({root, 0, 0});
    while (!Q.empty()) {
        int u = Q.front().node;
        int t = Q.front().turn;
        int d = Q.front().dist;
        Q.pop();
        for (int v : graph[u]) {
            if (paths[v][1-t] == -1) {
                paths[v][1-t] = d + 1;
                Q.push({v, 1 - t, d + 1});
            }
        }
    }
}

int solve(int d, int k) {
    int evenDist = paths[d][0];
    int oddDist = paths[d][1];
    if (evenDist != -1 && evenDist <= k) {
        if ((k - evenDist) % 2 == 0) {
            return 1;
        }
    }

    if (oddDist != -1 && oddDist <= k) {
        if ((k - oddDist) % 2 == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    compute(graph, 1);
    int P;
    cin >> P;
    for (int i = 0; i < P; i++) {
        int d, k;
        cin >> d >> k;
        cout << solve(d, k) << "\n";
    }
    return EXIT_SUCCESS;
}
