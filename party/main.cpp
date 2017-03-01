/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <numeric>

#include <cstring>
#include <cctype>
using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// endregion

class DisjointSetUnion {
public:
    DisjointSetUnion() { }
    DisjointSetUnion(int n) {
        id_ = vector<int>(n);
        iota(id_.begin(), id_.end(), 0);
        size_ = vector<int>(n, 0);
    }

    int root(int u) {
        while (id_[u] != u) {
            u = id_[u];
        }
        return u;
    }

    void connect(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) {
            return;
        }
        if (size_[a] < size_[b]) {
            id_[a] = b;
            size_[b] += size_[a];
        } else {
            id_[b] = a;
            size_[a] += size_[b];
        }
    }

    int countGroups() {
        map<int, bool> groups;
        for (int u = 0; u < int(id_.size()); u++) {
            groups[root(u)] = true;
        }
        return groups.size();
    }
private:
    vector<int> id_;
    vector<int> size_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    DisjointSetUnion dsu(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        dsu.connect(A - 1, B - 1);
    }
    if (dsu.countGroups() == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return EXIT_SUCCESS;
}
