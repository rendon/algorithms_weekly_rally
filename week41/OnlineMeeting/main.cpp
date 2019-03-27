/* Copyright 2018 Rafael Rendon Pablo <rafaelrendonpablo@gmail.com> */
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
const int kInf      = INT32_MAX;

inline void __enable_fast_input() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

inline int readInt() {
    int x = 0;
    std::cin >> x;
    return x;
}

inline int64 readLong() {
    int64 x = 0;
    std::cin >> x;
    return x;
}

inline string readString() {
    string str;
    std::cin >> str;
    return str;
}
// endregion

enum EventType {
    LogOn,
    LogOff
};

struct Event {
    EventType type;
    int id;
};

void printSolution(const set<int>& canBeLeader) {
    std::cout << canBeLeader.size() << std::endl;
    for (int id : canBeLeader) {
        std::cout << id + 1 << " ";
    }
    std::cout << std::endl;
}

int main() {
    __enable_fast_input();
    int n = readInt();
    int m = readInt();
    vector<Event> events;
    for (int i = 0; i < m; i++) {
        string type = readString();
        int id = readInt() - 1;
        if (type == "-") {
            events.push_back({EventType::LogOff, id});
        } else {
            events.push_back({EventType::LogOn, id});
        }
    }

    // Find those guys who where in the meeting all the time
    vector<bool> present(n, true);
    for (Event& e : events) {
        present[e.id] = false;
    }
    set<int> in;
    set<int> canBeLeader;
    set<int> canNotBeLeader;
    for (Event& e : events) {
        if (e.type == EventType::LogOff) {
            in.erase(e.id);
            if (in.empty()) {
                canBeLeader.insert(e.id);
            }
        } else {
            in.insert(e.id);
        }
    }

    in.clear();
    for (int i = 0; i < n; i++) {
        if (present[i]) {
            in.insert(i);
            canBeLeader.insert(i);
        }
    }

    for (Event& e : events) {
        if (e.type == EventType::LogOff) {
            in.erase(e.id);
            if (in.empty()) {
                canBeLeader.insert(e.id);
            }
        } else {
            in.insert(e.id);
        }
    }

    printSolution(canBeLeader);
    return EXIT_SUCCESS;
}
