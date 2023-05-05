//
// Created by Sasha on 05.05.2023.
//
#include "utils/PreprocessorMainDirectives.h" //don't forget include
#ifdef GCP_UNIT_TESTS
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //this need for testing
#include "utils/doctest.h" // this need for testing
#include "algorithms/Gcd.h"

TEST_CASE("equal remainder and Gcd") {
    Gcd gcd;
    vector<int> poly1 = {2, 5, 6,1};
    vector<int> poly2 = {1, 10,8};
    vector<int> expected = {10, 4};
    vector<int> expectedDivision={2,11};
    CHECK(gcd.subtract_polys(poly1, poly2, 13) == expected);
    CHECK(gcd.gcd(poly1, poly2, 13) == expected);
    CHECK(gcd.division(poly1, poly2, 13) == expectedDivision);
}
TEST_CASE("not equal reminder and Gcd") {
    Gcd gcd;
    vector<int> poly1 = {3,0,0,0,2,1,5};
    vector<int> poly2 = {6, 1,0,2,4};
    vector<int> expectedGcd = {1};
    vector<int> expectedRemainder = {2, 6,5,3};
    vector<int> expectedDivision={4,4,4};
    CHECK(gcd.subtract_polys(poly1, poly2, 7) ==expectedRemainder);
    CHECK(gcd.gcd(poly1, poly2, 7) == expectedGcd);
    CHECK(gcd.division(poly1, poly2, 7) == expectedDivision);
}

TEST_CASE("division equal to 1") {
    Gcd gcd;
    vector<int> poly1 = {1,2};
    vector<int> poly2 = {1,3};
    vector<int> expectedGcd = {6};
    vector<int> expectedRemainder = {6};
    vector<int> expectedDivision={1};
    CHECK(gcd.subtract_polys(poly1, poly2, 7) ==expectedRemainder);
    CHECK(gcd.gcd(poly1, poly2, 7) == expectedGcd);
    CHECK(gcd.division(poly1, poly2, 7) == expectedDivision);
}
TEST_CASE("division without reminder") {
    Gcd gcd;
    vector<int> poly1 = {1,5,6};
    vector<int> poly2 = {1,3};
    vector<int> expectedGcd = {1,3};
    vector<int> expectedRemainder = {};
    vector<int> expectedDivision={1,2};
    CHECK(gcd.subtract_polys(poly1, poly2, 7) ==expectedRemainder);
    CHECK(gcd.gcd(poly1, poly2, 7) == expectedGcd);
    CHECK(gcd.division(poly1, poly2, 7) == expectedDivision);
}
#endif