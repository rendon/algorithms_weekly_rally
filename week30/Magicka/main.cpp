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

int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int C;
        std::cin >> C;
        map<string, char> compound;
        for (int i = 0; i < C; i++) {
            string str;
            std::cin >> str;
            string k = str.substr(0, 2);
            compound[k] = str[2];
            std::reverse(k.begin(), k.end());
            compound[k] = str[2];
        }
        int D;
        std::cin >> D;
        map<string, bool> opposed;
        for (int i = 0; i < D; i++) {
            string k;
            std::cin >> k;
            opposed[k] = true;
            std::reverse(k.begin(), k.end());
            opposed[k] = true;
        }
        int N;
        std::cin >> N;
        string sequence;
        std::cin >> sequence;
        vector<char> state;
        for (char s : sequence) {
            if (state.empty()) {
                state.push_back(s);
                continue;
            }

            string k(1, s);
            char last = state[state.size()-1];
            k += last;
            if (compound.count(k) == 1) {
                state.pop_back();
                state.push_back(compound[k]);
                continue;
            }

            bool clear = false;
            k = string(1, s);
            for (char c : state) {
                if (opposed[k+c]) {
                    clear = true;
                }
            }
            if (clear) {
                state.clear();
            } else {
                state.push_back(s);
            }
        }

        std::cout << "Case #" << tc << ": [";
        int size = state.size();
        for (int i = 0; i < size; i++) {
            std::cout << state[i];
            if (i + 1 < size) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";

    }
    return EXIT_SUCCESS;
}
