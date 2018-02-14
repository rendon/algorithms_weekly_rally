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

double solve(double C, double F, double X) {
    double rate = 2;
    double time = 0;
    double total = 0;
    while (total < X) {
        if ((X - total) < (C - total)) {
            return total + (X - total) / rate;
        }
        time += C / rate;
        total += C;
        double noBuyCost = time + ((X - total) / rate);
        double buyCost = time + X / (rate + F);
        if (noBuyCost < buyCost) {
            return noBuyCost;
        }
        total = 0;
        rate += F;
    }
    return -1;
}

int main() {
    int T;
    std::cin >> T;
    std::cout << std::fixed << std::setprecision(7);
    for (int tc = 1; tc <= T; tc++) {
        double C, F, X;
        std::cin >> C >> F >> X;
        std::cout << "Case #" << tc << ": " << solve(C, F, X) << std::endl;
    }
    return EXIT_SUCCESS;
}
