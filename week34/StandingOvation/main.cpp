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
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int smax;
        std::cin >> smax;
        string levels;
        std::cin >> levels;
        int ans = 0;
        int sum = 0;
        for (int x = 0; x < int(levels.length()); x++) {
            if (sum < x) {
                ans += x - sum;
                sum = x;
            }
            sum += levels[x] - '0';
        }
        std::cout << "Case #" << tc << ": " << ans << std::endl;
    }
    return EXIT_SUCCESS;
}
