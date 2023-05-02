//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_ALGORITHM_H
#define MAIN_CPP_ALGORITHM_H

#include <vector>
#include <memory>
#include "utils/Object.h"
#include "GUI/InputComponents/InputComponent.h"

class Algorithm {
public:
    virtual std::string getName() const = 0;

    virtual Object* run() = 0;

    virtual const std::vector<std::shared_ptr<InputComponent>>& getTypes() const { return dataTypes; }
protected:
    std::vector<std::shared_ptr<InputComponent>> dataTypes;
};

#endif //MAIN_CPP_ALGORITHM_H
