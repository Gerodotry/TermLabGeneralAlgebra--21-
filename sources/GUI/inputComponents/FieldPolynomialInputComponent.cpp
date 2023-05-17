//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/FieldPolynomialInputComponent.h"
#include "imgui.h"
#include "utils/Number.h"
#include "utils/Int.h"
#include "utils/Parser.h"

void FieldPolynomialInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Degrees", &degrees[0], 2048); //TODO: check if have changed to avoid reparsing same string again
    ImGui::InputText("Coefficients", &coefficients[0], 2048);

    ImGui::End();
}

Object* FieldPolynomialInputComponent::getObject() {
    std::vector<std::string> degreesList = Parser::parseNumbers(degrees);
    std::vector<std::string> coefficientsList = Parser::parseNumbers(coefficients);
    polynomial = FieldPolynomial(degreesList, coefficientsList);
    return &polynomial;
}

FieldPolynomialInputComponent::FieldPolynomialInputComponent(const std::string &name): InputComponent(name){

}

bool FieldPolynomialInputComponent::isInputValid() {
    return true;
}