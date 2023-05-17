//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_PolynomialInputComponent_H
#define MAIN_CPP_PolynomialInputComponent_H


#include "InputComponent.h"
#include "utils/Int.h"
#include "utils/FieldPolynomial.h"

class FieldPolynomialInputComponent: public InputComponent {
public:
    explicit FieldPolynomialInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    int count = 1;

    std::string degrees = std::string(2048, 0);
    std::string coefficients = std::string(2048, 0);

    FieldPolynomial polynomial;
};


#endif //MAIN_CPP_PolynomialInputComponent_H
