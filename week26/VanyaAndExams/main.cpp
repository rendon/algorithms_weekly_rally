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

struct ExamDetail {
    int grade, costPerPoint;

    bool operator<(const ExamDetail& that) const {
        if (costPerPoint != that.costPerPoint) {
            return costPerPoint < that.costPerPoint;
        }
        return grade < that.grade;
    }
};

bool check(vector<ExamDetail>& details, int r, int avg, int64 m) {
    int64 sum = 0;
    for (auto detail : details) {
        sum += detail.grade;
        int64 availablePoints = r - detail.grade;
        int64 quantity = std::min(m / detail.costPerPoint, availablePoints);
        sum += quantity;
        m -= quantity * detail.costPerPoint;
    }

    return sum / double(details.size()) >= avg;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, r, avg;
    std::cin >> n >> r >> avg;

    vector<ExamDetail> details(n);
    for (auto& detail : details) {
        std::cin >> detail.grade >> detail.costPerPoint;
    }

    std::sort(details.begin(), details.end());

    // for (auto detail : details) {
    //     std::cout << detail.grade << " " << detail.costPerPoint << std::endl;
    // }

    int64 low = 0;
    // 10^18 + 1
    int64 high = 1000000000000000001LL;
    while (low < high) {
        int64 m = low + (high - low) / 2;
        if (check(details, r, avg, m)) {
            high = m;
        } else {
            low = m + 1;
        }
    }
    std::cout << low << std::endl;
    return EXIT_SUCCESS;
}
