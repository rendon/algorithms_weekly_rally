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
const int kMax = 15000;
// endregion

int find(vector<pair<int, int>>& T, int n) {
    int l = 0;
    int h = T.size();
    while (l < h) {
        int m = l + (h - l) / 2;
        if (n >= T[m].second) {
            l = m + 1;
        } else {
            h = m;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> T(kMax);
    T[0] = {0, 0};
    for (int i = 1; i < kMax; i++) {
        T[i].first = i;
        T[i].second = T[i-1].second + i;
    }
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        int i = find(T, n);
        cout << (T[i].second - n) << " " << T[i].first << "\n";
    }
    return EXIT_SUCCESS;
}
