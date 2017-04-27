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

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<string> ingredients(4);
        for (string& ing : ingredients) {
            cin >> ing;
        }
        int count = 0;
        for (int i = 0; i < 4; i++) {
            string ing;
            cin >> ing;
            auto it = std::find(ingredients.begin(), ingredients.end(), ing);
            if (it != ingredients.end()) {
                count++;
            }
        }
        if (count >= 2) {
            cout << "similar\n";
        } else {
            cout << "dissimilar\n";
        }
    }
    return EXIT_SUCCESS;
}
