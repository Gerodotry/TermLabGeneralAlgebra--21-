#pragma once
#include "algorithms/MillerRabinTest.h"
#include <iostream>


//�����i� ��� ���������� �i�������� �� �������
bigint MillerRabinTest::modPow(bigint x, bigint y, bigint p)
{
    bigint res = 1;      //i�i�i��i���i� ����������
    x = x % p;  // ����i��� ������� �, ���� ���� �i���� ��� ��� � ���� �� � 
  
    while (y > 0)
    {
        // ���� � �������, �� ����i��� ��������� �� ���������
        if ((y % 2)!=0)
            res = (res * x) % p;

        // � ������ ���� ����� ����� 
        y /= 2;  
        x = (x * x) % p;
    }
    return res;
}
bool MillerRabinTest::miillerTest(bigint d, bigint n)
{
   
    //������� ����� ��������� ����� � ������� [2..,n - 2)
    bigint a;
    while (a < 2 || a >= n - 2)
        a = 2 + rand() % n.longValue() - 4;

    // ������������ a^d % n �� �������� ���������� �i�������� �� �������
    bigint x = modPow(a, d, n);

    // ���� � == 1 ��� x == n - 1, �� ������� ������� �� �������� �������� �����
    if (x == 1 || x == n - 1)
        return true;

    // ��������� � �� ��������, ���� ���� � ���������� �� ���������
    // (I)   d �� ������ n-1
    // (II)  (x^2) % n �� 1
    // (III) (x^2) % n �� n-1
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false; //����������� "��������", ����� ����� ��������
        if (x == n - 1)    return true;//������� �� �������� �������� �����
    }

   //����������� "��������"
    return false;
}
bool MillerRabinTest::run(bigint numberToCheckIsPrime,  int iterationsNumber)
{
    if (iterationsNumber <= 0)
        iterationsNumber = 1;
    // �������� ����
    if (numberToCheckIsPrime <= 1 || numberToCheckIsPrime == 4)  return false;
    if (numberToCheckIsPrime <= 3) return true;

    // ����� ���� d, �� n = 2^d * r + 1 ��� ������� r >= 1
    bigint d = numberToCheckIsPrime - 1;
    while (d % 2 == 0)
        d /= 2;

    // ���������� ��i���� ���i�, ������ i�������i� 
    for (int i = 0; i < iterationsNumber; i++)
        if (!miillerTest(d, numberToCheckIsPrime))
            return false;
    //���� ��i ����� true, �� ����� �� ��� ����� ������
    return true;
}
