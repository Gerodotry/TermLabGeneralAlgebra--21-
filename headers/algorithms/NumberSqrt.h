//
// Created by Dmytro Khomych and Sergiy Polyukhovych on 08.05.2023.
//
#ifndef LAB_NUMBERSQRT_H
#define LAB_NUMBERSQRT_H


class NumberSqrt {
public:
    static Number run(Number a, unsigned int modulo);

private:
    static Number sqrt(const Number& a, unsigned int modulo);
};

#endif //LAB_NUMBERSQRT_H
