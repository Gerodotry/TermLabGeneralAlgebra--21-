//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_POLYNOMIALFASTPOWERING_H
#define LAB_POLYNOMIALFASTPOWERING_H


#include "PolynomialMultiplication.h"

class PolynomialFastPowering {
public:
    template<class T>
    static T run(const T& Polynomial, int n, int module);
};

template<class T>
T PolynomialFastPowering::run(const T& Polynomial, int n, int module) {
    if (n == 0) return T({{0, 1}});
    else if (n == 1) return Polynomial;
    else if (n % 2) {
        T A = run(Polynomial, n / 2, module);
        T AA = PolynomialMultiplication::run(A, A, module);
        return PolynomialMultiplication::run(AA, Polynomial, module);
    } else {
        T A = run(Polynomial, n / 2, module);
        return PolynomialMultiplication::run(A, A, module);
    }
}


#endif //LAB_POLYNOMIALFASTPOWERING_H
