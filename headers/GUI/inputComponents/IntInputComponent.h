//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_IntInputComponent_H
#define MAIN_CPP_IntInputComponent_H


#include "InputComponent.h"

class IntInputComponent: public InputComponent {
public:
    explicit IntInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    int value;
};


#endif //MAIN_CPP_IntInputComponent_H
