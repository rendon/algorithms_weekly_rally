/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// region Template
#include <iostream>
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

using namespace std;
typedef long long           int64;
typedef unsigned long long  uint64;
// endregion

// const int kMax = 1002;
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int R, O, Y, G, B, V;
        cin >> N;
        cin >> R >> O >> Y >> G >> B >> V;
        cout << "Case #" << tc << ": ";
        vector<pair<int, char>> colors{{R, 'R'}, {Y, 'Y'}, {B, 'B'}};
        std::sort(colors.begin(), colors.end());
        vector<char> row(N, '.');
        bool possible = true;
        for (int i = 0; i < N && colors[0].first > 0; i += 2) {
            row[i] = colors[0].second;
            colors[0].first--;
        }
        int j = 0;
        for (int i = N - 1; i >= 0 && row[i] == '.'; i--) {
            if (j % 2 == 1) {
                if (colors[1].first == 0) {
                    possible = false;
                }
                row[i] = colors[1].second;
                colors[1].first--;
            } else {
                if (colors[2].first == 0) {
                    possible = false;
                }
                row[i] = colors[2].second;
                colors[2].first--;
            }
            j++;
        }
        for (int i = 0; i < N && possible; i++) {
            if (row[i] == '.') {
                if (colors[1].first == 0 && colors[2].first == 0) {
                    possible = false;
                }
                if (colors[1].first > 0) {
                    row[i] = colors[1].second;
                    colors[1].first--;
                } else {
                    row[i] = colors[2].second;
                    colors[2].first--;
                }
            }
        }
        int reds = 0;
        int yellows = 0;
        int blues = 0;
        for (char c : row) {
            if (c == 'R') {
                reds++;
            } else if (c == 'Y') {
                yellows++;
            } else {
                blues++;
            }
        }
        possible &= (reds == R && yellows == Y && blues == B);
        for (int i = 0; i < N; i++) {
            if (row[i] == row[(i+1)%N]) {
                possible = false;
            }
        }
        if (!possible) {
            cout << "IMPOSSIBLE";
        } else {
            for (char c : row) {
                cout << c;
            }
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
