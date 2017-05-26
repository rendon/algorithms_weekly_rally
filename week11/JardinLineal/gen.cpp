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
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

bool test(string& garden, int p) {
    for (int i = 0; i <= p; i++) {
        int diff = 0;
        for (int j = i; j <= p; j++) {
            if (garden[j] == 'L') {
                diff--;
            } else {
                diff++;
            }
            if (std::abs(diff) > 2) {
                return false;
            }
        }
    }
    return true;
}

void gen(int p, string& garden, int& pos, int state) {
    if (p == int(garden.length())) {
        cout << p << " " << 997 << "\n";
        cout << garden << "\n";
        cout << ">> " << (pos % 997) << "\n";
        pos++;
        return;
    }

    if (!(state & 1)) {
        garden[p] = 'L';
        gen(p + 1, garden, pos, (state>>1)|(1<<1));
    }
    if (!(state & (1 << 4))) {
        garden[p] = 'P';
        gen(p + 1, garden, pos,  (state<<1)|(1<<3));
    }
}

int main() {
    string garden(20, '0');
    int pos = 1;
    gen(0, garden, pos, 0);
    return EXIT_SUCCESS;
}
