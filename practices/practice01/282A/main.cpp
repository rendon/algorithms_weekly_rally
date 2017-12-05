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
    int X = 0;
    for (int i = 0; i < n; i++) {
        string stmt;
        cin >> stmt;
        if (stmt == "++X" || stmt == "X++") {
            X++;
        } else {
            X--;
        }
    }
    cout << X << endl;
    return EXIT_SUCCESS;
}
