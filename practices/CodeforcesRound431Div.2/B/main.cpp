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
#include <complex>

using std::string;
using std::vector;
using std::map;
using std::set;
using std::queue;
using std::pair;

typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

struct Point {
    double x, y;

    Point() { }
    Point(double x, double y) : x(x), y(y) { }
};



std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

double cross(const Point& a, const Point& b) {
    return std::abs(a.x * b.y - b.x * a.y);
}

double dist(const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    // std::cout << "dx = " << dx << " dy = " << dy << std::endl;
    return std::sqrt(dx * dx + dy * dy);
}

bool isPossible(vector<Point>& points, int s, int n) {
    vector<bool> touched(n);
    for (int i = 1; i < n; i++) {
        std::fill(touched.begin(), touched.end(), false);
        Point A(points[i].x - points[s].x, points[i].y - points[s].y);

        // std::cout << points[s] << " -- " << points[i] << std::endl;
        vector<Point> rest;
        for (int j = 0; j < n; j++) {
            if (j == s || j == i) {
                continue;
            }
            Point B(points[j].x - points[s].x, points[j].y - points[s].y);
            double x = cross(A, B);
            double d = dist(points[s], points[i]);
            double distToLine = x / d;
            if (distToLine < kEps) {
                // std::cout << "cross = " << x << std::endl;
                // std::cout << "distToLine = " << distToLine << std::endl;
                // std::cout << points[j] << " in!\n";
                touched[j] = true;
            } else {
                if (rest.size() < 2) {
                    rest.push_back(points[j]);
                }
            }
        }
        if (rest.size() == 0) {
            continue;
        }

        if (rest.size() == 1) {
            return true;
        }

        Point P(rest[1].x - rest[s].x, rest[1].y - rest[s].y);
        bool possible = cross(A, P) < kEps;
        int d = dist(rest[s], rest[1]);
        for (int j = 0; j < n && possible; j++) {
            if (j == s || j == i || touched[j]) {
                continue;
            }
            Point Q(points[j].x - rest[s].x, points[j].y - rest[s].y);
            double x = cross(P, Q);
            if (x / d < kEps) {
                touched[j] = true;
            } else {
                possible = false;
            }
        }

        if (possible) {
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        points[i] = {double(i + 1), double(y)};
    }
    // double A = Y[i] - Y[0];
    // double B = 1 - (i + 1);
    // double C = A * 1 + B * Y[0];
    if (isPossible(points, 0, n) || isPossible(points, 1, n)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return EXIT_SUCCESS;
}
