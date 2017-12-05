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
// endregion

int main() {
    int M, N;
    cin >> M >> N;
    int ans = 0;
    int a = 0;
    if (M % 2 == 1) {
        ans = M - 1;
        a = N;
    } else {
        ans = M;
    }

    int b = 0;
    if (N % 2 == 1) {
        ans *= (N - 1);
        b = M;
    } else {
        ans *= N;
    }
    ans /= 2;
    ans += a / 2;
    ans += b / 2;
    cout << ans << endl;
    return EXIT_SUCCESS;
}
