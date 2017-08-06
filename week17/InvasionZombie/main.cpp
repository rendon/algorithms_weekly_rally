/* Copyright 2016 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
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

class ZombieInvasion {
public:
    ZombieInvasion() { }
    ZombieInvasion(int N, int K, int row, int col) {
        this->N = N;
        this->K = K;
        this->row = row;
        this->col = col;
    }

    int64 findExtinctionDay() {
        int64 low = 0, high = N + N + 1;
        while (low < high) {
            int64 days = low + (high - low) / 2;
            if (isBeyondSalvation(days)) {
                high = days;
            } else {
                low = days + 1;
            }
        }
        return low;
    }

private:
    int64 N, K;
    int64 row, col;
    /**
     * Returns the number of infected neighbourhoods after x days;
     */
    inline int64 f(int64 x) {
        return x * x + (x + 1) * (x + 1);
    }

    inline int64 g(int64 x) {
        return x * (x + 1) / 2;
    }

    /**
     * Determines if the city has reached a point where it's not possible to be
     * saved, that is, if the number of infected neighborhoods is at least K.
     */
    bool isBeyondSalvation(int64 days) {
        int64 upperHeight  = std::max(0ll, days - (N - (col + 1)));
        int64 rightHeight  = std::max(0ll, days - (N - (row + 1)));
        int64 bottomHeight = std::max(0ll, days - col);
        int64 leftHeight   = std::max(0ll, days - row);

        int64 upperArea = upperHeight * upperHeight;
        int64 rightArea = rightHeight * rightHeight;
        int64 leftArea  = leftHeight  * leftHeight;
        int64 bottomArea = bottomHeight * bottomHeight;
        int64 center = f(days) - leftArea - rightArea - upperArea - bottomArea;

        int64 northWest = std::max(0ll, upperHeight - (row + 1));
        int64 northEast = std::max(0ll, upperHeight - (N - row));
        int64 southEast = std::max(0ll, bottomHeight - (N - row));
        int64 southWest = std::max(0ll, bottomHeight - (row + 1));
        center += g(northWest) + g(northEast) + g(southEast) + g(southWest);
        return center >= K;
    }
};

int main() {
    int64 N, r, c, K;
    cin >> N >> r >> c >> K;
    ZombieInvasion zombieInvasion(N, K, r - 1, c - 1);
    cout << zombieInvasion.findExtinctionDay() << endl;
    return EXIT_SUCCESS;
}
