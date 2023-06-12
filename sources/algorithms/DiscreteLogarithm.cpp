//
// Created by sofia on 11.06.2023.
//

#include "algorithms/DiscreteLogarithm.h"
#include "algorithms/Gcd.h"
#include <cmath>
#include <unordered_map>

using namespace std;

//int DiscreteLogarithm::discrete_logarithm(int a, int b, int m) {
//    int n = (int) sqrt (m) + 1;
//    int an = 1;
//    unordered_map<int, int> value;
//    for (int i = 0; i < n; ++i)
//        an = (an * a) % m;
//    for (int i = 1, cur = an; i <= n; ++i) {
//        if (!value.count(cur))
//            value[cur] = i;
//        cur = (cur * an) % m;
//    }
//    for (int i = 0, cur = b; i <= n; ++i) {
//        if (value.count(cur)) {
//            int ans = value[cur] * n - i;
//            if (ans < m)
//                return ans;
//        }
//        cur = (cur * a) % m;
//    }
//    return -1;
//}

#include <iostream>
#include <numeric>


long long DiscreteLogarithm::discrete_logarithm(long a, long b, long m) {

     auto gcd = std::gcd(a,m);

    if (gcd > 1) {
        return -1;
    }

    a %= m, b %= m;
    long long n = sqrt(m) + 1;

    long long an = 1;
    for (long long i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<long long, long long> vals;
    for (long long q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (long long p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            long long ans = n * p - vals[cur];
            return ans;
        }
    }

    return -1;
}



