#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class IrreducibilityCheck
{
public:	

	static bool CheckIrreducibleReal(int a[], int power);
	static bool CheckIrreducibleComplex(int a[], int power);
	static bool CheckIrreducibleRational(int A[], int N);
	// Function to to implement the sieve
	// of eratosthenes
	static vector<int> SieveOfEratosthenes(int M);

	// Function to check whether the three
	// conditions of Eisenstein's
	// Irreducibility criterion for prime P
	static bool check(int A[], int P, int N);
	static bool PerronisIrreducible(int coeffs[], int n);
};

