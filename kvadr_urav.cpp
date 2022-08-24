#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double FloatConstant = 10E-6;

enum Roots
{
    NoRoots         = 0,
    OneRoot         = 1,
    TwoRoots        = 2, 
    InfinitiveRoots = 3,
};

int FloatComparison(double x1, double x2)
{
    return fabs(x1 - x2) <= FloatConstant; 
}

int LinearSolver(double b, double c, double* x1)
{
    if (b == 0)
        return (c == 0) ? InfinitiveRoots : NoRoots;
    else 
    {
        *x1 = -c / b;
        return OneRoot;
    }
}

int QuadraticSolver(double a, double b, double c, double* x1, double* x2) 
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
            return OneRoot;
        }

        else
        {
            if (c == 0)
            {
                *x1 = 0;
                *x2  = -b / a;
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

void SolutionsProcessing(double* x1, double* x2, int solver)
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

void ClearInputBuffer()
{
    while (getchar() != '\n') {};
}

int main() 
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    printf("Enter the coefficients of the quadratic equation: ");

    while (scanf("%lf%lf%lf", &a, &b, &c) != 3)  
    {
        ClearInputBuffer();
        printf("You did something wrong"
               "Enter the coefficients of the quadratic equation: ");
    }

    int solver = QuadraticSolver(a, b, c, &x1, &x2);

    SolutionsProcessing(&x1, &x2, solver);
}