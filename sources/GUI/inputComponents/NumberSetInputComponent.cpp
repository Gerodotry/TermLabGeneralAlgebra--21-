//
// Created by Dklishch on 6/1/2023.
//

#include "GUI/inputComponents/NumberSetInputComponent.h"
#include "imgui.h"
#include "utils/Parser.h"

void NumberSetInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Values", &numbersString[0], 2048); //TODO: check if have changed to avoid reparsing same string again

    ImGui::End();
}

Object* NumberSetInputComponent::getObject() {\
    numbers.numbers.clear();
    for (const auto& number: Parser::parseNumbers(numbersString)) {
        numbers.numbers.insert(Number(number));
    }
    return &numbers;
}

NumberSetInputComponent::NumberSetInputComponent(const std::string &name): InputComponent(name){

}

bool NumberSetInputComponent::isInputValid() {
    return true;
}
