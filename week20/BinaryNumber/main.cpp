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

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int main() {
    string S;
    cin >> S;
    bool hasOdd = false;
    int ans = 0;
    for (int i = S.length() - 1; i > 0; i--) {
        if (hasOdd) {
            if (S[i] == '0') {
                ans++;
            }
        } else if (S[i] == '1') {
            hasOdd = true;
            ans++;
        }
        ans++;
    }
    if (hasOdd) {
        ans++;
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}
