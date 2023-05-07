//
// Created by Sasha on 07.05.2023.
//

#ifndef LAB_REMAINDER_H
#define LAB_REMAINDER_H
#include <iostream>
#include <vector>

using namespace std;

class Remainder {
public:
    static int sub_poly(int* p, int* q, int len,int mod);
    static vector<int> subtract_polys(vector<int> poly1,  vector<int> poly2, int mod);
    static vector<int> run(vector<int> poly1,  vector<int> poly2, int mod);
};


#endif //LAB_REMAINDER_H
