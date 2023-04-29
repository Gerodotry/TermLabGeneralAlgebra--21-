// needs correction 
#include "utils/doctest.h"
#include "mod_inverse.h"
#include "mod_divide.h"

TEST_CASE("gcdExtended with random values")
{
    for (int i = 0; i < 100; i++)
    {
        int a = rand();
        int b = rand();
        int x, y;
        int gcd = GCDExtended::calculate(a, b, &x, &y);
        REQUIRE(gcd == std::__gcd(a, b));
        REQUIRE(a * x + b * y == gcd);
    }
}

TEST_CASE("modInverse with random values")
{
    for (int i = 0; i < 100; i++)
    {
        int a = rand() % 1000;
        int m = rand() % 1000 + 1; // m must be positive
        int inv = ModInverse::calculate(a, m);
        if (std::__gcd(a, m) == 1)
        {
            REQUIRE((a * inv) % m == 1);
        }
        else
        {
            REQUIRE(inv == -1);
        }
    }
}
