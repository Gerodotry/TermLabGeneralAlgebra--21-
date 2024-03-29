//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_RingPolynomialInputComponent_H
#define MAIN_CPP_RingPolynomialInputComponent_H


#include "InputComponent.h"
#include "utils/Int.h"
#include "utils/RingPolynomial.h"

class RingPolynomialInputComponent: public InputComponent {
public:
    explicit RingPolynomialInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    int count = 1;

    std::string degrees = std::string(2048, 0);
    std::string coefficients = std::string(2048, 0);

    RingPolynomial polynomial;
};


#endif //MAIN_CPP_PolynomialInputComponent_H
