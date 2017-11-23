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
    string s;
    std::cin >> s;
    vector<int> frequencies(26, 0);
    for (char ch : s) {
        frequencies[ch-'a']++;
    }
    
    int count = 0;
    for (int f : frequencies) {
        if (f > 1) {
            count += f - 1;
        }
    }

    if (n > 26) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << count << std::endl;
    }
    return EXIT_SUCCESS;
}
