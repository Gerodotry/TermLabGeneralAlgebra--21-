//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_INPUTCOMPONENT_H
#define MAIN_CPP_INPUTCOMPONENT_H


#include "utils/Object.h"
#include <string>

class InputComponent {
public:
    InputComponent(std::string name);

    virtual Object* getObject() = 0;

    virtual void createInputWindow() = 0;

    virtual bool isInputValid() = 0;
protected:
    std::string name;
};


#endif //MAIN_CPP_INPUTCOMPONENT_H
