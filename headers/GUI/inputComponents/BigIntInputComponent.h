//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_BIGINTINPUTCOMPONENT_H
#define LAB_BIGINTINPUTCOMPONENT_H


#include "InputComponent.h"
#include "utils/BigInt.h"

class BigIntInputComponent: public InputComponent {
public:
    explicit BigIntInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    int count = 1;

    std::string numberString = std::string(1024, '.');

    BigInt number;
};


#endif //LAB_BIGINTINPUTCOMPONENT_H
