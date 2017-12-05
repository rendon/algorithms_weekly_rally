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
    int s, n;
    std::cin >> s >> n;
    vector<std::pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        std:: cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end());
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (s > A[i].first) {
            s += A[i].second;
        } else {
            possible = false;
            break;
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return EXIT_SUCCESS;
}
