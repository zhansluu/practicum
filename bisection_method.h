#ifndef BISECTION_METHOD_H_INCLUDED
#define BISECTION_METHOD_H_INCLUDED
#include "functions.h"
#include <iomanip>

/*Метод бисекции (половинного деления)

    Делим отрезок пополам, пока его длина не будет меньше 2*epsilon.
    Как только мы достигли этого условия, берем X, который находится на середине получившегося отрезка.*/
    void bisection_method (double a, double b, double epsilon)
    {
        std::cout << "Метод бисекции (половинного деления)" << std::endl;
        double c, X, delta;
        size_t counter = 0;

        while ((b - a) > 2*epsilon)
        {
            c = (a+b)/2;
            if (func(a)*func(c) <= 0)
                b = c;
            else
                a = c;
            counter++;
        }
        X = (a + b)/2;
        delta = (b - a)/2;
        std::cout << "x = " << std::setprecision(15) << X << std::endl;
        std::cout << "Длина последнего отрезка: " << delta << std::endl;
        std::cout << "Абсолютная величина невязки для приближенного решения: " << fabs(func(X) - 0) << std::endl;
        std::cout << "Количество шагов для достижения точности эпсилон: " << counter << std::endl << std::endl;
    }

#endif // BISECTION_METHOD_H_INCLUDED
