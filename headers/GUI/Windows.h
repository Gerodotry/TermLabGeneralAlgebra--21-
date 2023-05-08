//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_WINDOWS_H
#define MAIN_CPP_WINDOWS_H

#include "algorithms/Algorithm.h"
#include "imgui.h"
#include <unordered_map>

class Windows {
public:
    void update();

    template<class T>
    void addAlgorithm(const std::string& name) {
        algorithms[name].push_back(std::make_shared<T>());
    }

    void addAlgorithm(const std::string& name, std::shared_ptr<Algorithm> algorithm);
private:
    std::unordered_map<std::string, std::vector<std::shared_ptr<Algorithm>>> algorithms;

    Algorithm* selectedAlgorithm = nullptr;

    Object* Result = nullptr;

    std::string resultString;

    bool algorithmButton(Algorithm* algorithm);

    void resultsWindow();

    void algorithmInputWindow();

    void algorithmListWindow();

    bool isInputValid();
};

#endif //MAIN_CPP_WINDOWS_H
