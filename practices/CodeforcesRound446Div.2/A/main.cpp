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

using std::string;
using std::vector;
using std::map;
using std::set;
using std::queue;

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    int64 remaining = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
        remaining += A[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }
    std::sort(B.begin(), B.end());
    if (remaining <= B[n-2] + B[n-1]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return EXIT_SUCCESS;
}
