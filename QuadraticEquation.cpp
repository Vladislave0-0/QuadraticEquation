#include "QuadraticEquation.h"

//===================================================================================================

void InputCoeff(double* a, double* b, double* c)
{
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    printf("Hello. This program solves quadratic equations.\n"
           "Please enter 3 coefficients a, b and c of the quadratic equation ax^2 + bx + c = 0 separated by a space: ");

    while (scanf("%lf %lf %lf", a, b, c) != 3)  
    {
        ClearInputBuffer();
        printf("You did something wrong. You will be fired.\n"
               "Enter the coefficients of the quadratic equation one more time to prevent this: ");
    }
}

//===================================================================================================

int QuadraticSolver(const double a, const double b, const double c, double* x1, double* x2)           
{
    if (FloatComparison(a, 0) == Equal)
    {
        return LinearSolver(b, c, x1);
    }
    else
    {
        double D = b*b - 4*a*c;

        if (FloatComparison(D, 0) == Under)
            return NoRoots;

        else if (FloatComparison(D, 0) == Equal) 
        {
            *x1 = -b / (2*a);
            if (FloatComparison(b, 0) == Equal)
                *x1 = 0;
            return OneRoot;
        }

        else
        {
            if (FloatComparison(c, 0) == Equal)
            {
                *x1 = 0;
                *x2  = -b / a;

                if (FloatComparison(b, 0) == Equal)
                {
                    *x1 = 0;
                    return OneRoot;
                }
                if (FloatComparison(*x1, *x2) == Equal)
                    return OneRoot;
                else
                    {
                        return Swap(x1, x2);
                    }
            }
            else
            {
                /* sqrt_*/D = sqrt(D);
                *x1 = (-b + /* sqrt_*/D) / (2*a);
                *x2 = (-b - /* sqrt_*/D) / (2*a);
                
                if (FloatComparison(*x1, *x2) == Equal)
                    return OneRoot;
                else
                    {
                        return Swap(x1, x2);
                    }
            }
        }
    }
    return 0;
}

//===================================================================================================

int LinearSolver(const double b, const double c, double* x1)                                               
{
    if (FloatComparison(b, 0) == Equal)
        return (FloatComparison(c, 0) == Equal) ? InfinitiveRoots : NoRoots;

    else 
    {
        *x1 = -c / b;
        if (FloatComparison(c, 0) == Equal)
            *x1 = 0;

        return OneRoot;
    }
}

//===================================================================================================

int Swap(double* x1, double* x2)
{
    double swap = *x1;
    if (FloatComparison(*x1, *x2) == Under)
        return TwoRoots;
    else
        *x1 = *x2;
        *x2 = swap;
        return TwoRoots;
}

//===================================================================================================

void SolutionsProcessing(const double* x1, const double* x2, const int nRoots)                        
{
    switch (nRoots)
    {
        case NoRoots:         printf("No solution.\n");                                  break;
        case InfinitiveRoots: printf("Infinitive solutions.\n");                         break; 
        case OneRoot:         printf("One solution x = %f.\n", *x1);                     break;
        case TwoRoots:        printf("Two solutions: x1 = %f and x2 = %f.\n", *x1, *x2); break;
        default:              assert(0 && "Undefined number of root. And I'm Groot.");   break;
    }
}
