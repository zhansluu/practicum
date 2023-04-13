#ifndef NEWTON_METHOD_H_INCLUDED
#define NEWTON_METHOD_H_INCLUDED
#include "functions.h"
#include <iomanip>

/*Проверка условий сходимости метода Ньютона
    1)f(a)*f(b) < 0 - выполняется изначально, так как сначала мы отделяем корни
    2)f'(x),f''(x) - сохраняют знаки на [a,b]
    3)f(x_0)f''(x_0) > 0 , x_0 in [a,b]
    */

/*Метод Ньютона (касательных)*/
    void newton_method (double a, double b, double epsilon)
    {
        std::cout << "Метод Ньютона" << std::endl;
        if (getDerivativeValue(a)*getDerivativeValue(b)<0 ||
            getSecondDerivativeValue(a)*getSecondDerivativeValue(b)<0)
                std::cout << "Теорема о сходимости не применима, так как производная меняет знак на концах отрезка" << std::endl << std::endl;
        else
        {
            int random = rand()*(b-a)/32767;
            size_t counter = 0;
            double previous_solut = a + random*(b-a);

            while(getSecondDerivativeValue(previous_solut) * func(previous_solut) <= 0)
                previous_solut = a + rand()*(b - a)/32767;

            double current_solut = previous_solut -(func(previous_solut)/getDerivativeValue(previous_solut));

            while(fabs(current_solut - previous_solut) >= epsilon)
            {
                previous_solut = current_solut;
                current_solut = previous_solut - (func(previous_solut) / getDerivativeValue(previous_solut));
                ++counter;
            }

            std::cout << "x = " << std::setprecision(15) << current_solut << std::endl;
            std::cout << "|x_m -  x_{m-1}| = " << fabs(current_solut - previous_solut) << std::endl;
            std::cout << "Абсолютный модуль невязки для приближенного решения: " << fabs(func(current_solut) - 0) << std::endl;
            std::cout << "Количество шагов для достижения точности эпсилон: " << counter << std::endl << std::endl;
        }
    }

#endif // NEWTON_METHOD_H_INCLUDED
