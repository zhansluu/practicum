#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/*Описание рабочей функции*/
    double func(double x)
    {
        return pow(2, x) - 2*cos(x);
    }

    double getDerivativeValue (double x)
    {
        return log(2)*pow(2,x) + 2*sin(x);
    }

    double getSecondDerivativeValue (double x)
    {
        return log(2)*log(2)*pow(2,x) + 2*cos(x);
    }

#endif // FUNCTIONS_H_INCLUDED
