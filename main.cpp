#include <iostream>
#include <cassert>
#include "utils/Vector.h"
#include "algorithms/VectorMultiplication.h"
#include "algorithms/NumberMultiplication.h"

int main() {
    Vector3D a{1, 2, 3};
    Vector3D b{1, 2, 3};
    std::cout << VectorMultiplication::run(a, b) << std::endl;
    std::cout << "Hello world" << std::endl;

    /* Test NumberMultiplication */
    unsigned int modulo = 10;
    Number a1("123"), b1("456");
    Number result = NumberMultiplication::run(a1, b1, modulo);
    assert(result.toString() == "209934");
    return 0;
}