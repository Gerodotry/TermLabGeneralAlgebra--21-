#include "utils/PreprocessorMainDirectives.h"

#ifdef POLLARD_UNIT_TESTS

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "utils/doctest.h"
#include <algorithms/Pollard.h>

TEST_CASE("Pollard Factorization Test") {
    Pollard pollard;

    // Test Case 1: Factorization of a prime number
    Number primeNumber("257");
    std::vector<Number> primeFactors = pollard.run(primeNumber);
    REQUIRE(primeFactors.size() == 1);
    CHECK(primeFactors[0].toString() == "257");

    // Test Case 2: Factorization of a composite number
    Number compositeNumber("561");
    std::vector<Number> compositeFactors = pollard.run(compositeNumber);
    REQUIRE(compositeFactors.size() == 2);
    CHECK(compositeFactors[0].toString() == "3");
    CHECK(compositeFactors[1].toString() == "11");

    // Test Case 3: Factorization of a large number
    Number largeNumber("123456789");
    std::vector<Number> largeFactors = pollard.run(largeNumber);
    REQUIRE(largeFactors.size() == 3);
    CHECK(largeFactors[0].toString() == "3");
    CHECK(largeFactors[1].toString() == "3");
    CHECK(largeFactors[2].toString() == "3607");
}
#endif
