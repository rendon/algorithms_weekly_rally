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

struct Bot {
    int position, time;
};

int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;
        Bot orange{1, 0};
        Bot blue{1, 0};
        for (int i = 0; i < N; i++) {
            string bot;
            int button;
            std::cin >> bot >> button;
            if (bot == "O") {
                orange.time += std::abs(orange.position - button) + 1;
                if (orange.time <= blue.time) {
                    orange.time = blue.time + 1;
                }
                orange.position = button;
            } else {
                blue.time += std::abs(blue.position - button) + 1;
                if (blue.time <= orange.time) {
                    blue.time = orange.time + 1;
                }
                blue.position = button;
            }
        }
        std::cout << "Case #" << tc << ": " << std::max(orange.time, blue.time)
            << std::endl;
    }
    return EXIT_SUCCESS;
}
