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

int f(vector<int>& M) {
    int n = M.size();
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (M[i] < M[i-1]) {
            count += M[i-1] - M[i];
        }
    }
    return count;
}

int g(vector<int>& M) {
    int n = M.size();
    double rate = 0;
    for (int i = 1; i < n; i++) {
        if (M[i] < M[i-1]) {
            rate = std::max(rate, (M[i-1] - M[i]) / 10.0);
        }
    }
    int count = 0;
    for (int i = 0; i + 1 < n; i++) {
        count += std::min(double(M[i]), 10 * rate);
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<int> M(N);
        for (int& m : M) {
            cin >> m;
        }
        cout << "Case #" << tc << ": ";
        cout << f(M) << " " << g(M) << "\n";
    }
    return EXIT_SUCCESS;
}
