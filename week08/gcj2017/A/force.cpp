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
// endregion

bool seen[1<<22];

string f(string S, int K) {
    int mask = 0;
    int N = S.length();
    for (int i = 0; i < N; i++) {
        if (S[i] == '+') {
            mask |= (1 << i);
        }
    }
    memset(seen, false, sizeof seen);
    queue<int> Q;
    queue<int> D;
    Q.push(mask);
    D.push(0);
    int goal = (1 << N) - 1;
    int x = (1 << K) - 1;
    while (!Q.empty()) {
        int state = Q.front();
        Q.pop();
        int dist = D.front();
        D.pop();
        if (state == goal) {
            char buf[12];
            sprintf(buf, "%d", dist);
            return string(buf);
        }
        for (int i = 0; i + K <= N; i++) {
            int ns = state ^ (x << i);
            if (seen[ns]) {
                continue;
            }
            seen[ns] = true;
            Q.push(ns);
            D.push(dist + 1);
        }
    }
    return "IMPOSSIBLE";
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string S;
        int K;
        cin >> S >> K;
        cout << "Case #" << tc << ": " << f(S, K) << endl;

    }
    return EXIT_SUCCESS;
}
