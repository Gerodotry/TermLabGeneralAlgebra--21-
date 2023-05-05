//
// Created by Sasha on 05.05.2023.
//

#ifndef LAB_GCD_H
#define LAB_GCD_H
#include <iostream>
#include <vector>

using namespace std;

class Gcd {
public:
    static int sub_poly(int* p, int* q, int len,int mod);
    static vector<int> subtract_polys(vector<int> poly1,  vector<int> poly2, int mod);
    static vector<int> gcd(vector<int> a, vector<int> b,int mod);
    static vector<int>division( vector<int> poly1, vector<int> poly2, int mod);
    static vector<int>divisionCoefs;
};


#endif //LAB_GCD_H
