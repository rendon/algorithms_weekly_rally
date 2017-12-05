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
    string A, B;
    cin >> A >> B;
    for (char& c : A) {
        c = tolower(c);
    }
    for (char& c : B) {
        c = tolower(c);
    }
    if (A < B) {
        cout << "-1\n";
    } else if (A == B) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
    return EXIT_SUCCESS;
}
