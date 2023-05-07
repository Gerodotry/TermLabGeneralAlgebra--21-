#ifndef LAB_MILLERRABINTEST_H
#define LAB_MILLERRABINTEST_H

#include"utils/BigInt.h"

class MillerRabinTest
{
public:
    // By default, iterationsNumber is 1.
    static bool run(BigInt numberToCheckIsPrime, int iterationsNumber);
private:
    static bool miillerTest(BigInt d, BigInt n);

	static BigInt modPow(BigInt x, BigInt y, BigInt p);
};
#endif //