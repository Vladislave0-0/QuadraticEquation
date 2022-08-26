#include "QuadraticEquation.h"

void TestingSolutions();

int main() 
{
    double a  = NAN, b  = NAN, c  = NAN, x1 = NAN, x2 = NAN;
    
    InputCoeff(&a, &b, &c);

    int nRoots = QuadraticSolver(a, b, c, &x1, &x2);

    SolutionsProcessing(&x1, &x2, nRoots);

    printf("\n\n");
    
    TestingSolutions();
}
