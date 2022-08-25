#include "QuadraticEquation.h"

int main() 
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    InputProcessing(&a, &b, &c);

    int solver = QuadraticSolver(a, b, c, &x1, &x2);

    SolutionsProcessing(&x1, &x2, solver);
}