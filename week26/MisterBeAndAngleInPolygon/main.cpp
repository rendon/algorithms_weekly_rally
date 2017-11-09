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
const double kLen = 10;
// endregion

const double kPi = std::acos(-1);
struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}

double angle(Point o, Point l, Point r, double target) {
    double a = dist(l, r);
    double c = dist(o, l);
    double b = dist(o, r);
    double alfa = std::acos((b * b + c * c - a * a) / (2 * b * c));
    double degrees = alfa * 180 / kPi;
    return std::abs(degrees - target);
}

int main() {
    int n, target;
    std::cin >> n >> target;
    double theta = 2 * kPi / n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
        double x = kLen * std::cos(-i * theta);
        double y = kLen * std::sin(-i * theta);
        points.push_back({x, y});
    }

    double best = 1e12;
    int b = -1, c = -1;
    for (int i = 1; i + 1 < 3; i++) {
        int low = i + 1;
        int high = n;
        while (low < high) {

            if (high - low < 15) {
                for (int j = low; j < high; j++) {
                    double alfa = angle(points[0], points[i], points[j], target);
                    if (alfa < best) {
                        best = alfa;
                        b = i;
                        c = j;
                    }
                }
                break;
            }


            int t = (high - low) / 3;
            int x = low + t;
            int y = low + t + t;

            double alfa = angle(points[0], points[i], points[x], target);
            if (alfa < best) {
                best = alfa;
                b = i;
                c = x;
            }
            double beta = angle(points[0], points[i], points[y], target);
            if (beta < best) {
                best = beta;
                b = i;
                c = y;
            }

            if (alfa < beta) {
                high -= t;
            } else {
                low += t;
            }

            if (t == 0) {
                break;
            }
        }
    }

    std::cout << b + 1 << " " << 1 << " " << c + 1 << std::endl;
    return EXIT_SUCCESS;
}
