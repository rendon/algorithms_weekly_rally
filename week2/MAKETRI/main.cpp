/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const char TYPE_START = 'A';
const char TYPE_END = 'Z';
// endregion

struct Point {
    uint64 value;
    char type;
    Point() { }
    Point(uint64 v, char t) : value(v), type(t) {
    }

    bool operator<(const Point& that) const {
        if (this-> value != that.value) {
            return this->value < that.value;
        }
        return this->type < that.type;
    }
};

uint64 f(uint64 a, uint64 b, uint64 l, uint64 r) {
    // cout << a << " " << b << " : " << l << " " << r << endl;
    if (b < l || r < a) {
        return 0;
    }

    if (a >= l && b <= r) {
        return b - a + 1;
    }

    if (l >= a && r <= b) {
        return r - l + 1;
    }

    if (a < l) {
        return b - l + 1;
    }
    return r - a + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64 N, L, R;
    
    cin >> N >> L >> R;
    vector<uint64> A(N);
    for (uint64& a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    vector<Point> points;
    for (int i = 1; i < int(A.size()); i++) {
        uint64 y = A[i];
        uint64 x = A[i-1];
        points.push_back(Point(y - x + 1, TYPE_START));
        points.push_back(Point(y + x - 1, TYPE_END));
    }
    sort(points.begin(), points.end());
    uint64 ans = 0;
    int count = 0;
    uint64 prev = -1;
    for (Point& point : points) {
        // cout << point.value << ", ";
        if (point.type == TYPE_START) {
            if (count == 0) {
                prev = point.value;
            }
            count++;
        } else {
            count--;
            if (count == 0) {
                ans += f(prev, point.value, L, R);
            }
        }
    }
    // cout << endl;
    cout << ans << endl;
    return EXIT_SUCCESS;
}
