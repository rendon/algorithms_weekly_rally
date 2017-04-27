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

string f(int N, int K) {
    priority_queue<Stall, vector<Stall>, greater<Stall>> Q;
    Q.push(createStall(1, N));
    Stall last;
    int count = 0;
    int power = 2;
    while (K--) {
        Stall top = Q.top();
        Q.pop();
        last = top;
        if (top.idx - top.a > 0) {
            Q.push(createStall(top.a, top.idx - 1));
        }
        if (top.b - top.idx > 0) {
            Q.push(createStall(top.idx + 1, top.b));
        }
        cout << "I: " << last.idx << " Max: " << last.max() << " Min: " << last.min() << endl;
        count++;
        if (count + 1 == power) {
            power *= 2;
            cout << "================================================================================" << endl;
        }
    }
    char buf[64];
    sprintf(buf, "%d %d", last.max(), last.min());
    return string(buf);
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
