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
    string expr;
    cin >> expr;
    vector<int> summands;
    for (char c : expr) {
        if (c != '+') {
            summands.push_back(c - '0');
        }
    }
    std::sort(summands.begin(), summands.end());
    int n = summands.size();
    for (int i = 0; i < n; i++) {
        cout << summands[i];
        if (i + 1 < n) {
            cout << "+";
        }
    }
    cout << endl;
    return EXIT_SUCCESS;
}
