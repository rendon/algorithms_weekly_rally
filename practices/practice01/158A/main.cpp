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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int& a : A) {
        cin >> a;
    }
    int ans = 0;
    for (int a : A) {
        if (a > 0 && a >= A[k-1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}
