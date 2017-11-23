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
#include <numeric>
#include <iomanip>
#include <algorithm>

using std::string;
using std::vector;
using std::map;
using std::set;
using std::queue;

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

const int kMod = 10000;

int dp[505][20];
int f(string& text, string& phrase, int t, int p) {
    if (t >= int(text.length())) {
        return (p >= int(phrase.length())) ? 1 : 0;
    }
    if (p >= int(phrase.length())) {
        return 1;
    }
    int& ans = dp[t][p];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (text[t] == phrase[p]) {
        ans = (ans + f(text, phrase, t + 1, p + 1)) % kMod;
        ans = (ans + f(text, phrase, t + 1, p)) % kMod;
    } else {
        ans = (ans + f(text, phrase, t + 1, p)) % kMod;
    }
    return ans;
}

int main() {
    string phrase = "welcome to code jam";
    int N;
    std::cin >> N;
    std::cin.get();
    for (int tc = 1; tc <= N; tc++) {
        string text;
        std::getline(std::cin, text);
        memset(dp, -1, sizeof dp);
        int ans = f(text, phrase, 0, 0);
        printf("Case #%d: %04d\n", tc, ans);
    }
    return EXIT_SUCCESS;
}
