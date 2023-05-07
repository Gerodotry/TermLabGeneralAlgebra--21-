#include"headers/utils/PreprocessorMainDirectives.h"
#include <iostream>
#include "algorithms/MillerRabinTest.h"
#include "algorithms/Gcd.h"
#include "algorithms/Remainder.h"
#include "algorithms/Division.h"
#include <cmath>
#include <vector>

using namespace std;

#ifdef MAIN


int main() {
    //unsigned int k = 8;  // Number of iterations
    //bigint n = 87178291199;

    //if (MillerRabinTest::run(n, k))
    //     cout <<"Number "<< n<<" is prime\n";  
    //else
    //    cout << "Number " << n << " is not prime\n";

    vector<int> a = {3, 0, 0, 0, 2, 1, 5};
    vector<int> b = {6, 1, 0, 2, 4};
    int mod = 7;
    vector<int> g = Gcd::run(a, b, mod);
    vector<int> remainder = Remainder::run(a, b, mod);
    vector<int> div = Division::run(a, b, mod);
    cout << "Gcd(";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << "x^" << a.size() - i - 1;
        if (i < a.size() - 1) cout << " + ";
    }
    cout << ", ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << "x^" << b.size() - i - 1;
        if (i < b.size() - 1) cout << " + ";
    }
    cout << ") = ";
    for (int i = 0; i < g.size(); i++) {
        cout << g[i] << "x^" << g.size() - i - 1;
        if (i < g.size() - 1) cout << " + ";
    }
    cout << endl;

    cout << "Remainder: ";
    for (int i = 0; i < remainder.size(); i++) {
        cout << remainder[i] << "x^" << remainder.size() - i - 1;
        if (i < remainder.size() - 1) cout << " + ";
    }
    cout << endl;

    cout << "Division result: ";
    for (int i = 0; i < div.size(); i++) {
        cout << div[i] << "x^" << div.size() - i - 1;
        if (i < div.size() - 1) cout << " + ";
    }
    cout << endl;

    return 0;
}

#endif // MAIN
