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
    vector<int> A(n);
    int k = readInt();
    vector<int> O(k);
    vector<int> T(k);

    for (int i = 0; i < n; i++) {
        A[i] = readInt();
        if (A[i] == 1) {
            O[i%k]++;
        } else {
            T[i%k]++;
        }
    }

    int answer = 0;
    for (int i = 0; i < k; i++) {
        answer += std::min((n / k) - O[i], (n / k) - T[i]);
    }
    std::cout << answer << std::endl;
    return EXIT_SUCCESS;
}
