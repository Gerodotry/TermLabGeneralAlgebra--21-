//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/IntInputComponent.h"
#include "imgui.h"
#include "utils/Number.h"
#include "utils/Int.h"

void IntInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputInt("Value", value.getPointer());
    ImGui::End();
}

Object* IntInputComponent::getObject() {
    return &value;
}

IntInputComponent::IntInputComponent(const std::string &name): InputComponent(name){

}

bool IntInputComponent::isInputValid() {
    return true;
}
