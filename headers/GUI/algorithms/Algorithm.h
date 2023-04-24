//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_ALGORITHM_H
#define MAIN_CPP_ALGORITHM_H

#include <vector>
#include "utils/Object.h"
#include "GUI/InputComponents/InputComponent.h"

class Algorithm {
public:
    virtual std::string getName() const = 0;

    virtual Object* run() = 0;

    virtual std::vector<InputComponent*> getTypes() const = 0;
};

#endif //MAIN_CPP_ALGORITHM_H
