//
// Created by Sasha on 05.05.2023.
//

#include "algorithms/Gcd.h"

std::vector<int> Gcd::divisionCoefs;
//Функція sub_poly віднімає поліном q від провідних членів полінома p
// та повертає кількість провідних нульових коефіцієнтів у результаті.
// Вона також обчислює коефіцієнт, який слід використовувати для виключення провідного члена p,
// множачи q на цей коефіцієнт та віднімаючи його від p.
// Коефіцієнт потім зберігається у векторі divisionCoefs. Ці коефіцієнти є коефіцієнтами повної/неповної частки
int Gcd::sub_poly(int *p, int *q, int len, int mod) {
    int coeff;
    int zero_count = 0;
    int i;
    //  coeff = p[0] / q[0];     // при умножении на этот коэффициент убивается старший коэфф.
    for (int x = 0; x < mod; x++) {//вираховуємо коефіцієнти частки
        if ((q[0] * x) % mod == p[0]) {
            coeff = x;
            divisionCoefs.push_back(coeff);//зберігаємо коефіцієнти частки

        }
    }
    p[0] = 0;
    for (i = 1; i < len; i++)
        p[i] = ((p[i] - (coeff * q[i]) % mod) + mod) % mod;//шукаємо коефіцієнти залишка(остачі)
    while (p[zero_count] == 0)
        zero_count++;

    return zero_count;
}
//Функція subtract_polys повторно викликає функцію sub_poly до тих пір,
// поки ступінь залишку буде меншим за ступінь дільника. Вона повертає залишок після ділення.
std::vector<int> Gcd::subtract_polys(std::vector<int> poly1, std::vector<int> poly2, int mod) {
    int len1 = poly1.size();
    int len2 = poly2.size();
    int *poly11 = new int[len1];
    int *poly22 = new int[len1];
    for (int k = 0; k < len1; k++) {
        poly11[k] = poly1[k];
    }
    for (int k = 0; k < len2; k++) {
        poly22[k] = poly2[k];
    }
    int i;
    int coeff;
    int zero_count;
    i = 0;
    while ((len1 - i) >= len2)     // доки залишок ще можна поділити на дільник
    {
        zero_count = sub_poly(poly11 + i, poly22, len2, mod);   // віднімаємо коефіцієнти
        i += zero_count;
    }
    std::vector<int> r;
    for (i; i < len1; i++) r.push_back(poly11[i]);
    // if (r.size() == 0) r.push_back(0);
    return r;
}
//Функція gcd повторно викликає функцію subtract_polys до тих пір,
// поки залишок не дорівнює нулю. Останній ненульовий залишок є НСД двох вхідних поліномів.
std::vector<int> Gcd::gcd(std::vector<int> a, std::vector<int> b, int mod) {
    while (!b.empty()) {
        /*for (int i = 0; i < a.size(); i++) {
            cout << a[i] << "x^" << a.size() - i - 1;
            if (i < a.size() - 1) cout << " + ";
        }
        cout << ", ";
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << "x^" << b.size() - i - 1;
            if (i < b.size() - 1) cout << " + ";
        }
        cout << ") = ";
        cout << endl;*/
        std::vector<int> r = subtract_polys(a, b, mod);
        a = b;
        b = r;
    }
    return a;
}
//Функція division викликає функцію subtract_polys для виконання ділення поліномів,
// а потім повертає вектор divisionCoefs.
std::vector<int> Gcd::division(std::vector<int> poly1, std::vector<int> poly2, int mod) {
    divisionCoefs.clear();
    subtract_polys(poly1, poly2, mod);
    return divisionCoefs;
}

std::vector<int> Gcd::run(std::vector<int> a, std::vector<int> b, int mod) {
    std::vector<int> g = gcd(a, b, mod);
    return g;
}
