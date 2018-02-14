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

const int kMine = kInf;
const int kSeen = kInf - 1;

void solve(vector<vector<int>>& grid, int M, int tc) {
    int R = grid.size();
    int C = grid[0].size();

    int zeros = 0;
    int r, c;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 0) {
                zeros++;
                r = i;
                c = j;
            }
        }
    }

    std::cout << "Case #" << tc << ":\n";
    if (M + 1 == R * C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == kMine) {
                    std::cout << "*";
                } else {
                    std::cout << "c";
                }
            }
            std::cout << "\n";
        }
        return;
    }

    if (zeros == 0) {
        std::cout << "Impossible\n";
        return;
    }

    queue<std::pair<int, int>> Q;
    Q.push({r, c});
    grid[r][c] = kSeen;
    while (!Q.empty()) {
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) {
                    continue;
                }
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    if (grid[nr][nc] == kMine) {
                        continue;
                    }
                    if (grid[nr][nc] == 0) {
                        Q.push({nr, nc});
                    }
                    grid[nr][nc] = kSeen;
                }
            }
        }
    }

    int unseen = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] != kMine && grid[i][j] != kSeen) {
                unseen++;
            }
        }
    }
    if (unseen > 0) {
        std::cout << "Impossible\n";
        return;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == kMine) {
                std::cout << "*";
            } else if (i == r && j == c) {
                std::cout << "c";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int R, C, M;
        std::cin >> R >> C >> M;
        vector<vector<int>> grid(R, vector<int>(C));


        int top = 0;
        int bottom = R;
        int left = 0;
        int right = C;
        while (M > 0) {
            for (int j = left; j < right && M > 0; j++) {
                grid[top][j] = kMine;
                M--;
            }
            for (int i = top + 1; i < bottom && M > 0; i++) {
                grid[i][right-1] = kMine;
                M--;
            }
            for (int j = right - 2; j >= left && M > 0; j--) {
                grid[bottom-1][j] = kMine;
                M--;
            }
            for (int i = bottom - 2; i > top && M > 0; i--) {
                grid[i][left] = kMine;
                M--;
            }
            top++;
            right--;
            bottom--;
            left++;
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == kMine) {
                    continue;
                }
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0) {
                            continue;
                        }
                        int r = i + dr;
                        int c = j + dc;
                        if (r >= 0 && r < R && c >= 0 && c < C) {
                            if (grid[r][c] == kMine) {
                                grid[i][j]++;
                            }
                        }
                    }
                }
            }
        }

       solve(grid, M, tc);
    }
    return EXIT_SUCCESS;
}
