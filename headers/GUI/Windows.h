//
// Created by Dklishch on 4/24/2023.
//

#ifndef MAIN_CPP_WINDOWS_H
#define MAIN_CPP_WINDOWS_H

#include "algorithms/Algorithm.h"
#include "imgui.h"

class Windows {
public:
    void update();

    template<class T>
    void addAlgorithm() {
        algorithms.push_back(new T);
    }

    void addAlgorithm(Algorithm* algorithm);

    ~Windows();
private:
    std::vector<Algorithm*> algorithms;

    Algorithm* selectedAlgorithm = nullptr;

    Object* Result = nullptr;

    bool algorithmButton(Algorithm* algorithm);

    void resultsWindow();

    void algorithmInputWindow();

    void algorithmListWindow();

    bool isInputValid();
};

#endif //MAIN_CPP_WINDOWS_H
