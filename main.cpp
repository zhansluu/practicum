/**
* ��������� ��������� ������ ���������� ��������� ������� ��������, ������� �������, ���������������� ������� ������� � ������� �������
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

    cout << "������� 1. ������������ ������� ���������� ���������" << endl;
    cout << "���� ������� f(x)=2^x-2cos(x)" << endl << "[A, B] = [-8; 10]" << endl << "epsilon = 10^(-6)" << endl;

    /*���� ������*/
    cout << "������� �������� A(������ �������): ";
    cin >> a;
    cout << endl << "������� �������� B(������� �������): ";
    cin >> b;
    if (b < a)
        swap(a,b);
    cout << endl << "������� �����������: ";
    cin >> epsilon;


    /*��������� ������ (����������� �����)

    ���� ������� ������ ���� ���� �� ������ �������, �� �� ��������� ���� ������� �� ������������ ��� ���������� �������
    ��� ��� ��� ���� ������.*/
    size_t n, counter = 0;
    double h, x1[10000], x2[10000], y1[10000], y2[10000];

    cout << endl << "������� ����� ��������� ������� n (����� ��������, > 1): ";
    cin >> n;
    while (n <= 1)
    {
        cout << "������������ �������� n. ������� ����� ��������� ������� (����� ��������, > 1)" << endl;
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
    cout << "����� �������� �������� �����: " << counter << endl << endl;

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
