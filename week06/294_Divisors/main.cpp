/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <cmath>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const int kMax      = 31625;
// endregion

bitset<kMax> sieve;
vector<int> primes;

void init() {
    sieve.set();
    sieve.reset(0);
    sieve.reset(1);
    int sr = std::sqrt(kMax);
    for (int i = 2; i <= sr; i++) {
        for (int j = i * i; j < kMax; j += i) {
            sieve.reset(j);
        }
    }
    for (int i = 2; i < kMax; i++) {
        if (sieve.test(i)) {
            primes.push_back(i);
        }
    }
}

inline int countDivisors(int n) {
    int sr = std::sqrt(n);
    int size = primes.size();
    int divs = 1;
    for (int i = 0; i < size && primes[i] <= sr && n > 1; i++) {
        int p = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            p++;
        }
        divs *= p + 1;
    }
    if (n > 1) {
        divs *= 2;
    }
    return divs;
}

pair<int, int> findNumberWithMostDivisors(int L, int U) {
    int maxN = 0;
    int maxDivisors = 0;
    for (int n = L; n <= U; n++) {
        int divs = countDivisors(n);
        if (maxDivisors < divs) {
            maxN = n;
            maxDivisors = divs;
        }
    }
    return {maxN, maxDivisors};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int N;
    cin >> N;
    while (N--) {
        int L, U;
        cin >> L >> U;
        auto ans = findNumberWithMostDivisors(L, U);
        cout << "Between " << L << " and " << U << ", " << ans.first
             << " has a maximum of " << ans.second << " divisors.\n";
    }
    return EXIT_SUCCESS;
}
