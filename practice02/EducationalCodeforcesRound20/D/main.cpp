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

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// endregion

bool test(vector<string>& words, int m, int k) {
    int len = 0;
    int splits = 0;
    for (int i = 0; i < int(words.size()) && (splits + 1) <= k; ) {
        string& word = words[i];
        if (len + word.length() <= m) {
            len += word.length();
            i++;
        } else {
            len = 0;
            splits++;
        }
    }
    return (splits + 1) <= k;
}

vector<string> split(string& text) {
    vector<string> words;
    string token;
    for (char c : text) {
        if (c == ' ') {
            words.push_back(token + ".");
            token = "";
        } else if (c == '-') {
            words.push_back(token + "-");
            token = "";
        } else {
            token += c;
        }
    }
    if (token != "") {
        words.push_back(token);
    }
    // for (string word : words) {
    //     cout << "W: " << word << endl;
    // }
    return words;
}

int solve(string& text, int k) {
    int l = 1;
    int h = text.length() + 1;
    vector<string> words = split(text);
    while (l < h) {
        int m = l + (h - l) / 2;
        if (!test(words, m, k)) {
            l = m + 1;
        } else {
            h = m;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    cin.get();
    string text;
    getline(cin, text);
    cout << solve(text, k) << endl;
    return EXIT_SUCCESS;
}
