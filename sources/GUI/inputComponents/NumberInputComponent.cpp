//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/NumberInputComponent.h"
#include "imgui.h"
#include "utils/Number.h"

void NumberInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Value", &number[0], 1024);
    ImGui::End();
}

Object* NumberInputComponent::getObject() {
    int len = number.find_first_of('\000');
    Number* result = new Number(number.substr(0, len));
    return result;
}

NumberInputComponent::NumberInputComponent(const std::string &name): InputComponent(name){

}

bool NumberInputComponent::isInputValid() {
    return true;
}
