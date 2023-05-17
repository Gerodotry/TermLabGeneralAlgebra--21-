//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_GCDALGORITHM_H
#define LAB_GCDALGORITHM_H

#include "Algorithm.h"
#include "utils/RawPolynomial.h"

class GcdAlgorithm : public Algorithm {
public:
    GcdAlgorithm();

    std::string getName() const override;

    virtual Object *run() override;
private:
    RawPolynomial result;
};


#endif //LAB_GCDALGORITHM_H
