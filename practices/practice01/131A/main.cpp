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
bool test(string word) {
    bool up = true;
    for (char c : word) {
        if (islower(c)) {
            up = false;
            break;
        }
    }
    if (up) {
        return true;
    }
    bool suffixUp = true;
    int n = word.length();
    for (int i = 1; i < n; i++) {
        if (islower(word[i])) {
            suffixUp = false;
        }
    }
    return suffixUp;
}

char flip(char c) {
    if (isupper(c)) {
        return tolower(c);
    } else {
        return toupper(c);
    }
}

int main() {
    string word;
    cin >> word;
    if (test(word)) {
        for (char c : word) {
            cout << flip(c);
        }
        cout << endl;
    } else {
        cout << word << endl;
    }
    return EXIT_SUCCESS;
}
