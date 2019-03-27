/* Copyright 2018 Rafael Rendon Pablo <rafaelrendonpablo@gmail.com> */
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

using std::string;
using std::vector;
using std::map;
using std::set;
using std::queue;

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = INT32_MAX;

inline void __enable_fast_input() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

inline int readInt() {
    int x = 0;
    std::cin >> x;
    return x;
}

inline int64 readLong() {
    int64 x = 0;
    std::cin >> x;
    return x;
}

inline string readString() {
    string str;
    std::cin >> str;
    return str;
}
// endregion

int main() {
    string x = readString();
    string y = readString();
    string z(x.length(), '.');
    bool valid = true;
    for (int i = 0; i < int(x.length()); i++) {
        if (x[i] == y[i]) {
            z[i] = x[i];
        } else {
            if (y[i] > x[i]) {
                valid = false;
            }
            z[i] = y[i];
        }
    }
    if (!valid) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << z << std::endl;
    }
    return EXIT_SUCCESS;
}
