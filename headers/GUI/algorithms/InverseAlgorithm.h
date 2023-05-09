//
// Created by mac on 08.05.2023.
//

#ifndef LAB_INVERSEALGORITHM_H
#define LAB_INVERSEALGORITHM_H



#include "Algorithm.h"
#include "utils/Number.h"

class InverseAlgorithm : public Algorithm {
public:
    InverseAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Number result;
};


#endif //LAB_INVERSEALGORITHM_H
