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
#include <numeric>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int64 g(int64 n, int64 x, int f, int s) {
    if (f == 0 && s == 0) {
        if (x >= n) {
            return x;
        }
        return -1;
    }
    if (f > 0) {
        int64 t = g(n, x * 10 + 4, f - 1, s);
        if (t != -1) {
            return t;
        }
    }
    if (s > 0) {
        int64 t = g(n, x * 10 + 7, f, s - 1);
        if (t != -1) {
            return t;
        }
    }
    return -1;
}

int64 f(int64 n, int l) {
    return g(n, 0LL, l, l);
}

int main() {
    int64 n;
    cin >> n;
    int d = log10(n) + 1;
    for (int l = d; ; l++) {
        if (l % 2 == 1) {
            continue;
        }
        int64 x = f(n, l / 2);
        if (x != -1) {
            cout << x << endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}
