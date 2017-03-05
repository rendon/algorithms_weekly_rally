/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// const double kEps   = 10e-8;
// const int kMax      = 1000;
// const int kInf      = 1 << 30;
// endregion

bool isSubsequence(const string& S, const string& T) {
    unsigned int i = 0;
    unsigned int j = 0;
    while (i < S.length() && j < T.length()) {
        while (j < T.length() && T[j++] != S[i]);
        i++;
    }
    return i == S.length() && S[i-1] == T[j-1];
}

int main() {
    string S, T;
    while (cin >> S >> T) {
        if (isSubsequence(S, T)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return EXIT_SUCCESS;
}
