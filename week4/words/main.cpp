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
const int kMax      = (1 << 16) + 1;
const int kUndefined = -1;
// endregion

struct Node {
    int first, last, length;
};

int dp[kMax][5];
map<char, int> eq{{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};

int f(int active, int prevLast, const vector<Node>& nodes) {
    // Base case: no nodes available
    if (active == 0) {
        return 0;
    }
    int& ans = dp[active][prevLast];
    if (ans != kUndefined) {
        return ans;
    }

    ans = 0;
    int mask = (1 << nodes.size()) - 1;
    for (int i = 0; i < int(nodes.size()); i++) {
        int length = nodes[i].length;
        if (nodes[i].first == prevLast && (active & (1 << i))) {
            int newActive = active & (mask ^ (1 << i));
            ans = std::max(ans, f(newActive, nodes[i].last, nodes) + length);
        }
    }
    return ans;
}

int maximalComplexity(const vector<Node>& nodes) {
    memset(dp, kUndefined, sizeof dp);
    int M = nodes.size();
    int best = 0;
    for (int prevLast = 0; prevLast < 5; prevLast++) {
        best = std::max(best, f((1 << M) - 1, prevLast, nodes));
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;
        vector<Node> nodes(M);
        for (int i = 0; i < M; i++) {
            string word;
            cin >> word;
            int length = word.length();
            nodes[i] = {eq[word[0]], eq[word[length-1]], length};
        }
        cout << maximalComplexity(nodes) << endl;
    }
    return EXIT_SUCCESS;
}
