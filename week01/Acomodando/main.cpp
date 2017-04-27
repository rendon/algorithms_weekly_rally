/* Copyright 2017 Rafael Rendón Pablo <rafaelrendonpablo@gmail.com> */
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
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& number : numbers) {
        cin >> number;
    }
    int position = 0;
    int k = numbers[0];
    for (int number : numbers) {
        if (number < k) {
            position++;
        }
    }
    cout << position << endl;
    return EXIT_SUCCESS;
}
