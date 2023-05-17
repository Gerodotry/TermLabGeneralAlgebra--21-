//
// Created by Dklishch on 5/8/2023.
//

#include "GUI/inputComponents/BigIntInputComponent.h"
#include "imgui.h"

void BigIntInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputText("Value", &numberString[0], 2048, ImGuiInputTextFlags_CharsDecimal | ImGuiInputTextFlags_AutoSelectAll);
    ImGui::End();
}

Object* BigIntInputComponent::getObject() {
    size_t len = numberString.find_first_of('\000');
    number = BigInt(numberString.substr(0, len));
    return &number;
}

BigIntInputComponent::BigIntInputComponent(const std::string &name): InputComponent(name){

}

bool BigIntInputComponent::isInputValid() {
    return true;
}