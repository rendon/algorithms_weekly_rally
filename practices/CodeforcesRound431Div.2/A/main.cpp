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

bool isPossible(vector<int>& A) {
    int n = A.size();
    if (A[0] % 2 == 0 || A[n-1] % 2 == 0) {
        return false;
    }

    if (n % 2 == 1) {
        return true;
    }

    int leftSize = 0;
    int count = 0;
    for (int i = 0; i + 1 < n; i++) {
        leftSize++;
        int rightSize = n - i - 1;
        if (leftSize % 2 == 0 || rightSize % 2 == 0) {
            continue;
        }
        if (A[i] % 2 == 1 && A[i+1] % 2 == 1) {
            count++;
            leftSize = 0;
        }
    }

    return count > 1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (int& a : A) {
        std::cin >> a;
    }
    if (isPossible(A)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return EXIT_SUCCESS;
}
