//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/PolynomialInputComponent.h"
#include "imgui.h"
#include "utils/Number.h"
#include "utils/Int.h"

void PolynomialInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Degrees", &degrees[0], 2048); //TODO: check if have changed to avoid reparsing same string again
    ImGui::InputText("Coefficients", &coefficients[0], 2048);

    ImGui::End();
}

Object* PolynomialInputComponent::getObject() {
    std::vector<std::string> degreesList = parseNumbers(degrees);
    std::vector<std::string> coefficientsList = parseNumbers(coefficients);
    polynomial = Polynomial(degreesList, coefficientsList);
    return &polynomial;
}

PolynomialInputComponent::PolynomialInputComponent(const std::string &name): InputComponent(name){

}

bool PolynomialInputComponent::isInputValid() {
    return true;
}

std::vector<std::string> PolynomialInputComponent::parseNumbers(const std::string &string) {
    std::vector<std::string> results;
    std::string tmp;
    for (const char& c: string) {
        if (c >= '0' && c <= '9') {
            tmp += c;
        } else {
            results.push_back(tmp);
            tmp.clear();
        }
        if (c == '\00') break;
    }
    return results;
}
