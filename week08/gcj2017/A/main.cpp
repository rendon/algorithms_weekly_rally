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

string f(string S, int K) {
    int N = S.length();
    int ans = 0;
    for (int i = 0; i + K <= N; i++) {
        if (S[i] == '-') {
            for (int j = 0; j < K; j++) {
                S[i+j] = (S[i+j] == '+') ? '-' : '+';
            }
            ans++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (S[i] != '+') {
            return "IMPOSSIBLE";
        }
    }
    char buf[12];
    sprintf(buf, "%d", ans);
    return string(buf);
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
