#ifndef MAIN_CPP_FieldPolynomialDivisionAlgorithm_H
#define MAIN_CPP_FieldPolynomialDivisionAlgorithm_H

#include "Algorithm.h"
#include "utils/Number.h"
#include "utils/FieldPolynomial.h"

class FieldPolynomialDivisionAlgorithm : public Algorithm {
public:
    FieldPolynomialDivisionAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    FieldPolynomial result;
};


#endif //MAIN_CPP_FieldPolynomialDivisionAlgorithm_H
