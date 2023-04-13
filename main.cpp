/**
* Программа позволяет решить нелинейные уравнения методом бисекций, методом Ньютона, модифицированным методом Ньютона и методом секущих
*/
#include <iostream>
#include <cmath>
#include "modified_newton_method.h"
#include "newton_method.h"
#include "secant_method.h"
#include "bisection_method.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(0, "Russian");
    double a, b, epsilon;

    cout << "Задание 1. Приближенное решение нелинейных уравнений" << endl;
    cout << "Дана функция f(x)=2^x-2cos(x)" << endl << "[A, B] = [-8; 10]" << endl << "epsilon = 10^(-6)" << endl;

    /*Ввод данных*/
    cout << "Введите значение A(нижнюю границу): ";
    cin >> a;
    cout << endl << "Введите значение B(верхнюю границу): ";
    cin >> b;
    if (b < a)
        swap(a,b);
    cout << endl << "Введите погрешность: ";
    cin >> epsilon;


    /*Отделение корней (Локализация корня)

    Если функция меняет свой знак на концах отрезка, то мы добавляем этот отрезок на рассмотрение при дальнейшем решении
    Так как там есть корень.*/
    size_t n, counter = 0;
    double h, x1[10000], x2[10000], y1[10000], y2[10000];

    cout << endl << "Введите число разбиения отрезка n (целое значение, > 1): ";
    cin >> n;
    while (n <= 1)
    {
        cout << "Некорректное значение n. Введите число разбиения отрезка (целое значение, > 1)" << endl;
        cin >> n;
    }

    h = (b-a)/n;
    x1[counter] = a;
    x2[counter] = x1[counter] + h;
    while (x2[counter] <= b)
    {
        y1[counter] = func(x1[counter]);
        y2[counter] = func(x2[counter]);
        if (y1[counter]*y2[counter] <= 0)
        {
            cout <<"["<< x1[counter] <<','<< x2[counter] <<"]"<< endl;
            counter++;
            x1[counter] = x2[counter-1];
            x2[counter] = x2[counter-1] + h;
        }
        else
        {
            x1[counter] = x2[counter];
            x2[counter] = x2[counter] + h;
        }
    }
    cout << "Число отрезков перемены знака: " << counter << endl << endl;

    size_t counter_2 = 0;
    do
    {
        bisection_method (x1[counter_2], x2[counter_2], epsilon);
        newton_method (x1[counter_2], x2[counter_2], epsilon);
        modified_newton_method (x1[counter_2], x2[counter_2], epsilon);
        secant_method (x1[counter_2], x2[counter_2], epsilon);
        cout << "----------------------------------" << endl;
        counter_2 ++;
    } while (counter_2 != counter);

    return 0;
}
