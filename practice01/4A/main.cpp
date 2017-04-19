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

bool test(int w) {
    for (int i = 1; i + i <= w; i++) {
        if ((i % 2 == 0) && (w - i) % 2 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int w;
    cin >> w;
    if (test(w)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return EXIT_SUCCESS;
}
