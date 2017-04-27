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
// endregion

int find(vector<int>& A) {
    int n = A.size();
    if (A[1] - A[0] > 1) {
        return A[0];
    }
    if (A[n-1] - A[n-2] > 1) {
        return A[n-1];
    }
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i-1]) {
            return A[i];
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int& a : A) {
            cin >> a;
        }
        std::sort(A.begin(), A.end());
        cout << find(A) << "\n";
    }
    return EXIT_SUCCESS;
}
