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
// const double kEps   = 10e-8;
// const int kMax      = 1000;
// const int kInf      = 1 << 30;
// endregion
struct Time {
    int minute;
    int index;
    bool operator>(const Time& that) const {
        if (minute != that.minute) {
            return minute > that.minute;
        }
        return index > that.index;
    }
};

int findBarber(vector<int>& barbers, int B, int N) {
    priority_queue<Time, vector<Time>, greater<Time>> Q;
    for (int i = 0; i < B; i++) {
        Q.push({0, i});
    }
    int index = 0;
    while (N--) {
        Time top = Q.top();
        Q.pop();
        index = top.index;
        cout << ">> " << index << "\n";
        Q.push({top.minute + barbers[index], index});
    }
    return index + 1;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int B, N;
        cin >> B >> N;
        vector<int> barbers(B);
        for (int& b : barbers) {
            cin >> b;
        }
        cout << "Case #" << tc << ": " << findBarber(barbers, B, N) << "\n";
    }
    return EXIT_SUCCESS;
}
