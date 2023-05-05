//
// Created by Dklishch on 3/26/2023.
//

#ifndef MAIN_CPP_PolynomialInputComponent_H
#define MAIN_CPP_PolynomialInputComponent_H


#include "InputComponent.h"
#include "utils/Int.h"
#include "utils/RingPolynomial.h"

class PolynomialInputComponent: public InputComponent {
public:
    explicit PolynomialInputComponent(const std::string& name);

    virtual void createInputWindow() override;

    virtual Object* getObject() override;

    bool isInputValid() override;
private:
    int count = 1;

    std::string degrees = std::string(2048, '.');
    std::string coefficients = std::string(2048, '.');

    RingPolynomial polynomial;

    std::vector<std::string> parseNumbers(const std::string& string);
};


#endif //MAIN_CPP_PolynomialInputComponent_H
