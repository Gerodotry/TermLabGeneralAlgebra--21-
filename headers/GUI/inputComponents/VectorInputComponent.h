//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_VECTORINPUTCOMPONENT_H
#define MAIN_CPP_VECTORINPUTCOMPONENT_H


#include "InputComponent.h"
#include "utils/Vector.h"

class VectorInputComponent: public InputComponent {
public:
    explicit VectorInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    float values[3] = {0, 0, 0};
};


#endif //MAIN_CPP_VECTORINPUTCOMPONENT_H
