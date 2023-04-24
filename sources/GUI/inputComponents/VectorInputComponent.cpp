//
// Created by Dklishch on 3/26/2023.
//

#include "GUI/InputComponents/VectorInputComponent.h"
#include "imgui.h"

void VectorInputComponent::createInputWindow() {
    ImGui::Begin(name.c_str());
    ImGui::InputFloat3("Values", values);
    ImGui::End();
}

Object* VectorInputComponent::getObject() {
    Vector3D *vector = new Vector3D;
    vector->x = values[0];
    vector->y = values[1];
    vector->z = values[2];
    return vector;
}

VectorInputComponent::VectorInputComponent(const std::string &name): InputComponent(name){

}

bool VectorInputComponent::isInputValid() {
    return true;
}
