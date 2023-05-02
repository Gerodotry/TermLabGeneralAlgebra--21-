#include "mod_inverse.h"
#include <iostream>

int GCDExtended::calculate(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = calculate(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// next

int ModInverse::calculate(int a, int m)
{
    int x, y;
    int gcd = GCDExtended::calculate(a, m, &x, &y);

    if (gcd != 1)
    {
        std::cout << "Inverse does not exist";
        return -1;
    }
    else
    {
        return (x % m + m) % m;
    }
}
