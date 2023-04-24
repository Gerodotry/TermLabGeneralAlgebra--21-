#include "algorithms/IrreducibilityCheck.h"




bool IrreducibilityCheck::CheckIrreducibleReal(int a[], int power)
{
    power = power - 1;
    if (power == 1) return true;        
    if (power > 2) return false;
    if (power == 2) {
        if ((pow(a[1], 2) - 4 * a[0] * a[2]) >= 0) {

            return false;
        }
        else return true;
    }
    
}

bool IrreducibilityCheck::CheckIrreducibleComplex(int a[], int power)
{
    power = power - 1;
    if (power == 1) return true;
    else return false;
}

// Function to check for Eisensteins
// Irreducubility Criterion
 bool IrreducibilityCheck::CheckIrreducibleRational(int A[], int N)
{
     // Stores the largest element in A
     int M = -1;

     // Find the maximum element in A
     for (int i = 0; i < N; i++) {
         M = max(M, A[i]);
     }

     // Stores all the prime numbers
     vector<int> primes
         = SieveOfEratosthenes(M + 1);

     // Check if any prime
     // satisfies the conditions
     for (int i = 0;
         i < primes.size(); i++) {

         // Function Call to check
         // for the three conditions
         if (check(A, primes[i], N)) {
             return 1;
             
         }
     }
     return 0;
}

vector<int> IrreducibilityCheck::SieveOfEratosthenes(int M)
{
    // Stores the prime numbers
    bool* isPrime= new bool[M + 1];

    // Initialize the prime numbers
    memset(isPrime, true,
        sizeof(isPrime));

    for (int p = 2; p * p <= M; p++) {

        // If isPrime[p] is not changed,
        // then it is a prime
        if (isPrime[p] == true) {

            // Update all multiples of
            // p as non-prime
            for (int i = p * p;
                i <= M; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Stores all prime numbers less
    // than M
    vector<int> prime;

    for (int i = 2; i <= M; i++) {

        // If the i is the prime numbers
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }

    // Return array having the primes
    return prime;
}

bool IrreducibilityCheck::check(int A[], int P, int N)
{
    // 1st condition
    if (A[0] % P == 0)
        return 0;

    // 2nd condition
    for (int i = 1; i < N; i++)
        if (A[i] % P)
            return 0;

    // 3rd condition
    if (A[N - 1] % (P * P) == 0)
        return 0;

    return 1;
   
}

bool IrreducibilityCheck::PerronisIrreducible(int coeffs[], int n)
{
    int a = abs(coeffs[0]);
    int b = abs(coeffs[n - 1]);

    for (int i = 1; i < n - 1; i++) {
        int c = abs(coeffs[i]);
        if (c > a) {
            swap(a, c);
        }
        if (c > b) {
            swap(b, c);
        }
    }

    int d = coeffs[n - 1];
    double bound = 1 + b / a;

    for (int k = 1; k <= n - 2; k++) {
        double x = pow(d / k, 1.0 / (n - 1));
        if (x > bound) {
            return true;
        }
    }

    return false;
}

