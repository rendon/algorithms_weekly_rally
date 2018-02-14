/* Copyright 2018 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
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

const int kTarget = (1 << 10) - 1;

string str(int x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

string solve(int N) {
    if (N == 0) {
        return "INSOMNIA";
    }

    int digits = 0;
    for (int i = 1; ; i++) {
        int x = i * N;
        while (x > 0) {
            int d = x % 10;
            x /= 10;
            digits |= (1 << d);
        }
        if (digits == kTarget) {
            return str(i * N);
        }
    }
    return "INSOMNIA";
}

int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;
        std::cout << "Case #" << tc << ": " << solve(N) << std::endl;
    }
    return EXIT_SUCCESS;
}
