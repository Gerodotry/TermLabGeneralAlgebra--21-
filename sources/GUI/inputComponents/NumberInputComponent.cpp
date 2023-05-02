//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/NumberInputComponent.h"
#include "imgui.h"
#include "utils/Number.h"

void NumberInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Value", &numberString[0], 1024);
    ImGui::End();
}

Object* NumberInputComponent::getObject() {
    size_t len = numberString.find_first_of('\000');
    number = Number(numberString.substr(0, len));
    return &number;
}

NumberInputComponent::NumberInputComponent(const std::string &name): InputComponent(name){

}

bool NumberInputComponent::isInputValid() {
    return true;
}
