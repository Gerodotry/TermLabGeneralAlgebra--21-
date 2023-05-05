//
// Created by Sasha on 05.05.2023.
//

#include "algorithms/Gcd.h"

vector<int> Gcd:: divisionCoefs;
int Gcd::sub_poly(int *p, int *q, int len,int mod) {
    int coeff;
    int  zero_count = 0;
    int  i;
    //  coeff = p[0] / q[0];     // при умножении на этот коэффициент убивается старший коэфф.
    for (int x = 0; x < mod; x++) {
        if ((q[0] * x) % mod == p[0]) {
            coeff = x;
          divisionCoefs.push_back(coeff);

        }
    }
    p[0] = 0;
    for (i = 1; i < len; i++)
        p[i] = ((p[i] - (coeff * q[i])%mod)+mod)%mod;
    while (p[zero_count] == 0)
        zero_count++;

    return zero_count;
}

vector<int> Gcd::subtract_polys(vector<int> poly1, vector<int> poly2, int mod) {
    int len1 = poly1.size();
    int len2 = poly2.size();
    int* poly11 = new int[len1];
    int* poly22 = new int[len1];
    for (int k = 0; k < len1; k++) {
        poly11[k] = poly1[k];
    }
    for (int k = 0; k < len2; k++) {
        poly22[k] = poly2[k];
    }
    int    i;
    int coeff;
    int    zero_count;
    i = 0;
    while ((len1 - i) >= len2)     // пока еще возможно разделить остаток на делитель
    {
        zero_count = sub_poly(poly11 + i, poly22, len2,mod);   // вычитаем коэффициенты
        i += zero_count;
    }
    vector<int>r;
    for (i; i < len1; i++) r.push_back(poly11[i]);
    // if (r.size() == 0) r.push_back(0);
    return r;
}

vector<int> Gcd::gcd(vector<int> a, vector<int> b,int mod) {
    while (!b.empty()) {
        /*for (int i = 0; i < a.size(); i++) {
            cout << a[i] << "x^" << a.size() - i - 1;
            if (i < a.size() - 1) cout << " + ";
        }
        cout << ", ";
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << "x^" << b.size() - i - 1;
            if (i < b.size() - 1) cout << " + ";
        }
        cout << ") = ";
        cout << endl;*/
        vector<int> r = subtract_polys(a, b,mod);
        a = b;
        b = r;
    }
    return a;
}
vector<int> Gcd::division(vector<int> poly1, vector<int> poly2, int mod) {
    divisionCoefs.clear();
    int len1 = poly1.size();
    int len2 = poly2.size();
    int* poly11 = new int[len1];
    int* poly22 = new int[len1];
    for (int k = 0; k < len1; k++) {
        poly11[k] = poly1[k];
    }
    for (int k = 0; k < len2; k++) {
        poly22[k] = poly2[k];
    }
    int    i;
    int coeff;
    int    zero_count;
    i = 0;
    while ((len1 - i) >= len2)     // пока еще возможно разделить остаток на делитель
    {

        zero_count = sub_poly(poly11 + i, poly22, len2,mod);   // вычитаем коэффициенты
        i += zero_count;
    }
    return divisionCoefs;
}
