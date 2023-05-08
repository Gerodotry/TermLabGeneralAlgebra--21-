//
// Created by Dklishch on 5/8/2023.
//

#include "utils/NumberFactors.h"

std::string NumberFactors::toString() {
    std::string result;
    for (auto& number: numbers) {
        result += number.toString() + ", ";
    }

    result.pop_back();
    result.pop_back();

    return result;
}

NumberFactors::NumberFactors(const std::vector<Number> &numbers) : numbers(numbers) {

}

NumberFactors::NumberFactors() {

}
