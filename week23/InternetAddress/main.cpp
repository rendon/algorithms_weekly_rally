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

int main() {
    string S;
    std::cin >> S;
    string url;
    int pos = 0;
    if (S[0] == 'h') {
        url = "http://";
        pos = 4;
    } else {
        url = "ftp://";
        pos = 3;
    }

    string domain;
    domain += S[pos];
    pos++;
    while (pos + 1 < int(S.length())) {
        if (S[pos] == 'r' && S[pos+1] == 'u') {
            std::cout << url + domain + ".ru";
            pos += 2;
            if (pos < int(S.length())) {
                std::cout << "/";
                while (pos < int(S.length())) {
                    std::cout << S[pos++];
                }
            }
            break;
        } else {
            domain += S[pos++];
        }
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
