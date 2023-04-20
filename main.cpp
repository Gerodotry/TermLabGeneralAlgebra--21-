#include <iostream>
#include "utils/Vector.h"
#include "algorithms/VectorMultiplication.h"

int main() {
    Vector3D a{1, 2, 3};
    Vector3D b{1, 2, 3};
    std::cout << VectorMultiplication::run(a, b) << std::endl;
    std::cout << "Hello world" << std::endl;
    
    std::map<long long, int> pn1 = PollardFactorization::factorize(10403);
    std::map<long long, int> ans1{std::pair(7, 1), std::pair(13, 1)};

    for(map<long long,int>::const_iterator it = pn1.begin();
        it != pn1.end(); ++it)
    {
        std::cout << it->first << " " << it->second;
        cout <<endl;
    }
    for(map<long long,int>::const_iterator it = ans1.begin();
        it != ans1.end(); ++it)
    {
        std::cout << it->first << " " << it->second;
        cout <<endl;
    }
}