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
const int kMax      = 1100000;
const int kInf      = 1 << 30;
// endregion

std::bitset<kMax> sieve;


map<int64, bool> M;
void init() {
    int64 sr = std::sqrt(kMax);
    for(int64 i = 2; i <= sr; i++) {
        if (!sieve.test(i)) {
            for (int64 j = i * i; j < kMax; j += i) {
                sieve.set(j);
            }
        }
    }
    for (int64 i = 2; i < kMax; i++) {
        if (!sieve.test(i)) {
            M[i*i] = true;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    int n;
    std::cin >> n;
    vector<int64> X(n);
    for (int64& x : X) {
        std::cin >> x;
    }
    for (int64 x : X) {
        if (M[x]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return EXIT_SUCCESS;
}
