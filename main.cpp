#pragma once
#include"headers/utils/PreprocessorMainDirectives.h"


#include <iostream>
#include "algorithms/MillerRabinTest.h"
#include "algorithms/IrreducibilityCheck.h"
#include <cmath>
#include <vector>

using namespace std;

#ifdef MAIN




int main()
{
    //unsigned int k = 8;  // Number of iterations
    //bigint n = 87178291199;

    //if (MillerRabinTest::run(n, k))
    //     cout <<"Number "<< n<<" is prime\n";  
    //else
    //    cout << "Number " << n << " is not prime\n";
   
    int coeff[] = { 1,0,-4 }; // x^3 - 3x + 1
    
	if (IrreducibilityCheck::CheckIrreducibleReal(coeff, sizeof(coeff) / sizeof(coeff[0])))
		cout << "The polynomial is irreducible in the real field." << endl;
	else
		cout << "The polynomial is reducible in the real field." << endl;

	if (IrreducibilityCheck::CheckIrreducibleComplex(coeff, sizeof(coeff) / sizeof(coeff[0])))
		cout << "The polynomial is irreducible in the complex field." << endl;
	else
		cout << "The polynomial is reducible in the complex field." << endl;
	
    
    if (IrreducibilityCheck::CheckIrreducibleRational(coeff, sizeof(coeff) / sizeof(coeff[0])))
        cout << "The polynomial is irreducible in the rational field." << endl;
    else
        cout << "The polynomial is reducible in the rational field." << endl;
	
	
    return 0;
}
#endif // MAIN
