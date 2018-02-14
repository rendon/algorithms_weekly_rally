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

bool check(vector<int>& P, int k) {
    std::multiset<int> values;
    for (int p : P) {
        values.insert(p);
    }
    while (k > 0) {
        std::multiset<int>::iterator last = values.end();
        std::multiset<int>::iterator first = values.begin();
        int tallest = *(--last);
        if (k >= tallest) {
            return true;
        }

        int shortest = *first;
        if (tallest - shortest < 2) {
            values.erase(last);
            int half = tallest / 2;
            values.insert(half);
            values.insert(tallest - half);
        } else {
            values.erase(last);
            values.erase(first);
            int total = tallest + shortest;
            int half = total / 2;
            values.insert(half);
            values.insert(total - half);
        }
        k--;
    }
    return false;
}

int solve(vector<int>& P) {
    int high = *std::max_element(P.begin(), P.end()) + 1;
    for (int x = 1; x < high; x++) {
        if (check(P, x)) {
            return x;
        }
    }
    return high - 1;
    // int low = 0;
    // while (low < high) {
    //     int k = low + (high - low) / 2;
    //     if (check(P, k)) {
    //         high = k;
    //     } else {
    //         low = k + 1;
    //     }
    // }
    // return low;
}

int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int D;
        std::cin >> D;
        vector<int> P(D);
        for (int& p : P) {
            std::cin >> p;
        }
        std::cout << "Case #" << tc << ": " << solve(P) << std::endl;
    }
    return EXIT_SUCCESS;
}
