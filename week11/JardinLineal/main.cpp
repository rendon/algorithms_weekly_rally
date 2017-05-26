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
const int kInf      = 1 << 30;
const int64 kUndef = -1;
// endregion

const int kMax = 600005;

int dp[2][128];

void solve(const int n, const int m, vector<int>& states, string& garden) {
    for (int state = 0; state < 128; state++) {
        if ((state & 1) || (state & (1 << 6))) {
            dp[n%2][state] = 0;
        } else {
            dp[n%2][state] = 1;
        }
    }
    int pos = 1;
    for (int p = n - 1; p >= 0; p--) {
        for (int state = 0; state < 128; state++) {
            if ((state & 1) || (state & (1 << 6))) {
                dp[p%2][state] = 0;
                continue;
            }
            if (states[p] == state) {
                if (garden[p] == 'P') {
                    pos = (pos + dp[(p+1)%2][(state>>1)|(1<<2)]) % m;
                }
            }
            int& ans = dp[p%2][state];
            ans = 0;
            // Try with a 0
            if (!(state & (1 << 1))) {
                int ns = (state>>1)|(1<<2);
                ans += dp[(p+1)%2][ns];
            }

            // Try with a 1
            if (!(state & (1 << 5))) {
                int ns = (state<<1)|(1<<4);
                ans += dp[(p+1)%2][ns];
            }
            ans %= m;
        }
    }
    cout << pos << endl;
}

vector<int> findPosition(const int n, string& garden, const int m) {
    int state = 0;
    vector<int> states(n);
    for (int p = 0; p < n; p++) {
        states[p] = state;
        if (garden[p] == 'L') {
            state = (state >> 1) | (1 << 2);
        } else {
            state = (state << 1) | (1 << 4);
        }
    }
    return states;
}

int main() {
    int N, M;
    string garden;
    cin >> N >> M;
    cin >> garden;
    vector<int> states = findPosition(N, garden, M);
    solve(N, M, states, garden);
    return EXIT_SUCCESS;
}
