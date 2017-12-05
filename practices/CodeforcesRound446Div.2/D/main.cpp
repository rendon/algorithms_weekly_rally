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
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (int& a : A) {
        std::cin >> a;
    }
    if (n == 1) {
        std::cout << A[0] << std::endl;
        return EXIT_SUCCESS;
    }

    map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[A[i]] = i;
    }

    std::sort(A.begin(), A.end());
    vector<int> B(n);
    for (int i = 0; i + 1 < n; i++) {
        B[index[A[i]]] = A[i+1];
    }
    B[index[A[n-1]]] = A[0];

    for (int b : B) {
        std::cout << b << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
