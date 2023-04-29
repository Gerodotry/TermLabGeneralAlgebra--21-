#include "mod_inverse.h"
#include "mod_divide.h"

int ModDivide::calculate(int a, int b, int p)
{
    int inv = ModInverse::calculate(b, p);
    int result = (a * inv) % p;

    if (result < 0)
    {
        result += p;
    }

    return result;
}
