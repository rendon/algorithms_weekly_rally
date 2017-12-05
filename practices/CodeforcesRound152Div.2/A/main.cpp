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
    int n;
    std::cin >> n;
    vector<std::pair<int, int>> cupboards(n);
    for (auto& cupboard : cupboards) {
        std::cin >> cupboard.first >> cupboard.second;
    }
    int ans = std::numeric_limits<int>::max();
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            int count = 0;
            for (auto cupboard : cupboards) {
                if (cupboard.first != a) {
                    count++;
                }
                if (cupboard.second != b) {
                    count++;
                }
            }
            ans = std::min(ans, count);
        }
    }
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
