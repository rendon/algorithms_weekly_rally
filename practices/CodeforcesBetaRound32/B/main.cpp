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
    string s;
    std::cin >> s;
    int n = s.length();
    int i = 0;
    while (i < n) {
        if (s[i] == '.') {
            std::cout << 0;
            i++;
        } else if (s[i+1] == '.') {
            std::cout << 1;
            i += 2;
        } else {
            std::cout << 2;
            i += 2;
        }
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
