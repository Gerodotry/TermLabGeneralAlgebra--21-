//
// Created by Dklishch on 6/1/2023.
//

#ifndef LAB_ISGROUPGENERATORALGORITHM_H
#define LAB_ISGROUPGENERATORALGORITHM_H

#include "Algorithm.h"
#include "utils/Bool.h"

class IsGroupGeneratorAlgorithm : public Algorithm {
public:
    IsGroupGeneratorAlgorithm();

    std::string getName() const override;

    virtual Object* run() override;
private:
    Bool result;
};


#endif //LAB_ISGROUPGENERATORALGORITHM_H
