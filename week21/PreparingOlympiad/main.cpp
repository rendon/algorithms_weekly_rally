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

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int main() {
    int n, l, r, x;
    std::cin >> n >> l >> r >> x;
    vector<int> difficulties(n);
    for (int& d : difficulties) {
        std::cin >> d;
    }
    int ans = 0;
    for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
        int sum = 0;
        int min = kInf;
        int max = -kInf;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (bitmask & (1 << i)) {
                count++;
                sum += difficulties[i];
                min = std::min(min, difficulties[i]);
                max = std::max(max, difficulties[i]);
            }
        }
        if (count >= 2 && sum >= l && sum <= r && (max - min) >= x) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
