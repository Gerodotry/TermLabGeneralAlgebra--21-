#include "utils/PreprocessorMainDirectives.h" //don't forget include

#ifdef IRREDUCIBILITY_UNIT_TESTS 
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //this need for testing
#include "utils/doctest.h" // this need for testing
#include "algorithms/IrreducibilityCheck.h"

TEST_CASE("CheckIrreducibleReal") {
    int a[] = { 1, 0, -1 }; // x^2 - 1
    int b[] = { 1, 0, 1 }; // x^2 + 1
    int c[] = { 1, 2, 1 }; // (x+1)^2
    int d[] = { 2, 3, 1 }; // 2x^2 + 3x + 1
    int e[] = { 2, 3, 1,5 }; 

    IrreducibilityCheck checker;

    // quadratic with real roots
    CHECK(IrreducibilityCheck::CheckIrreducibleReal(a, 3) == false);

    // quadratic with complex roots
    CHECK(IrreducibilityCheck::CheckIrreducibleReal(b, 3) == true);

    // quadratic with repeated roots
    CHECK(IrreducibilityCheck::CheckIrreducibleReal(c, 3) == false);

    // quadratic with non-integer coefficients
    CHECK(IrreducibilityCheck::CheckIrreducibleReal(d, 3) == false);

    CHECK(IrreducibilityCheck::CheckIrreducibleReal(d, 4) == false);

    
}

TEST_CASE("CheckIrreducibleComplex") {
    int a[] = { 1, 0, -1 }; // x^2 - 1
    int b[] = { 1,1 };

    IrreducibilityCheck checker;

    // quadratic with complex roots
    CHECK(IrreducibilityCheck::CheckIrreducibleComplex(a, 3) == false);
    CHECK(IrreducibilityCheck::CheckIrreducibleComplex(b, 2) == true);
    
}

TEST_CASE("CheckIrreducibleRational") {
    int a[] = { 1, 0, -1 }; // x^2 - 1
    int b[] = { 1, 0, 1 }; // x^2 + 1
    int c[] = { 1, 2, 1 }; // (x+1)^2
    int d[] = { 2, 3, 1 }; // 2x^2 + 3x + 1

    IrreducibilityCheck checker;

    // quadratic with prime factorization x^2 - 1 = (x-1)(x+1)
    CHECK(IrreducibilityCheck::CheckIrreducibleRational(a, 3) == false);

   

    // quadratic with prime factorization (x+1)^2
    CHECK(IrreducibilityCheck::CheckIrreducibleRational(c, 3) == false);

    // quadratic with non-integer coefficients
    CHECK(IrreducibilityCheck::CheckIrreducibleRational(d, 3) == false);

    
}
#endif 