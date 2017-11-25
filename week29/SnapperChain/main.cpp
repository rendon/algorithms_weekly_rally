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
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int64 N, K;
        std::cin >> N >> K;
        int64 target = 1LL << N;
        K %= target;
        std::cout << "Case #" << tc << ": ";
        if (K + 1 == target) {
            std::cout << "ON\n";
        } else {
            std::cout << "OFF\n";
        }
    }
    return EXIT_SUCCESS;
}
