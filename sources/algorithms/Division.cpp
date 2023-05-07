//
// Created by Sasha on 07.05.2023.
//

#include "algorithms/Division.h"

vector<int> Division::divisionCoefs;

int Division::sub_poly(int *p, int *q, int len, int mod) {
    int coeff;
    int zero_count = 0;
    int i;
    //  coeff = p[0] / q[0];     // при умножении на этот коэффициент убивается старший коэфф.
    for (int x = 0; x < mod; x++) {
        if ((q[0] * x) % mod == p[0]) {
            coeff = x;
            divisionCoefs.push_back(coeff);

        }
    }
    p[0] = 0;
    for (i = 1; i < len; i++)
        p[i] = ((p[i] - (coeff * q[i]) % mod) + mod) % mod;
    while (p[zero_count] == 0)
        zero_count++;

    return zero_count;
}

vector<int> Division::division(vector<int> poly1, vector<int> poly2, int mod) {
    divisionCoefs.clear();
    int len1 = poly1.size();
    int len2 = poly2.size();
    int *poly11 = new int[len1];
    int *poly22 = new int[len1];
    for (int k = 0; k < len1; k++) {
        poly11[k] = poly1[k];
    }
    for (int k = 0; k < len2; k++) {
        poly22[k] = poly2[k];
    }
    int i;
    int coeff;
    int zero_count;
    i = 0;
    while ((len1 - i) >= len2)     // пока еще возможно разделить остаток на делитель
    {
        zero_count = sub_poly(poly11 + i, poly22, len2, mod);   // вычитаем коэффициенты
        i += zero_count;
    }
    return divisionCoefs;
}

vector<int> Division::run(vector<int> poly1, vector<int> poly2, int mod) {
    vector<int> div = division(poly1, poly2, mod);
    return div;
}
