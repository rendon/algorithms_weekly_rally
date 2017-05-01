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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n + 2);
    vector<int> L(n + 2);
    vector<int> R(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    L[0] = kInf;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) {
            L[i] = 0;
        } else {
            L[i] = L[i-1] + 1;
        }
    }
    R[n+1] = kInf;
    for (int i = n; i >= 1; i--) {
        if (A[i] == 0) {
            R[i] = 0;
        } else {
            R[i] = R[i+1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << std::min(L[i], R[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
