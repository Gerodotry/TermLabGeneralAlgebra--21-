#include <iostream>
#include "utils/Vector.h"
#include "algorithms/VectorMultiplication.h"

int main() {
    Vector3D a{1, 2, 3};
    Vector3D b{1, 2, 3};
    std::cout << VectorMultiplication::run(a, b) << std::endl;
    std::cout << "Hello world" << std::endl;
}