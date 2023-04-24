#include "utils/PreprocessorMainDirectives.h" //don't forget include

#ifdef MILLERRABIN_UNIT_TESTS // type like this and add your title to PreprocessorMainDirectives.h

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN //this need for testing
#include "utils/doctest.h" // this need for testing
#include "algorithms/MillerRabinTest.h"

TEST_CASE("MillerRabinTestTESTS") {

    SUBCASE("One iteration")
    {
        SUBCASE("check prime number 1 must be false") {
            CHECK(MillerRabinTest::run(1, 1) == false);
        }
        SUBCASE("check prime number 2 must be true") {
            CHECK(MillerRabinTest::run(2, 1) == true);
        }
        SUBCASE("check prime number 100 must be false") {
            CHECK(MillerRabinTest::run(100, 1) == false);
        }
        SUBCASE("check prime number 111 must be false") {
            CHECK(MillerRabinTest::run(100, 1) == false);
        }
        SUBCASE("check prime number 1111111111111111111 must be true") {
            CHECK(MillerRabinTest::run(1111111111111111111, 1) == true);
        }
    }
    SUBCASE("Two iteration")
    {
        SUBCASE("check prime number 1 must be false") {
            CHECK(MillerRabinTest::run(1, 2) == false);
        }
        SUBCASE("check prime number 2 must be true") {
            CHECK(MillerRabinTest::run(2, 2) == true);
        }
        bigint bigNumber("8683317618811886495518194401279999999");
        SUBCASE("check prime number 8683317618811886495518194401279999999 must be true") {
            
            CHECK(MillerRabinTest::run(bigNumber, 2) == true);
        }
    }
    SUBCASE("Three iteration and very big numbers")
    {
        bigint bigNumber("8683317618811886495518194401279999999");
        SUBCASE("check prime number bigNumber must be true") {

            CHECK(MillerRabinTest::run(bigNumber, 3) == true);
        }
        SUBCASE("check prime number bigNumber * 2 must be false") {
            CHECK(MillerRabinTest::run(bigNumber*2, 3) == false);
        }
        bigint bigNumber2("6161791591356884791277");
        SUBCASE("check prime number bigNumber2 must be true") {
            CHECK(MillerRabinTest::run(bigNumber2, 3) == true);
        }
        SUBCASE("check prime number bigNumber2 * 3 must be false") {
            CHECK(MillerRabinTest::run(bigNumber2 * 3, 3) == false);
        }
        bigint bigNumber3("3318308475676071413");
        SUBCASE("check prime number bigNumber3 must be true") {
            CHECK(MillerRabinTest::run(bigNumber3, 3) == true);
        }
        SUBCASE("check prime number bigNumber3 * 10 must be false") {
            CHECK(MillerRabinTest::run(bigNumber3 * 10, 3) == false);
        }
        bigint bigNumber4("43143988327398957279342419750374600193");
        SUBCASE("check prime number bigNumber3 must be true") {
            CHECK(MillerRabinTest::run(bigNumber4, 3) == true);
        }
        SUBCASE("check prime number bigNumber3 * 10 must be false") {
            CHECK(MillerRabinTest::run(bigNumber4 * 10, 3) == false);
        }
    }
    SUBCASE("Invalid numbers")
    {
        SUBCASE("check prime number -1 must be false") {

            CHECK(MillerRabinTest::run(-1, 3) == false);
        }
        SUBCASE("check prime number 0 must be false") {

            CHECK(MillerRabinTest::run(0, 13) == false);
        }
        SUBCASE("check prime number 1 must be false") {

            CHECK(MillerRabinTest::run(0, 5) == false);
        }
        SUBCASE("check prime number -15544 must be false") {

            CHECK(MillerRabinTest::run(-15544, 5) == false);
        }
        SUBCASE("check prime number -11 must be false") {

            CHECK(MillerRabinTest::run(-11, 5) == false);
        }
    }

}
#endif // MILLERRABIN_UNIT_TESTS