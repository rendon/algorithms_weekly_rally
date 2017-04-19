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
    map<char, bool> vowels = {
        {'A', true},
        {'O', true},
        {'Y', true},
        {'E', true},
        {'U', true},
        {'I', true},
        {'a', true},
        {'o', true},
        {'y', true},
        {'e', true},
        {'u', true},
        {'i', true}
    };
    string str;
    cin >> str;
    string ans;
    for (char s : str) {
        if (!vowels[s]) {
            ans += tolower(s);
        }
    }

    for (char s : ans) {
        cout << "." << s;
    }
    cout << endl;
    return EXIT_SUCCESS;
}
