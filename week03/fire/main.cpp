/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
// Problem: Fire (http://coj.uci.cu/24h/problem.xhtml?pid=1647)
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
const int kImpossible = -1;
const char kFire = 'F';
const char kJoe = 'J';
const char kEmpty = '.';
// endregion

struct State {
    int row;
    int col;
    int time;
    char type;
};

queue<State> enqueueInitialState(vector<string>& maze) {
    queue<State> Q;
    int R = maze.size();
    int C = maze[0].length();

    // Add Joe first
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (maze[r][c] == kJoe) {
                Q.push({r, c, 0, kJoe});
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (maze[r][c] == kFire) {
                Q.push({r, c, 0, kFire});
            }
        }
    }
    return Q;
}

int simulate(vector<string>& maze) {
    int rowDelta[] = {-1, 0, 1, 0};
    int colDelta[] = {0, 1, 0, -1};
    int R = maze.size();
    int C = maze[0].length();
    queue<State> Q = enqueueInitialState(maze);

    while (!Q.empty()) {
        State s = Q.front();
        Q.pop();
        if (s.type == kJoe) {
            // This cell was reached by the fire at the same time Jod did
            if (maze[s.row][s.col] != kJoe) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int row = s.row + rowDelta[i];
                int col = s.col + colDelta[i];
                if (row < 0 || row >= R || col < 0 || col >= C) {
                    return s.time + 1;
                }
                if (maze[row][col] == kEmpty) {
                    maze[row][col] = kJoe;
                    Q.push({row, col, s.time + 1, kJoe});
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int row = s.row + rowDelta[i];
                int col = s.col + colDelta[i];
                if (row < 0 || row >= R || col < 0 || col >= C) {
                    continue;
                }

                // The fire can occupy a cell with Joe in it, it's the fire!
                if (maze[row][col] == kEmpty || maze[row][col] == kJoe) {
                    maze[row][col] = kFire;
                    Q.push({row, col, s.time + 1, kFire});
                }
            }
        }
    }
    return kImpossible;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> maze(R);
    for (string& row : maze) {
        cin >> row;
    }
    int earliestTime = simulate(maze);
    if (earliestTime == kImpossible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << earliestTime << endl;
    }
    return EXIT_SUCCESS;
}
