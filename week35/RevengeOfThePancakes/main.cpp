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

int solve(const string& S) {
    char current = (S[0] == '+') ? 1 : 0;
    int pos = 0;
    int length = S.length();
    int ans = 0;
    while (pos < length) {
        int next = pos + 1;
        while (S[next] == S[pos]) {
            next++;
        }
        if (next >= length) {
            return (current == 0) ? ans + 1 : ans;
        }

        ans += 1;
        current = 1 - current;
        pos = next;
    }
    return -1;
}

int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string S;
        std::cin >> S;
        std::cout << "Case #" << tc << ": " << solve(S) << std::endl;
    }
    return EXIT_SUCCESS;
}
