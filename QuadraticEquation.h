#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

//==============================================================================================
/**
 * @brief Notes the number of roots found.
 * 
 */
enum Roots
{
    NoRoots         = 0,
    OneRoot         = 1,
    TwoRoots        = 2, 
    InfinitiveRoots = 3,
};

//==============================================================================================
/**
 * @brief InputCoeff - takes 3 pointer to quadratic coefficients. 
 *        It also checks for the correctness of the input.
 * 
 * @param a Pointer to coefficient at x^2.
 * @param b Pointer to coefficient at x^1.
 * @param c Pointer to coefficient at x^0.
 */
void InputCoeff(double* a, double* b, double* c);

//==============================================================================================
/**
 * @brief QuadraticSolver - takes 3 quadratic coefficients and 
 *        2 pointers to quadratic equation solutions.
 * 
 * @param a Coefficient at x^2.
 * @param b Coefficient at x^1.
 * @param c Coefficient at x^0.
 * @param x1 Pointer to the first root of the quadratic equation.
 * @param x2 Pointer to the second root of the quadratic equation.
 * 
 * @return one of the values of enum. 
 * @see enum Roots.
 */
int QuadraticSolver(const double a, const double b, const double c, double* x1, double* x2);

//==============================================================================================
/**
 * @brief LinearSolver - a special case of a function QuadraticSolver if a == 0.
 *        Takes 2 quadratic coefficients b and c and pointer to the root of the
 *        quadratic equation.
 * 
 * @param b Coefficient at x^1.
 * @param c Coefficient at x^0.
 * @param x1 Pointer to the root of the quadratic equation.
 * 
 * @return values of enum. 
 * @see enum Roots.
 */
int LinearSolver(const double b, const double c, double* x1);

//==============================================================================================
/**
 * @brief SolutionsProcessing - takes 2 pointers to quadratic equation solutions
 *        and value nRoots. processes the data obtained after solving the quadratic 
 *        equation and displays the number of roots, and then the roots themselves.
 * 
 * @param x1 Pointer to the first root of the quadratic equation.
 * @param x2 Pointer to the second root of the quadratic equation.
 * @param nRoots Сalls a function QuadraticSolver.
 */
void SolutionsProcessing(const double* x1, const double* x2, const int nRoots);

//==============================================================================================
/**
 * @brief Swap - performs the exchange of variable values.
 * 
 * @param x1 First (and smallest) root of the equation
 * @param x2 Second (and biggest) root of the equation
 */
int Swap(double* x1, double* x2);

//==============================================================================================

#endif // QUADRATIC_EQUATION_H
