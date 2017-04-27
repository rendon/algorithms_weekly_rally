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
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int cost = 0;
        int x;
        while (N > 0) {
            cin >> x;
            N--;
            if (x == 0) {
                cost += 1000 + 100;
                break;
            }
        }
        while (N > 0) {
            cin >> x;
            N--;
            cost += 100;
            if (x == 0) {
                cost += 1000;
            }
        }
        cout << cost << endl;
    }
    return EXIT_SUCCESS;
}
