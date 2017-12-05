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
const int kMaxN = 5005;
const int kInf      = 1 << 30;
const int64 kMod = 998244353LL;
// endregion

int64 cache[kMaxN][kMaxN];
vector<vector<int>> factorsMap;
vector<int> primes;

vector<int> factorize(int64 n) {
    vector<int> factors;
    int64 x = n;
    for (int i = 0; i < int(primes.size()) && primes[i] * primes[i] <= n; i++) {
        while (x % primes[i] == 0) {
            factors.push_back(primes[i]);
            x /= primes[i];
        }
    }
    if (x > 1) {
        factors.push_back(x);
    }
    return factors;
}


void init() {
    memset(cache, -1, sizeof cache);
    std::bitset<kMax> sieve;
    for (int i = 2; i * i < kMax; i++) {
        if (!sieve.test(i)) {
            for (int j = i * i; j < kMax; j += i) {
                sieve.set(j);
            }
        }
    }
    for (int i = 2; i < kMax; i++) {
        if (!sieve.test(i)) {
            primes.push_back(i);
        }
    }

    factorsMap.resize(kMaxN);
    for (int64 i = 1; i < kMaxN; i++) {
        factorsMap[i] = factorize(i);
    }
}

int64 modpow(int64 b, int64 p) {
    int64 x = 1;
    int64 y = b;
    while (p > 0) {
        if (p % 2 == 1) {
            x = (x * y) % kMod;
        }
        p /= 2;
        y = (y * y) % kMod;
    }
    return x;
}


// Solution:
// 1. We cannot have links between nodes in the samecluster, period.
// 2. We 0 or more links between two clusters, but we cannot have "triangles",
//    that is, a node in one cluster cannot be connected to more than one node
//    in the other cluster because we would have a path between two nodes in
//    the same cluster with a distance of 2, breaking the rule.
// 3. Compute the number of *different* ways to choose i nodes in the first
//    cluster and multiply that by the number of ways to assign these nodes to
//    different nodes in the second cluster.
int64 f(int64 a, int64 b) {
    int64 min = std::min(a, b);
    int64 max = std::max(a, b);
    int64 x = 1;

    map<int, int> factors;
    for (int i = 1; i <= min; i++) {
        for (int factor : factorsMap[min-i+1]) {
            factors[factor]++;
        }

        for (int factor : factorsMap[i]) {
            factors[factor]--;
        }
        
        // nCk(min, i)
        // i = the number of active links betweee the two clusters
        int64 chooseA = 1;
        for (auto e : factors) {
            chooseA = (chooseA * modpow(e.first, e.second));
            if (chooseA >= kMod) {
                chooseA %= kMod;
            }
        }

        // Multiply max * (max - 1) * ... * (max - i + 1)
        int64 chooseB = 1;
        for (int j = max; j > max - i; j--) {
            chooseB = chooseB * j;
            if (chooseB >= kMod) {
                chooseB %= kMod;
            }
        }
        x += chooseA * chooseB;
        if (x >= kMod) {
            x %= kMod;
        }
    }
    return x;
}

int main() {
    int64 a, b, c;
    std::cin >> a >> b >> c;
    init();
    int64 x = f(a, b);
    int64 y = f(a, c);
    int64 z = f(b, c);
    std::cout << ((((x % kMod) * (y % kMod)) % kMod) * z) % kMod << std::endl;
    return EXIT_SUCCESS;
}
