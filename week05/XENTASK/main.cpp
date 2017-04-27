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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> X(N);
        for (int& x : X) {
            cin >> x;
        }
        vector<int> Y(N);
        for (int& y : Y) {
            cin >> y;
        }
        int costxy = 0;
        int costyx = 0;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                costxy += X[i];
                costyx += Y[i];
            } else {
                costxy += Y[i];
                costyx += X[i];
            }
        }
        cout << std::min(costxy, costyx) << "\n";
    }
    return EXIT_SUCCESS;
}
