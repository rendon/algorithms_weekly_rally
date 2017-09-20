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
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

int main() {
    vector<int> A(26, 0);
    string str;
    cin >> str;
    for (char ch : str) {
        A[ch-'a']++;
    }
    int oddCount = 0;
    for (int a : A) {
        if (a % 2 == 1) {
            oddCount++;
        }
    }
    if (oddCount > 0) {
        oddCount--;
    }
    if (oddCount % 2 == 0) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return EXIT_SUCCESS;
}
