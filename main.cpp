#pragma once
#include <iostream>
#include "algorithms/MillerRabinTest.h"

int main()
{
    unsigned int k = 8;  // Number of iterations
    bigint n = 87178291199;

    if (MillerRabinTest::run(n, k))
         cout <<"Number "<< n<<" is prime\n";  
    else
        cout << "Number " << n << " is not prime\n";

  

    return 0;
}