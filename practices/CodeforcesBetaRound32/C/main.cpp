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
    int n, m, s;
    std::cin >> n >> m >> s;
    int64 x = 1;
    int64 count = 0;
    while (x <= m) {
        count++;
        x += s;
    }
    // std::cout << "count = " << count << std::endl;
    int64 h = count * (m - (x - s) + 1);

    int64 y = 1;
    count = 0;
    while (y <= n) {
        count++;
        y += s;
    }
    int64 v = count * (n - (y - s) + 1);

    // std::cout << "h = " << h << std::endl;
    // std::cout << "v = " << v << std::endl;
    std::cout << h * v << std::endl;
    return EXIT_SUCCESS;
}
