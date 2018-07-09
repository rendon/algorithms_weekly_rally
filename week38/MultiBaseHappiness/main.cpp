/* Copyright 2018 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
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
const int kMax      = 10000015;
const int kInf      = 1 << 30;
// endregion

const int kHappy = 1;
const int kNotHappy = 2;
int happiness[kMax][11];
int maxV = 0;

bool isHappy(int x, int base) {
    vector<bool> visited(kMax);
    int n = x;
    vector<int> steps;
    bool flag = true;
    // printf("n = %d\n", n);
    while (true) {
        steps.push_back(n);
        visited[n] = true;
        int v = 0;
        while (n > 0) {
            int d = n % base;
            v += d * d;
            n /= base;
        }
        maxV = std::max(maxV, v);
        if (flag) {
            // printf(">> %d\n", v);
            flag = false;
        }
        n = v;
        if (visited[n]) {
            return false;
        }
        if (n == 1) {
            return true;
        }
    }
    return false;
}

bool isHappy(int x, const vector<int>& bases) {
    for (int base : bases) {
        if (!isHappy(x, base)) {
            return false;
        }
    }
    return true;
}   

void solve(int tc, const vector<int>& bases) {
    std::cout << "Case #" << tc << ": ";
    for (int x = 2; ; x++) {
        if (isHappy(x, bases)) {
            std::cout << x << std::endl;
            return;
        }
    }
}

int main() {
    int count = 0;
    for (int base = 10; base <= 10; base++) {
        for (int x = 2; x < 1000; x++) {
            if (isHappy(x, base)) {
                count++;
                printf("=================> %d\n", x);
            }
        }
    }
    printf("Count = %d\n", count);
    // int T;
    // std::cin >> T;
    // std::cin.get();
    // for (int tc = 1; tc <= T; tc++) {
    //     string line;
    //     std::getline(std::cin, line);
    //     std::stringstream ss(line);

    //     vector<int> bases;
    //     int base;
    //     while (ss >> base) {
    //         bases.push_back(base);
    //     }

    //     solve(tc, bases);
    // }
    return EXIT_SUCCESS;
}
