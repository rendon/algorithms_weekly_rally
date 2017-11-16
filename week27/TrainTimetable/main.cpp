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

const int kA2B = 1;
const int kB2A = 2;

struct Trip {
    int start, end, direction;

    Trip() { }
    Trip(string s, string e, int direction) {
        start = parse(s);
        end = parse(e);
        this->direction = direction;
    }

    int parse(string timestamp) {
        int hours = 10 * (timestamp[0] - '0') + (timestamp[1] - '0');
        int minutes = 10 * (timestamp[3] - '0') + (timestamp[4] - '0');
        return hours * 60 + minutes;
    }

    bool operator<(const Trip& that) const {
        if (this->start != that.start) {
            return this->start < that.start;
        }
        if (this->end != that.end) {
            return this->end < that.end;
        }
        return this->direction < that.direction;
    }
};

std::ostream& operator<<(std::ostream& os, const Trip& trip) {
    if (trip.direction == kA2B) {
        os << "--> ";
    } else {
        os << "<-- ";
    }
    os << trip.start << " " << trip.end;
    return os;
}

void solve(int tc, vector<Trip>& a2b, vector<Trip>& b2a, int T) {
    vector<Trip> trips;
    for (Trip trip : a2b) {
        trips.push_back(trip);
    }

    for (Trip trip : b2a) {
        trips.push_back(trip);
    }

    std::sort(trips.begin(), trips.end());
    std::priority_queue<int, vector<int>, std::greater<int>> A;
    std::priority_queue<int, vector<int>, std::greater<int>> B;
    int countA = 0;
    int countB = 0;
    for (Trip trip : trips) {
        if (trip.direction == kA2B) {
            if (!A.empty() && A.top() <= trip.start) {
                A.pop();
            } else {
                countA++;
            }
            B.push(trip.end + T);
        } else {
            if (!B.empty() && B.top() <= trip.start) {
                B.pop();
            } else {
                countB++;
            }
            A.push(trip.end + T);
        }
    }

    std::cout << "Case #" << tc << ": " << countA << " " << countB << std::endl;
}

int main() {
    int N;
    std::cin >> N;
    for (int tc = 1; tc <= N; tc++) {
        int T;
        std::cin >> T;
        int NA;
        std::cin >> NA;
        int NB;
        std::cin >> NB;
        vector<Trip> a2b;
        for (int i = 0; i < NA; i++) {
            string s, e;
            std::cin >> s >> e;
            a2b.push_back({s, e, kA2B});
        }

        vector<Trip> b2a;
        for (int i = 0; i < NB; i++) {
            string s, e;
            std::cin >> s >> e;
            b2a.push_back({s, e, kB2A});
        }
        solve(tc, a2b, b2a, T);
    }
    return EXIT_SUCCESS;
}
