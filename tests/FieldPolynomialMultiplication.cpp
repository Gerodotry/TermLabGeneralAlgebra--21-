#include "utils/PreprocessorMainDirectives.h" //don't forget include

#ifdef FIELD_POLYNOMIAL_MULTIPLICATION_UNIT_TESTS

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //this need for testing

#include "utils/doctest.h" // this need for testing
#include "utils/FieldPolynomial.h"
#include "algorithms/PolynomialMultiplication.h"

TEST_CASE("Polynomial multiplication test 0") {
    FieldPolynomial polynomial1 = { {4, 1}, {3, 0}, {2, 1}, {1, 1}, {0, 0} };
    FieldPolynomial polynomial2 = { {3, 1}, {2, 0}, {1, 1}, {0, 1} };

    FieldPolynomial result = PolynomialMultiplication::run(polynomial1, polynomial2, 10);
    FieldPolynomial expected = { {4, 1}, {3, 1}, {2, 1}, {1, 2}, {0, 1} };

    CHECK(expected.toString() == result.toString());
}

TEST_CASE("Polynomial multiplication test 1") {
    FieldPolynomial polynomial1 = { {5, 1}, {4, 0}, {3, 1}, {2, 0}, {1, 0}, {0, 1} };
    FieldPolynomial polynomial2 = { {4, 1}, {3, 0}, {2, 0}, {1, 1}, {0, 0} };

    FieldPolynomial result = PolynomialMultiplication::run(polynomial1, polynomial2, 10);
    FieldPolynomial expected = { {5, 1}, {4, 1}, {3, 1}, {1, 1}, {0, 1} };

    CHECK(expected.toString() == result.toString());
}

TEST_CASE("Polynomial multiplication test 2") {
    FieldPolynomial polynomial1 = { {6, 0}, {5, 1}, {4, 1}, {3, 0}, {2, 1}, {1, 0}, {0, 1} };
    FieldPolynomial polynomial2 = { {5, 1}, {4, 0}, {3, 0}, {2, 1}, {1, 1}, {0, 0} };

    FieldPolynomial result = PolynomialMultiplication::run(polynomial1, polynomial2, 10);
    FieldPolynomial expected = { {5, 2}, {4, 1}, {2, 2}, {1, 1}, {0, 1} };

    CHECK(expected.toString() == result.toString());
}

TEST_CASE("Polynomial multiplication test 3") {
    FieldPolynomial polynomial1 = { {4, 0}, {3, 1}, {2, 0}, {1, 1}, {0, 0} };
    FieldPolynomial polynomial2 = { {3, 1}, {2, 0}, {1, 1}, {0, 1} };

    FieldPolynomial result = PolynomialMultiplication::run(polynomial1, polynomial2, 3);
    FieldPolynomial expected = { {0, 1} };

    CHECK(expected.toString() == result.toString());
}

TEST_CASE("Polynomial multiplication test 4") {
    FieldPolynomial polynomial1 = { {5, 0}, {4, 1}, {3, 0}, {2, 0}, {1, 1}, {0, 1} };
    FieldPolynomial polynomial2 = { {4, 0}, {3, 1}, {2, 0}, {1, 1}, {0, 0} };

    FieldPolynomial result = PolynomialMultiplication::run(polynomial1, polynomial2, 2);
    FieldPolynomial expected = { {0, 0} };

    CHECK(expected.toString() == result.toString());
}

#endif