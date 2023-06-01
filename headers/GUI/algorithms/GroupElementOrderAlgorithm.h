//
// Created by Dklishch on 6/1/2023.
//

#ifndef LAB_GROUPELEMENTORDERALGORITHM_H
#define LAB_GROUPELEMENTORDERALGORITHM_H

#include "Algorithm.h"
#include "utils/Long.h"

class GroupElementOrderAlgorithm : public Algorithm {
public:
    GroupElementOrderAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Long result;
};

#endif //LAB_GROUPELEMENTORDERALGORITHM_H
