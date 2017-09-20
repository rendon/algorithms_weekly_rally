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
const int kMax      = 1 << 25;
const int kInf      = 1 << 30;
// endregion

double dp[kMax];

void print(int bitmask) {
    for (int i = 0; i < 32; i++) {
        if (bitmask & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

inline int turnOn(int bitmask, int i) {
    return bitmask | (1 << i);
}

inline int turnOff(int bitmask, int i) {
    if (bitmask & (1 << i)) {
        return bitmask ^ (1 << i);
    }
    return bitmask;
}

class Solver {
public:
    Solver() {}
    Solver(int initialState, int n, int stopPosition, int whiteCount) {
        this->initialState = initialState;
        this->n = n;
        this->stopPosition = stopPosition;
        this->whiteCount = whiteCount;
    }

    int buildState(int state, int n, int pos) {
        bool bit = (state & (1<<pos)) != 0;
        int newState = state;
        int x = 0;
        for (int j = 0; j + 1 < n; j++, x++) {
            if (j == pos) {
                x++;
            }
            if (state & (1<<x)) {
                newState = turnOn(newState, j);
            } else {
                newState = turnOff(newState, j);
            }
        }
        if (bit) {
            newState = turnOn(newState, n - 1);
        } else {
            newState = turnOff(newState, n - 1);
        }
        return newState;
    }

    double f(int state, int n) {
        if (n == stopPosition) {
            // printf(">> ");
            // print(state);
            int wc = 0;
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) {
                    wc++;
                }
            }
            // printf("Ans: %lf\n", double(whiteCount - wc));
            return double(whiteCount - wc);
        }

        double& ans = dp[state];
        if (ans >= 0) {
            return ans;
        }

        double fav = 0;
        double tot = n;
        for (int i = 0; i < n; i++) {
            if (state & (1<<i)) {
                fav += 1.0;
            } else if (state & (1<<(n - i - 1))) {
                fav += 1.0;
            }
        }
        double p = 1.0 / tot;

        // printf("p = %lf\n", p);
        ans = 0;
        for (int i = 0; i < n; i++) {
            ans += std::max(
                p * f(buildState(state, n, i), n - 1),
                p * f(buildState(state, n, n - i - 1), n - 1)
            );
        }
        return ans;
    }

    double solve() {
        for (int i = 0; i < kMax; i++) {
            dp[i] = -1.0;
        }
        return f(initialState, n);
    }

private:
    int initialState;
    int n;
    int stopPosition;
    int whiteCount;
};

int main() {
    int n, k;
    int initialState = 0;
    string str;
    cin >> n >> k;
    cin >> str;
    int wc = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'W') {
            initialState = initialState | (1 << i);
            wc++;
        }
    }

    Solver solver(initialState, n, n - k,  wc);

    cout << std::fixed << std::setprecision(12) << solver.solve() << endl;
    return EXIT_SUCCESS;
}
