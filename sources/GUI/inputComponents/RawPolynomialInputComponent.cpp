//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/inputComponents/RawPolynomialInputComponent.h"
#include "imgui.h"
#include "utils/Parser.h"


void RawPolynomialInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Degrees", &degrees[0], 2048); //TODO: check if have changed to avoid reparsing same string again
    ImGui::InputText("Coefficients", &coefficients[0], 2048);

    ImGui::End();
}

Object* RawPolynomialInputComponent::getObject() {
    std::vector<std::string> degreesList = Parser::parseNumbers(degrees);
    std::vector<std::string> coefficientsList = Parser::parseNumbers(coefficients);
    polynomial = RawPolynomial(degreesList, coefficientsList);
    return &polynomial;
}

RawPolynomialInputComponent::RawPolynomialInputComponent(const std::string &name): InputComponent(name){

}

bool RawPolynomialInputComponent::isInputValid() {
    return true;
}