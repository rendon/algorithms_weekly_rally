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

int64 f(int64 N) {
    char buf[20];
    int64 ans = 0;
    for (int64 i = 1; i <= N; i++) {
        sprintf(buf, "%lld", i);
        bool ok = true;
        int len = strlen(buf);
        for (int i = 1; i < len && ok; i++) {
            if (buf[i] < buf[i-1]) {
                ok = false;
            }
        }
        if (ok) {
            ans = std::max(ans, i);
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int64 N;
        cin >> N;
        cout << "Case #" << tc << ": " << f(N) << endl;
    }
    return EXIT_SUCCESS;
}
