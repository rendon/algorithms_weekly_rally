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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) {
            ans++;
        }
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}
