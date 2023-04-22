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
	
	/// <summary>By default iterationsNumber is 1</summary>
	static bool run(bigint numberToCheckIsPrime, int iterationsNumber);
};