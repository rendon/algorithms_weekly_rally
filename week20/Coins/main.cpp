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
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const double kEps   = 10e-8;
const int kMax      = 1000;
const int kInf      = 1 << 30;
// endregion

inline int f(char c) {
    return c - 'A';
}

int main() {
    bool graph[3][3];
    memset(graph, false, sizeof graph);
    for (int i = 0; i < 3; i++) {
        string relationship;
        cin >> relationship;
        int u = f(relationship[0]);
        int v = f(relationship[2]);
        if (relationship[1] == '>') {
            graph[u][v] = true;
        } else {
            graph[v][u] = true;
        }
    }
    vector<int> A(3);
    std::iota(A.begin(), A.end(), 0);
    bool possible = false;
    do {
        int a = A[0];
        int b = A[1];
        int c = A[2];
        if (graph[a][b] && graph[a][c] && graph[b][c]) {
            possible = true;
            cout << char(c + 'A') << char(b + 'A') << char(a + 'A') << endl;
            break;
        }
    } while (std::next_permutation(A.begin(), A.end()));
    if (!possible) {
        cout << "Impossible" << endl;
    }
    return EXIT_SUCCESS;
}
