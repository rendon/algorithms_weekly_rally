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
const int kMax      = 7555;
// endregion

const vector<int> coins{1, 5, 10, 25, 50};
int changeWays[kMax][5];

void computeChangeWays() {
    for (unsigned i = 0; i < coins.size(); i++) {
        changeWays[0][i] = 1;
    }
    for (int cents = 1; cents < kMax; cents++) {
        for (int p = 0; p < int(coins.size()); p++) {
            for (int i = 0; i <= p; i++) {
                int coin = coins[i];
                if (cents - coin >= 0) {
                    changeWays[cents][p] += changeWays[cents-coin][i];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cents;
    computeChangeWays();
    while (cin >> cents) {
        cout << changeWays[cents][int(coins.size()-1)] << "\n";
    }
    return EXIT_SUCCESS;
}
