//
// Created by Dklishch on 4/24/2023.
//

#include "GUI/Windows.h"
#include "imgui.h"

void Windows::update() {
    if (Result) {
        resultsWindow();
    } else if (selectedAlgorithm) {
        algorithmInputWindow();
    } else {
        algorithmListWindow();
    }
}

void Windows::addAlgorithm(Algorithm *algorithm) {
    algorithms.push_back(algorithm);
}

Windows::~Windows() {
    for (const auto& algorithm: algorithms) {
        delete algorithm;
    }
}

bool Windows::algorithmButton(Algorithm *algorithm) {
    return ImGui::Button(algorithm->getName().c_str());
}

void Windows::resultsWindow() {
    ImGui::Begin("Results");

    ImGui::Text(Result->toString().c_str());
    if (ImGui::Button("Back")) {
        Result = nullptr;
    }

    ImGui::End();
}

void Windows::algorithmInputWindow() {
    ImGui::Begin("Control panel");

    for (auto& type: selectedAlgorithm->getTypes()) {
        type->createInputWindow();
    }

    if (!isInputValid()) {
        ImGui::Text("Input is invalid");
    } else if (ImGui::Button("Run")) {
        Result = selectedAlgorithm->run();
    }

    if (ImGui::Button("Back")) {
        selectedAlgorithm = nullptr;
    }
    ImGui::End();
}

void Windows::algorithmListWindow() {
    ImGui::Begin("Algorithms");

    for (const auto &algorithm: algorithms) {
        if (algorithmButton(algorithm)) {
            selectedAlgorithm = algorithm;
            break;
        }
    }

    ImGui::End();
}

bool Windows::isInputValid() {
    bool result = true;
    for (const auto& type: selectedAlgorithm->getTypes()) {
        result = result && type->isInputValid();
    }
    return result;
}
