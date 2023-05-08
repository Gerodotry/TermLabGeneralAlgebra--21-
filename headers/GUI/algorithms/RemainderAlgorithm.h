//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_REMAINDERALGORITHM_H
#define LAB_REMAINDERALGORITHM_H

#include "Algorithm.h"
#include "utils/RawPolynomial.h"

class RemainderAlgorithm: public Algorithm {
public:
    RemainderAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    RawPolynomial result;
};


#endif //LAB_REMAINDERALGORITHM_H
