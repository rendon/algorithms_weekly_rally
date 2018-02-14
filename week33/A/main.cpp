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
const int kMax      = 4;
const int kInf      = 1 << 30;
// endregion

class MagickTrick {
public:
    MagickTrick() {
        std::cin >> firstAnswer;
        firstAnswer--;
        for (int i = 0; i < kMax; i++) {
            for (int j = 0; j < kMax; j++) {
                std::cin >> before[i][j];
            }
        }
        std::cin >> secondAnswer;
        secondAnswer--;
        for (int i = 0; i < kMax; i++) {
            for (int j = 0; j < kMax; j++) {
                std::cin >> after[i][j];
            }
        }
    }

    string solve() {
        map<int, int> frequencies;
        for (int j = 0; j < kMax; j++) {
            frequencies[before[firstAnswer][j]]++;
            frequencies[after[secondAnswer][j]]++;
        }

        vector<int> common;
        for (auto e : frequencies) {
            if (e.second == 2) {
                common.push_back(e.first);
            }
        }
        int size = common.size();
        if (size == 1) {
            char buf[16];
            sprintf(buf, "%d", common[0]);
            return string(buf);
        } else if (size == 0) {
            return "Volunteer cheated!";
        } else {
            return "Bad magician!";
        }
    }

private:
    int firstAnswer;
    int secondAnswer;
    int before[4][4];
    int after[4][4];
};


int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        MagickTrick magickTrick;
        std::cout << "Case #" << tc <<": " << magickTrick.solve() << std::endl;
    }
    return EXIT_SUCCESS;
}
