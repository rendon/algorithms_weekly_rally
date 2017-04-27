/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
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
#include <algorithm>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// const double kEps   = 10e-8;
// const int kMax      = 1000;
// const int kInf      = 1 << 30;
// endregion

int64 f(int r, int c) {
    if (r == 1) {
        return 1;
    }
    int ans = 0;
    for (int len = 1; len <= 3; len++) {
        if (r - len >= 0) {
            ans += f(r - len, c);
        }
    }
    ans *= c - 1;
    return ans;
}

int main() {
    cout << f(3, 2) << endl;
    return EXIT_SUCCESS;
}
