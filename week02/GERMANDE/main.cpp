/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <bits/stdc++.h>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int s, d;
        cin >> s >> d;
        int n = s * d;
        vector<int> votes(n);
        for (int& v : votes) {
            cin >> v;
        }
        int sum = 0;
        int f;
        for (f = 0; f + 1 < d; f++) {
            sum += votes[f];
        }
        int districtGoal = (d + 1) / 2;
        vector<int> buckets(d, 0);
        for (int b = 0; b < n; b++) {
            sum += votes[f];
            buckets[b%d] += (sum >= districtGoal) ? 1 : 0;
            sum -= votes[b];
            f = (f + 1) % n;
        }
        int stateGoal = (s + 1) / 2;
        bool possible = false;
        for (int bucket : buckets) {
            if (bucket >= stateGoal) {
                possible = true;
            }
        }
        if (possible) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return EXIT_SUCCESS;
}

