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
    std::cout << std::fixed << std::setprecision(10);
    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;
        vector<int> A(N);
        for (int& a : A) {
            std::cin >> a;
        }
        vector<int> B = A;
        std::sort(B.begin(), B.end());
        double ans = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] != B[i]) {
                ans++;
            }
        }
        std::cout << "Case #" << tc << ": " << ans << std::endl;
    }
    return EXIT_SUCCESS;
}
