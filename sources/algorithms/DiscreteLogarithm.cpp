//
// Created by sofia on 11.06.2023.
//

#include "algorithms/DiscreteLogarithm.h"
#include <cmath>
#include <unordered_map>

using namespace std;

int DiscreteLogarithm::discrete_logarithm(int a, int b, int m) {
    int n = (int) sqrt (m) + 1;
    int an = 1;
    unordered_map<int, int> value;
    for (int i = 0; i < n; ++i)
        an = (an * a) % m;
    for (int i = 1, cur = an; i <= n; ++i) {
        if (!value.count(cur))
            value[cur] = i;
        cur = (cur * an) % m;
    }
    for (int i = 0, cur = b; i <= n; ++i) {
        if (value.count(cur)) {
            int ans = value[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}