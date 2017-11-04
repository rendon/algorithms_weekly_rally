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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    // Make sure the ratios are irreducible fractions
    int g = gcd(a, b);
    a /= g;
    b /= g;

    g = gcd(c, d);
    c /= g;
    d /= g;

    // Try to use all the horizontal space available, otherwise use all the
    // vertical space available:
    // Let's define as c' = a, then d' = a / c * d, if d' <= b then we can use
    // all the horizontal space.
    //
    // Since we are using all the horizontal space, the ratio of used space is
    // simply d' / b = ((a * d) / c) / b = a * d / c * b
    //
    int num, den;
    if (double(a) / c * d <= b) {
        num = a * d;
        den = c * b;
    } else {
        num = b * c;
        den = d * a;
    }

    // Finally, since we are interested in the unused space, let's subtract to 1
    // the amount of used space, that is 1 - den/num = (den - num) / den
    num = den - num;
    int g = gcd(num, den);
    std::cout << num / g << "/" << den / g << std::endl;

    return EXIT_SUCCESS;
}
