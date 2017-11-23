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

class Solver {
public:
    Solver() { }
    Solver(int H, int W, vector<vector<int>> heights) {
        this->H = H;
        this->W = W;
        this->heights = heights;
        graph = vector<vector<int>>(H, vector<int>(W, -1));
    }

    void solve() {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                dfs(i, j);
            }
        }

        char label = 'a';
        map<int, char> idToLabel;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int id = graph[i][j];
                // std::cout << id << " ";
                if (idToLabel.count(id) == 0) {
                    idToLabel[id] = label++;
                }
            }
            // std::cout << std::endl;
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                std::cout << idToLabel[graph[i][j]] << " ";
            }
            std::cout << std::endl;
        }
    }
private:
    int H, W;
    int nextId = 1;
    vector<vector<int>> heights;
    vector<vector<int>> graph;

    int dfs(int r, int c) {
        if (graph[r][c] != -1) {
            return graph[r][c];
        }
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        int minHeight = kInf;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
                continue;
            }
            minHeight = std::min(minHeight, heights[nr][nc]);
        }
        int h = heights[r][c];
        if (h <= minHeight) {
            graph[r][c] = nextId++;
            // std::cout << "h = " << h << " minHeight = " << minHeight << " x =" << x << std::endl;
            return graph[r][c];
        }

        // std::cout << "minHeight = " << minHeight << std::endl;
        int id = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
                continue;
            }
            if (heights[nr][nc] == minHeight) {
                id = dfs(nr, nc);
                // std::cout << "h = " << h << " (" << r << ", " << c << ") v = " << heights[nr][nc] << " id = " << id << std::endl;
                graph[r][c] = id;
                break;
            }
        }
        return id;
    }
};


int main() {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int H, W;
        std::cin >> H >> W;
        vector<vector<int>> heights(H, vector<int>(W));
        for (vector<int>& row : heights) {
            for (int& cell : row) {
                std::cin >> cell;
            }
        }
        Solver solver(H, W, heights);
        std::cout << "Case #" << tc << ":" << std::endl;
        solver.solve();
    }
    return EXIT_SUCCESS;
}
