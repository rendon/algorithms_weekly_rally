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
const int kInf      = 1 << 30;
// endregion

int allEven(vector<int>& E, int n) {
    int best = kInf;
    for (int v = 0; v <= 1; v++) {
        int steps = 0;
        vector<int> A = E;
        A[0] = v;
        for (int i = 0; i < n; i++) {
            if (A[i] == 1) {
                steps++;
                A[i] = 1 - A[i];
                A[i+1] = 1 - A[i+1];
                A[i+2] = 1 - A[i+2];
            }
        }
        if (A[n] == 0) {
            best = std::min(best, steps);
        }
    }
    return (best == kInf) ? -1 : best;
}

int allOdd(vector<int>& O, int n) {
    int best = kInf;
    for (int v = 0; v <= 1; v++) {
        int steps = 0;
        vector<int> A = O;
        A[0] = v;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                steps++;
                A[i] = 1 - A[i];
                A[i+1] = 1 - A[i+1];
                A[i+2] = 1 - A[i+2];
            }
        }
        if (A[n] == 1) {
            best = std::min(best, steps);
        }
    }
    return (best == kInf) ? -1 : best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> E(n + 3);
    vector<int> O(n + 3);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        E[i] = x % 2;
        O[i] = x % 2;
    }
    cout << allOdd(O, n) << endl;
    cout << allEven(E, n) << endl;
    return EXIT_SUCCESS;
}
