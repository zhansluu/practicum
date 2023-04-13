#ifndef BISECTION_METHOD_H_INCLUDED
#define BISECTION_METHOD_H_INCLUDED
#include "functions.h"
#include <iomanip>

/*����� �������� (����������� �������)

    ����� ������� �������, ���� ��� ����� �� ����� ������ 2*epsilon.
    ��� ������ �� �������� ����� �������, ����� X, ������� ��������� �� �������� ������������� �������.*/
    void bisection_method (double a, double b, double epsilon)
    {
        std::cout << "����� �������� (����������� �������)" << std::endl;
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
        std::cout << "����� ���������� �������: " << delta << std::endl;
        std::cout << "���������� �������� ������� ��� ������������� �������: " << fabs(func(X) - 0) << std::endl;
        std::cout << "���������� ����� ��� ���������� �������� �������: " << counter << std::endl << std::endl;
    }

#endif // BISECTION_METHOD_H_INCLUDED
