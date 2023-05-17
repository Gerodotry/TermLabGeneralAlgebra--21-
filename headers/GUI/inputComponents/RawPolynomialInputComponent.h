//
// Created by Dklishch on 5/8/2023.
//

#ifndef LAB_RAWPOLYNOMIALINPUTCOMPONENT_H
#define LAB_RAWPOLYNOMIALINPUTCOMPONENT_H


#include "InputComponent.h"
#include "utils/RawPolynomial.h"

class RawPolynomialInputComponent: public InputComponent {
public:
    explicit RawPolynomialInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    int count = 1;

    std::string degrees = std::string(2048, '.');
    std::string coefficients = std::string(2048, '.');

    RawPolynomial polynomial;
};


#endif //LAB_RAWPOLYNOMIALINPUTCOMPONENT_H
