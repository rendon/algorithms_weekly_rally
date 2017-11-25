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
        int R, k, N;
        std::cin >> R >> k >> N;
        vector<int> G(N);
        for (int& g : G) {
            std::cin >> g;
        }
        vector<int> next(N, -1);
        vector<int> profit(N);
        for (int i = 0; i < N; i++) {
            int64 sum = 0;
            for (int j = 0; j < N; j++) {
                int idx = (i + j) % N;
                sum += G[idx];
                if (sum > k) {
                    break;
                }
                next[i] = (idx + 1) % N;
                profit[i] = sum;
            }
        }
        int64 ans = 0;
        int idx = 0;
        for (int i = 0; i < R; i++) {
            ans += profit[idx];
            idx = next[idx];
        }
        std::cout << "Case #" << tc << ": " << ans << std::endl;
    }
    return EXIT_SUCCESS;
}
