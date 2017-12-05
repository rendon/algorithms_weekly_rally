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
const int kMax  = 1005;
const int kNo = 0;
const int kYes = 1;
// endregion

struct PathNode {
    int p, v;
    char c;
};
map<int, int> dp[kMax];
map<int, PathNode> path[kMax];

class Poker {
public:
    Poker() { }
    Poker(string sequence, int n, int k) : sequence(sequence), n(n), k(k) {
    }

    int f(int p, int v) {
        if (p == n) {
            if (std::abs(v) == k) {
                return kYes;
            }
            return kNo;
        }

        if (std::abs(v) >= k) {
            return kNo;
        }

        if (dp[p].count(v) == 1) {
            return dp[p][v];
        }
        if (sequence[p] != '?') {
            int q = 0;
            if (sequence[p] == 'W') {
                q++;
            } else if (sequence[p] == 'L') {
                q--;
            }
            path[p][v] = {p + 1, v + q, sequence[p]};
            return dp[p][v] = f(p + 1, v + q);
        } else {
            // Draw
            if (f(p + 1, v) == kYes) {
                path[p][v] = {p + 1, v, 'D'};
                return dp[p][v] = kYes;
            }
            // Win
            if (f(p + 1, v + 1) == kYes) {
                path[p][v] = {p + 1, v + 1, 'W'};
                return dp[p][v] = kYes;
            }

            // Lost
            if (f(p + 1, v - 1) == kYes) {
                path[p][v] = {p + 1, v - 1, 'L'};
                return dp[p][v] = kYes;
            }
        }
        return dp[p][v] = kNo;
    }

    void solve() {
        if (f(0, 0) == kYes) {
            int p = 0, v = 0;
            while (p < n) {
                cout << path[p][v].c;
                int np = path[p][v].p;
                int nv = path[p][v].v;
                p = np;
                v = nv;
            }
        } else {
            cout << "NO\n";
        }
    }


private:
    string sequence;
    int n, k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string sequence;
    cin >> sequence;
    Poker poker(sequence, n, k);
    poker.solve();
    return EXIT_SUCCESS;
}
