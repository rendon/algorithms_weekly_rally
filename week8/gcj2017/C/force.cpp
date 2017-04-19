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
    int l, r, idx;
    
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
};

string f(int N, int K) {
    vector<bool> occupied(N, false);
    vector<Stall> stalls(N);
    for (int i = 0; i < N; i++) {
        stalls[i].idx = i;
    }
    Stall last;
    for (int user = 1; user <= K; user++) {
        int l = 0;
        for (int i = 0; i < N; i++) {
            if (occupied[i]) {
                l = 0;
            } else {
                stalls[i].l = l++;
            }
        }
        int r = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (occupied[i]) {
                r = 0;
            } else {
                stalls[i].r = r++;
            }
        }
        int pos = -1;
        for (int i = 0; i < N; i++) {
            if (!occupied[i]) {
                if (pos == -1) {
                    pos = i;
                } else if (stalls[i] < stalls[pos]) {
                    pos = i;
                }
            }
        }
        last = stalls[pos];
        cout << last.idx + 1 << endl;
        occupied[pos] = true;
    }
    char buf[64];
    sprintf(buf, "%d %d", last.max(), last.min());
    return string(buf);
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N >> K;
        cout << "Case #" << tc << ": " << f(N, K) << endl;
    }
    return EXIT_SUCCESS;
}
