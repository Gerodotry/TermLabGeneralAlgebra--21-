//
// Created by Sasha on 07.05.2023.
//

#ifndef LAB_DIVISION_H
#define LAB_DIVISION_H
#include <iostream>
#include <vector>

using namespace std;

class Division {
public:
    static int sub_poly(int* p, int* q, int len,int mod);
    static vector<int>division( vector<int> poly1, vector<int> poly2, int mod);
    static vector<int>divisionCoefs;
    static vector<int> run(vector<int> poly1, vector<int> poly2, int mod);
};


#endif //LAB_DIVISION_H
