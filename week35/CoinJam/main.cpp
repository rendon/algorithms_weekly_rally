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
const int kMax      = 1 << 22;
const int kInf      = 1 << 30;
// endregion

int sieve[kMax];
vector<int64> primes;

class Solution {
public:
    Solution() { }

    Solution(int64 mask, const vector<int64>& divisors, int bitsize) {
        for (int i = 0; i < bitsize; i++) {
            if (mask & (1LL << i)) {
                coin += "1";
            } else {
                coin += "0";
            }
        }
        this->divisors = divisors;
    }

    const string& getCoin() {
        return coin;
    }

    const vector<int64>& getDivisors() {
        return divisors;
    }

private:
    string coin;
    vector<int64> divisors;
};

int64 convert(int64 mask, int base, int size) {
    int64 v = 0;
    for (int i = 0; i < size; i++) {
        int digit = ((mask & (1LL << i)) != 0) ? 1 : 0;
        v = v * base + digit;
    }
    return v;
}

void init() {
    int sr = std::sqrt(kMax);
    for (int i = 2; i <= sr; i++) {
        if (sieve[i] != 0) {
            continue;
        }
        for (int j = i * i; j < kMax; j += i) {
            sieve[j] = i;
        }
    }
    for (int i = 2; i < kMax; i++) {
        if (sieve[i] == 0) {
            primes.push_back(i);
        }
        if (primes.size() == 5000) {
            break;
        }
    }
}

vector<Solution> findSolutions(int N, int J) {
    vector<Solution> solutions;
    for (int64 mask = 0; mask < (1LL << (N - 2)); mask++) {
        int64 candidate = (mask << 1) | 1LL | (1LL << (N - 1));
        vector<int64> divisors;
        for (int base = 2; base <= 10; base++) {
            int64 x = convert(candidate, base, N);
            int64 divisor = -1;
            for (int64 p : primes) {
                if ((p < x) && (x % p == 0)) {
                    divisor = p;
                    break;
                }
            }
            if (x == 1590504037202545653841921LL) {
                std::cout << "div = " << divisor << std::endl;
            }
            if (divisor != -1) {
                divisors.push_back(divisor);
            }
        }
        if (divisors.size() == 9) {
            solutions.push_back(Solution(candidate, divisors, N));
        }
        if (int(solutions.size()) == J) {
            break;
        }
    }
    return solutions;
}

int main() {
    init();
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, J;
        std::cin >> N >> J;
        std::cout << "Case #" << tc << ":\n";

        for (Solution solution : findSolutions(N, J)) {
            std::cout << solution.getCoin() << " ";
            for (int divisor : solution.getDivisors()) {
                std::cout << " " << divisor;
            }
            std::cout << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
