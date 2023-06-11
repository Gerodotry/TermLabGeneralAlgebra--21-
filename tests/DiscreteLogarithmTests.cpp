//
// Created by sofia on 11.06.2023.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //this need for testing
#include "algorithms/DiscreteLogarithm.h"
#include "utils/doctest.h" // this need for testing
#include "utils/PreprocessorMainDirectives.h" //don't forget include
#ifdef DISCRETELOGARITHM_UNIT_TESTS

TEST_CASE("test case 1") {
    int a = 3;
    int b = 13;
    int m = 17;
    int expected = 4;
    CHECK(DiscreteLogarithm::discrete_logarithm(a, b, m) == expected);
}

TEST_CASE("test case 2") {
    int a = 2535452443767;
    int b = 4327588590113;
    int m = 17;
    int expected = 2;
    CHECK(DiscreteLogarithm::discrete_logarithm(a, b, m) == expected);
}

TEST_CASE("test case 3") {
    int a = 2535452443767;
    int b = 4327588590113;
    int m = 13;
    int expected = 2;
    CHECK(DiscreteLogarithm::discrete_logarithm(a, b, m) == expected);
}

TEST_CASE("test case 4") {
    int a = 13;
    int b = 3;
    int m = 17;
    int expected = -1;
    CHECK(DiscreteLogarithm::discrete_logarithm(a, b, m) == expected);
}

TEST_CASE("test case 5") {
    int a = 3;
    int b = 13;
    int m = 1;
    int expected = 0;
    CHECK(DiscreteLogarithm::discrete_logarithm(a, b, m) == expected);
}

#endif // DISCRETELOGARITHM_UNIT_TESTS
