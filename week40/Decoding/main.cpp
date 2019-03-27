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
    int n = readInt();
    string E = readString();
    string D(E.length(), '.');
    int idx = 0;
    int left = n / 2 - 1;
    int right = n / 2;
    if (n % 2 == 1) {
        D[n/2] = E[idx++];
        left = n / 2 - 1;
        right = n / 2 + 1;
    }
    while (idx < n) {
        D[left--] = E[idx++];
        D[right++] = E[idx++];
    }
    std::cout << D << std::endl;
    return EXIT_SUCCESS;
}
