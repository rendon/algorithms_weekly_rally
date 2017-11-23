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
    string A, B;
    std::cin >> A >> B;
    int n = A.length();
    int m = B.length();
    int i = 0;
    int ans = 0;
    while (i <= n - m) {
        int j = 0;
        while (j < m) {
            if (A[i+j] == B[j]) {
                j++;
            } else {
                break;
            }
        }
        if (j >= m) {
            ans++;
            i += m;
        } else {
            i++;
        }
    }
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
