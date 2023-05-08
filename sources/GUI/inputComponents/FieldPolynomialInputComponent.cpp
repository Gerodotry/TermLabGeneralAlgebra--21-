//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/PolynomialInputComponent.h"
#include "imgui.h"
#include "utils/Number.h"
#include "utils/Int.h"

void FieldPolynomialInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Degrees", &degrees[0], 2048); //TODO: check if have changed to avoid reparsing same string again
    ImGui::InputText("Coefficients", &coefficients[0], 2048);

    ImGui::End();
}

Object* FieldPolynomialInputComponent::getObject() {
    std::vector<std::string> degreesList = parseNumbers(degrees);
    std::vector<std::string> coefficientsList = parseNumbers(coefficients);
    polynomial = FieldPolynomial(degreesList, coefficientsList);
    return &polynomial;
}

FieldPolynomialInputComponent::FieldPolynomialInputComponent(const std::string &name): InputComponent(name){

}

bool FieldPolynomialInputComponent::isInputValid() {
    return true;
}

std::vector<std::string> FieldPolynomialInputComponent::parseNumbers(const std::string &string) {
    std::vector<std::string> results;
    std::string tmp;
    for (const char& c: string) {
        if (c == ' ') continue;
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
