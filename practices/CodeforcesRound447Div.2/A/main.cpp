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
    string S;
    std::cin >> S;
    int n = S.length();
    int ans = 0;
    for (int i = 0; i + 2 < n; i++) {
        for (int j = i + 1; j + 1 < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (S[i] == 'Q' && S[j] == 'A' && S[k] == 'Q') {
                    ans++;
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
