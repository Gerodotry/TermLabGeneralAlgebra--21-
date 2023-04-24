#pragma once
#include"utils/BigInteger.h"

using namespace BigInt;
class MillerRabinTest
{
private:
	static bool miillerTest(bigint d, bigint n);
	//функцiя для модульного пiднесення до степеня
	static bigint modPow(bigint x, bigint y, bigint p);
public:
	
	// Main function to run algorithm. By default iterationsNumber is 1.
	static bool run(bigint numberToCheckIsPrime, int iterationsNumber);
};