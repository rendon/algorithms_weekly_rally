/* Copyright 2018 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
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

struct Stall {
    int l, r, idx, a, b;
    
    Stall() {
        l = 0;
        r = 0;
        idx = 0;
    }

    Stall(int l, int r, int idx) {
        this->l = l;
        this->r = r;
        this->idx = idx;
    }

    int min() const {
        return std::min(l, r);
    }

    int max() const {
        return std::max(l, r);
    }

    bool operator<(const Stall& that) const {
        if (this->min() == that.min()) {
            if (this->max() == that.max()) {
                return this->idx < that.idx;
            } else {
                return this->max() > that.max();
            }
        } else {
            return this->min() > that.min();
        }
    }

    bool operator>(const Stall& that) const {
        return !(*this < that);
    }
};

Stall createStall(int a, int b) {
    int s = (a + b) / 2;
    int e = (a + b + 1) / 2;
    vector<Stall> v;
    for (int i = s; i <= e; i++) {
        v.push_back(Stall(i - a, b - i, i));
    }
    std::sort(v.begin(), v.end());
    v[0].a = a;
    v[0].b = b;
    return v[0];
}

void g(int64 a, int64 b, int64 w, int64 K) {
    if (w == 0) {
        cout << "A = " << a << " B = " << b << endl;
        return;
    }
    Stall stall = createStall(a, b);
    if (K > w / 2) {
        g(stall.idx + 1, b, w / 2, K - w / 2);
    } else {
        g(a, stall.idx - 1, w / 2, K);
    }
}

int64 f(int64 N, int64 K) {
    int64 p = 1;
    int64 w = 1;
    while (p + p - 1 < K) {
        p += p;
        w = p;
    }
    K -= p - 1;
    g(1, N, w, K);
    // cout << "W: " << w << endl;
    // cout << "P: " << p << endl;
    // cout << "K: " << K << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N >> K;
        cout << "Case #" << tc << ": " << f(N, K) << "\n";
    }
    return EXIT_SUCCESS;
}
