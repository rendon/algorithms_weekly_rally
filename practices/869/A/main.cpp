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
    vector<int> A(n);
    vector<int> B(n);

    set<int> S;
    for (int& a : A) {
        std::cin >> a;
        S.insert(a);
    }

    for (int& b : B) {
        std::cin >> b;
        S.insert(b);
    }


    int ans = 0;
    for (int a : A) {
        for (int b : B) {
            if (S.find(a ^ b) != S.end()) {
                ans++;
            }
        }
    }
    if (ans % 2 == 0) {
        std::cout << "Karen\n";
    } else {
        std::cout << "Koyomi\n";
    }
    return EXIT_SUCCESS;
}
