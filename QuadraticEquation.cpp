#include "QuadraticEquation.h"

int InputProcessing(double* a, double* b, double* c)                                //Обработка ввода
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Enter the coefficients of the quadratic equation: ");

    while (scanf("%lf%lf%lf", a, b, c) != 3)  
    {
        ClearInputBuffer();
        printf("You did something wrong. "
               "Enter the coefficients of the quadratic equation one more time: ");
    }
    return 0;
}

int LinearSolver(double b, double c, double* x1)                                    //Решение линейного уравнения           
{
    if (b == 0)
        return (c == 0) ? InfinitiveRoots : NoRoots;
    else 
    {
        *x1 = -c / b;
        if (c == 0)
            *x1 = 0;
            return OneRoot;
        return OneRoot;
    }
}

int QuadraticSolver(double a, double b, double c, double* x1, double* x2)           //Решение квадратного уравнения
{
    if (a == 0)
    {
        LinearSolver(b, c, x1);
    }
    else
    {
        float D = b*b - 4*a*c;

        if (D < 0)
            return NoRoots;

        else if (D == 0) 
        {
            *x1 = -b / (2*a);
            if (b == 0)
                *x1 = 0;
                return OneRoot;
            return OneRoot;
        }

        else
        {
            if (c == 0)
            {
                *x1 = 0;
                *x2  = -b / a;
                if (b == 0)
                    *x1 = 0;
                    return OneRoot;
                if (FloatComparison(*x1, *x2) == 1)
                    return OneRoot;
                else
                    return TwoRoots;
            }
            else
            {
                *x1 = (-b + sqrt(D))/(2*a);
                *x2  = (-b - sqrt(D))/(2*a);
                if (FloatComparison(*x1, *x2) == 1)
                    return OneRoot;
                else
                    return TwoRoots;
            }
        }
    }
    return 0;
}

void SolutionsProcessing(double* x1, double* x2, int solver)                        //Обработка полученных корней
{
    switch(solver)
    {
        case NoRoots: printf("No solution.\n"); break;
        case InfinitiveRoots: printf("Infinitive solutions.\n"); break; 
        case OneRoot: printf("One solution x = %f.\n", *x1); break;
        case TwoRoots: 
        {
            if (*x2 >= *x1)
                printf("Two solutions: x1 = %f and x2 = %f.\n", *x1, *x2);
            else
                printf("Two solutions: x1 = %f and x2 = %f.\n", *x2, *x1);
            break;
        }
        default: printf("You did something wrong.\n"); break;
    }
}
