#include "algorithms/MillerRabinTest.h"
#include <iostream>


//функцiя для модульного пiднесення до степеня
BigInt MillerRabinTest::modPow(BigInt x, BigInt y, BigInt p)
{
    BigInt res = 1;  //iнiцiалiзацiя результату
    x = x % p;  // Потрiбно оновити х, якщо воно бiльше або так ж саме як р 
  
    while (y > 0)
    {
        // Якщо у непарне, то потрiбно помножити на результат
        if ((y % 2)!=0)
            res = (res * x) % p;

        // у повине бути парне зараз 
        y /= 2;  
        x = (x * x) % p;
    }
    return res;
}
bool MillerRabinTest::miillerTest(BigInt d, BigInt n)
{
   
     //Потрібно взяти випадкове число в діапазоні [2..,n - 2)
    BigInt a;
    while (a < 2 || a >= n - 2)
        a = 2 + rand() % n.longValue() - 4;

    // Обчислюється a^d % n за допомогою модульного пiднесення до степеня
    BigInt x = modPow(a, d, n);

   // якщо х == 1 або x == n - 1, то потрібно перейти на наступну ітерацію цикла
    // x == 1 - це 1 умова
    // x == n-1 - це 2 умова, по модулю n "-1 == n-1"
    if (x == 1 || x == n - 1)
        return true;

    // Зводиться х до квадрату, поки одне з наступного не трапиться
    // (I)   d не досягає n-1
    // (II)  (x^2) % n не 1
    // (III) (x^2) % n не n-1
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false; //повертається "складове", тобто число непросте
        if (x == n - 1)    return true;//перехід на наступну ітерацію цикла
    }

    //повертається "складове", тобто число непросте
    return false;
}
bool MillerRabinTest::run(BigInt numberToCheckIsPrime,  int iterationsNumber)
{
    if (iterationsNumber <= 0)
        iterationsNumber = 1;
     // Перевірка умов
    if (numberToCheckIsPrime <= 1 || numberToCheckIsPrime == 4)  return false;
    if (numberToCheckIsPrime <= 3) return true;

    // Зайти таке d, що n = 2^r*d + 1, де d - непросте, r - якесь додатнє число 
    BigInt d = numberToCheckIsPrime - 1;
    while (d % 2 == 0)
        d /= 2;

     // Виконується стiльки разiв, скільки iтераторiв 
    for (int i = 0; i < iterationsNumber; i++)
        if (!miillerTest(d, numberToCheckIsPrime))
            return false;
     //ящко всi цикли true, то скоріш за все число просте
    return true;
}
