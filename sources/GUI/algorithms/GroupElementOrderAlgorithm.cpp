//
// Created by Dklishch on 6/1/2023.
//

#include "GUI/algorithms/GroupElementOrderAlgorithm.h"
#include "GUI/inputComponents/NumberInputComponent.h"
#include "algorithms/GroupElementOrder.h"

std::string GroupElementOrderAlgorithm::getName() const {
    return "Group element order";
}

Object *GroupElementOrderAlgorithm::run() {
    Number *number = dynamic_cast<Number *>(dataTypes[0]->getObject());
    Number *module = dynamic_cast<Number *>(dataTypes[1]->getObject());
    result = GroupElementOrder::run(*number, *module);
    return &result;
}

GroupElementOrderAlgorithm::GroupElementOrderAlgorithm() {
    dataTypes = {
            std::make_shared<NumberInputComponent>("Number"),
            std::make_shared<NumberInputComponent>("Module")
    };
}