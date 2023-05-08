//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_DIVISIONALGORITHM_H
#define LAB_DIVISIONALGORITHM_H

#include "Algorithm.h"
#include "utils/RawPolynomial.h"

class DivisionAlgorithm: public Algorithm {
public:
    DivisionAlgorithm();

    std::string getName() const override;

    virtual Object *run() override;
private:
    RawPolynomial result;
};


#endif //LAB_DIVISIONALGORITHM_H
