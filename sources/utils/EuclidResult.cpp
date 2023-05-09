//
// Created by Dklishch on 5/9/2023.
//

#include "utils/EuclidResult.h"

std::string EuclidResult::toString() {
    std::string result;

    result += "gcd: " + gcd.toString() + "\n";
    result += "a: " + a.toString() + "\n";
    result += "b: " + b.toString() + "\n";

    return result;
}
