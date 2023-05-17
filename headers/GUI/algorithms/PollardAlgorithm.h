//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_POLLARDALGORITHM_H
#define LAB_POLLARDALGORITHM_H

#include "Algorithm.h"
#include "utils/NumberFactors.h"

class PollardAlgorithm : public Algorithm {
public:
    PollardAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    NumberFactors result;
};


#endif //LAB_POLLARDALGORITHM_H
