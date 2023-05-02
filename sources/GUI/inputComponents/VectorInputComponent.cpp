//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/VectorInputComponent.h"
#include "imgui.h"

void VectorInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputFloat("X", &vector.x);
    ImGui::InputFloat("Y", &vector.y);
    ImGui::InputFloat("Z", &vector.z);
    ImGui::End();
}

Object* VectorInputComponent::getObject() {
    return &vector;
}

VectorInputComponent::VectorInputComponent(const std::string &name): InputComponent(name){

}

bool VectorInputComponent::isInputValid() {
    return true;
}
