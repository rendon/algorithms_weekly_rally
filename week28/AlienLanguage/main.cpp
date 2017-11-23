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

const int kMaxN = 16 * 5001;
const int kMaxL = 16;
int dp[kMaxN][kMaxL];

struct Node {
    int id;
    char value;
    map<int, Node> next;
    Node() { }
    Node(int id, char value) {
        this->id = id;
        this->value = value;
    }
};

void addWord(Node& root, string& word, int pos, int& nextId) {
    if (pos >= int(word.size())) {
        return;
    }
    int k = word[pos] - 'a';
    if (root.next.count(k) == 0) {
        root.next[k] = Node(nextId++, word[pos]);
    }
    addWord(root.next[k], word, pos + 1, nextId);
}

/*
void dfs(Node& root, string str) {
    if (root.next.empty()) {
        std::cout << str << std::endl;
        return;
    }
    for (int k = 0; k < 26; k++) {
        if (root.next.count(k) == 1) {
            char ch = char(k + 'a');
            string ns = str;
            ns += ch;
            dfs(root.next[k], ns);
        }
    }
}
*/

int f(Node& root, int p, vector<string>& groups) {
    if (p >= int(groups.size())) {
        return 1;
    }
    int& ans = dp[root.id][p];
    if (ans != -1) {
        return ans;
    }

    ans = 0;
    for (char ch : groups[p]) {
        int k = ch - 'a';
        if (root.next.count(k) == 1) {
            ans += f(root.next[k], p + 1, groups);
        }
    }
    return ans;
}

int solve(Node& root, string pattern) {
    vector<string> groups;
    int size = pattern.length();
    for (int i = 0; i < size; ) {
        if (pattern[i] == '(') {
            int j;
            for (j = i + 1; j < size && pattern[j] != ')'; j++);
            groups.push_back(pattern.substr(i + 1, j - (i + 1)));
            i = j + 1;
        } else {
            groups.push_back(pattern.substr(i, 1));
            i++;
        }
    }
    memset(dp, -1, sizeof dp);
    return f(root, 0, groups);
}

int main() {
    int L, D, N;
    std::cin >> L >> D >> N;
    vector<string> words(D);
    int nextId = 0;
    Node root(nextId++, '.');
    for (string& word : words) {
        std::cin >> word;
        addWord(root, word, 0, nextId);
    }

    // dfs(root, "");
    for (int tc = 1; tc <= N; tc++) {
        string pattern;
        std::cin >> pattern;
        std::cout << "Case #" << tc << ": " << solve(root, pattern) << std::endl;
    }
    return EXIT_SUCCESS;
}
