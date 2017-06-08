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
const int kMax      = 1000;
const int kInf      = 1 << 30;
const int kBob = 0;
const int kAlice = 1;
// endregion

struct State {
    int node, time, type;
};

int solve(vector<vector<int>> graph, int n, int a, int b) {
    queue<State> Q;
    Q.push({b, 1, kBob});
    Q.push({a, 0, kAlice});
    vector<bool> visitedByAlice(n + 1);
    vector<bool> visitedByBob(n + 1);
    visitedByAlice[a] = true;
    visitedByBob[b] = true;
    int ans = 0;
    while (!Q.empty()) {
        State front = Q.front();
        Q.pop();
        int u = front.node;
        if (front.type == kBob) {
            if (visitedByAlice[u]) {
                continue;
            }
            for (int v : graph[u]) {
                if (!visitedByAlice[v] && !visitedByBob[v]) {
                    visitedByBob[v] = true;
                    Q.push({v, front.time + 2, kBob});
                }
            }
        } else {
            if (visitedByBob[u]) {
                ans = std::max(ans, front.time);
            }
            for (int v : graph[u]) {
                if (!visitedByAlice[v]) {
                    visitedByAlice[v] = true;
                    Q.push({v, front.time + 2, kAlice});
                }
            }
        }
        
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << solve(graph, n, 1, x) << endl;
    return EXIT_SUCCESS;
}
