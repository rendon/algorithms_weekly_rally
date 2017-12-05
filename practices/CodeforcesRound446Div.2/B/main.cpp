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
    vector<int> L(n + 1);
    vector<int> R(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> L[i];
    }

    for (int i = 1; i <= n; i++) {
        int v = i - L[i];
        int s = std::max(1, v);
        R[s] = i - 1;
        // std::cout << "s = " << s << " v = " << v << " " << R[s] << " ";
    }
    int ans = 0;
    int pos = 1;
    int max = 0;
    while (pos <= n) {
        if (R[pos] >= pos) {
            if (R[pos] > max) {
                max = R[pos];
            }
        }

        if (pos > max) {
            ans++;
        }
        pos++;
    }
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
