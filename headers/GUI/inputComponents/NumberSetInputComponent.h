//
// Created by Dklishch on 6/1/2023.
//

#ifndef LAB_NUMBERSETINPUTCOMPONENT_H
#define LAB_NUMBERSETINPUTCOMPONENT_H

#include "InputComponent.h"
#include "utils/NumberSet.h"

class NumberSetInputComponent : public InputComponent {
public:
    explicit NumberSetInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    NumberSet numbers;

    std::string numbersString = std::string(1024, 0);
};
#endif //LAB_NUMBERSETINPUTCOMPONENT_H
