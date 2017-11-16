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
const int kMaxS = 105;
const int kMaxQ = 1005;
// endregion

class Solver {
public:
    Solver() { }
    Solver(vector<string> engines, vector<string> queries) {
        this->engines = engines;
        this->queries = queries;
        this->S = engines.size();
        this->Q = queries.size();
    }

    int f(int s, int q) {
        if (q == Q) {
            return 0;
        }

        int& ans = dp[s][q];
        if (ans != -1) {
            return ans;
        }

        ans = kInf;
        for (int i = 0; i < S; i++) {
            int cost = 1;
            if (i == s) {
                cost = 0;
            }
            if (engines[i] != queries[q]) {
                ans = std::min(ans, f(i, q + 1) + cost);
            }
        }
        return ans;
    }

    int solve() {
        dp = vector<vector<int>>(kMaxS, vector<int>(kMaxQ, -1));
        int ans = kInf;
        for (int i = 0; i < S; i++) {
            ans = std::min(ans, f(i, 0));
        }
        return ans;
    }

private:
    vector<string> engines;
    vector<string> queries;
    vector<vector<int>> dp;
    int S, Q;
};

int main() {
    int N;
    std::cin >> N;
    for (int tc = 1; tc <= N; tc++) {
        int S;
        std::cin >> S;
        std::cin.get();
        vector<string> engines(S);
        for (string& engine : engines) {
            std::getline(std::cin, engine);
        }
        int Q;
        std::cin >> Q;
        std::cin.get();
        vector<string> queries(Q);
        for (string& query : queries) {
            std::getline(std::cin, query);
        }

        Solver solver(engines, queries);

        std::cout << "Case #" << tc << ": " << solver.solve() << std::endl;
    }
    return EXIT_SUCCESS;
}
