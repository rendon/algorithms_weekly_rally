/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <cmath>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
const int kMax      = 200000 + 5;
const int kInf = 1 << 30;
// endregion

struct Element {
    int value;
    int frequency;
    int start;
    int end;
};

Element A[kMax];
int T[2*kMax];

void buildTree(int node, int a, int b) {
    if (a == b) {
        T[node] = A[a].frequency;
        return;
    }
    int mid = (a + b) / 2;
    int l = 2 * node;
    int r = 2 * node + 1;
    buildTree(l, a, mid);
    buildTree(r, mid + 1, b);
    T[node] = std::max(T[l], T[r]);
}

int query(int node, int a, int b, int i, int j) {
    if (j < i) {
        return -kInf;
    }
    if (i > b || j < a) {
        return -kInf;
    }
    if (i <= a && b <= j) {
        return T[node];
    }
    int mid = (a + b) / 2;
    int l = 2 * node;
    int r = 2 * node + 1;
    return std::max(query(l, a, mid, i, j), query(r, mid + 1, b, i, j));
}

int solve(int a, int b, int n) {
    int x = query(1, 0, n - 1, A[a].end + 1, A[b].start - 1);
    int l = std::min(A[a].end + 1, b + 1) - a;
    int r = b - std::max(A[b].start - 1, a - 1);
    return std::max(x, std::max(l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> q;
        for (int i = 0; i < n; i++) {
            cin >> A[i].value;
        }
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && A[j].value == A[i].value) {
                A[j++].start = i;
            }
            i = j;
        }
        for (int i = n - 1; i >= 0; ) {
            int j = i;
            while (j >= 0 && A[j].value == A[i].value) {
                A[j--].end = i;
            }
            i = j;
        }
        for (int i = 0; i < n; ) {
            int f = A[i].end - A[i].start + 1;
            int j = i;
            while (j < n && A[j].value == A[i].value) {
                A[j++].frequency = f;
            }
            i = j;
        }
        // for (int i = 0; i < n; i++) {
        //     cout << A[i].value << " S: " << A[i].start << " E: " << A[i].end << " F: " << A[i].frequency << endl;
        // }
        buildTree(1, 0, n - 1);
        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            cout << solve(a - 1, b - 1, n) << "\n";
        }
    }
    return EXIT_SUCCESS;
}
