/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <iomanip>
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

struct Horse {
    double position, speed;
    bool operator<(const Horse& that) const {
        return position < that.position;
    }
};

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int D, N;
        cin >> D >> N;
        vector<Horse> horses(N);
        for (auto& h : horses) {
            cin >> h.position >> h.speed;
        }
        std::sort(horses.begin(), horses.end());

        double speed = 1e-10;
        for (int i = N - 1; i >= 0; i--) {
            double dist = D - horses[i].position;
            speed = std::max(speed, dist / horses[i].speed);
        }
        cout << std::fixed << std::setprecision(9);
        cout << "Case #" << tc << ": " << double(D) / speed << endl;
    }
    return EXIT_SUCCESS;
}
