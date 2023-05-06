#pragma once
#include "algorithms/MillerRabinTest.h"
#include <iostream>


//функцiя для модульного пiднесення до степеня
bigint MillerRabinTest::modPow(bigint x, bigint y, bigint p)
{
    bigint res = 1;      //iнiцiалiзацiя результату
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
bool MillerRabinTest::miillerTest(bigint d, bigint n)
{
   
    //Потрібно взяти випадкове число в діапазоні [2..,n - 2)
    bigint a;
    while (a < 2 || a >= n - 2)
        a = 2 + rand() % n.longValue() - 4;

    // Обчислюється a^d % n за допмогою модульного пiднесення до степеня
    bigint x = modPow(a, d, n);

    // якщо х == 1 або x == n - 1, то потрібно перейти на наступну ітерацію цикла
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

   //повертається "складове"
    return false;
}
bool MillerRabinTest::run(bigint numberToCheckIsPrime,  int iterationsNumber)
{
    if (iterationsNumber <= 0)
        iterationsNumber = 1;
    // Перевірка умов
    if (numberToCheckIsPrime <= 1 || numberToCheckIsPrime == 4)  return false;
    if (numberToCheckIsPrime <= 3) return true;

    // Зайти таке d, що n = 2^d * r + 1 для деякого r >= 1
    bigint d = numberToCheckIsPrime - 1;
    while (d % 2 == 0)
        d /= 2;

    // Виконується стiльки разiв, скільки iтераторiв 
    for (int i = 0; i < iterationsNumber; i++)
        if (!miillerTest(d, numberToCheckIsPrime))
            return false;
    //ящко всi цикли true, то скоріш за все число просте
    return true;
}
