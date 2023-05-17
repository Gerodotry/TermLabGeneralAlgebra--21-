//
// Created by Dklishch on 5/9/2023.
//

#ifndef LAB_EUCLIDRESULT_H
#define LAB_EUCLIDRESULT_H


#include "FieldPolynomial.h"

class EuclidResult: public Object {
public:
    FieldPolynomial gcd;
    FieldPolynomial a;
    FieldPolynomial b;

    std::string toString() override;
};


#endif //LAB_EUCLIDRESULT_H
