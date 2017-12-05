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
    vector<int> A(n);
    int ones = 0;
    for (int& a : A) {
        std::cin >> a;
        if (a == 1) {
            ones++;
        }
    }
    if (ones > 0) {
        std::cout << n - ones << std::endl;
    } else {
        int minLength = kInf;
        for (int i = 0; i < n; i++) {
            int g = A[i];
            for (int j = i + 1; j < n; j++) {
                g = std::__gcd(g, A[j]);

                if (g == 1) {
                    if ((j - i + 1) < minLength) {
                        minLength = j - i + 1;
                    }
                }
            }
        }
        if (minLength == kInf) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << (minLength - 1)  + n - 1 << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
