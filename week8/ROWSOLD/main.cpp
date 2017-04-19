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

int64 solve(string& S) {
    S += "1";
    int n = S.length();
    int64 x = 0;
    int prev = -1;
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == '1') {
            if (prev == -1) {
                prev = i;
                x = 1;
            } else {
                int64 dist = i - prev - 1;
                if (dist > 0) {
                    ans += dist * x + x;
                }
                x++;
                prev = i;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << solve(S) << "\n";
    }
    return EXIT_SUCCESS;
}
