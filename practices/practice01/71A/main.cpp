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
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        if (line.length() > 10) {
            cout << line[0] << line.length() - 2 << line[line.length()-1] << endl;
        } else {
            cout << line << endl;
        }
    }
    return EXIT_SUCCESS;
}
