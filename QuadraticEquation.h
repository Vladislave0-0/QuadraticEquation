#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

const double FloatConstant = 1E-6;

enum Roots
{
    NoRoots         = 0,
    OneRoot         = 1,
    TwoRoots        = 2, 
    InfinitiveRoots = 3,
};

int InputProcessing(double* a, double* b, double* c);

int LinearSolver(double b, double c, double* x1);

int QuadraticSolver(double a, double b, double c, double* x1, double* x2);

void SolutionsProcessing(double* x1, double* x2, int solver);


#endif // QUADRATIC_EQUATION_H
