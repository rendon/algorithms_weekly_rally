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

string solve() {
    int N, K;
    cin >> N >> K;
    vector<bool> found(K, false);
    vector<set<int>> locations(K);
    vector<vector<int>> islands(N);
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        while (P--) {
            int x;
            cin >> x;
            x--;
            found[x] = true;
            locations[x].insert(i);
            islands[i].push_back(x);
        }
    }
    for (bool f : found) {
        if (!f) {
            return "sad";
        }
    }
    for (vector<int>& island : islands) {
        bool skippable = true;
        for (int x : island) {
            if (locations[x].size() < 2) {
                skippable = false;
                break;
            }
        }
        if (skippable) {
            return "some";
        }
    }
    return "all";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
    return EXIT_SUCCESS;
}
