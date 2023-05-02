//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_NUMBERINPUTCOMPONENT_H
#define MAIN_CPP_NUMBERINPUTCOMPONENT_H


#include "InputComponent.h"

class NumberInputComponent: public InputComponent {
public:
    explicit NumberInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    std::string number = std::string(1024, '.');
};


#endif //MAIN_CPP_VECTORINPUTCOMPONENT_H
