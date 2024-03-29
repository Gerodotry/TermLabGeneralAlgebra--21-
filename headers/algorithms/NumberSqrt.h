//
// Created by Dmytro Khomych and Sergiy Polyukhovych on 08.05.2023.
//
#ifndef LAB_NUMBERSQRT_H
#define LAB_NUMBERSQRT_H


#include "utils/Number.h"

class NumberSqrt {
public:
    static Number run(Number a, Number modulo);
private:
    static Number sqrt(Number& a, Number& modulo);
};

#endif //LAB_NUMBERSQRT_H
