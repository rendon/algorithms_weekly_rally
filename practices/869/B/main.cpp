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
    int64 a, b;
    std::cin >> a >> b;
    int64 ans;
    if (b - a < 100) {
        ans = 1;
        for (int64 i = a + 1; i <= b; i++) {
            ans = (ans * i) % 10;
        }
    } else {
        ans = 0;
    }
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
