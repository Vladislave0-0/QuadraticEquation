#define NDEBUG
//====================================================================

#include "QuadraticEquation.h"
#include "UnitTest.h"

//====================================================================

int main() 
{
#ifndef NDEBUG
    TestingSolutions();
#else
    double a  = NAN, b  = NAN, c  = NAN, x1 = NAN, x2 = NAN;
    
    InputCoeff(&a, &b, &c);

    int nRoots = QuadraticSolver(a, b, c, &x1, &x2);

    SolutionsProcessing(&x1, &x2, nRoots);
    
#endif 
    return 0;
}
