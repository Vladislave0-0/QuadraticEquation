#ifndef COMMON_H
#define COMMON_H

//=====================================================================================

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

//=====================================================================================
/**
 * @brief notes comparing variables with type float.
 */
enum ComparisonResult
{
    Under = -1,
    Equal =  0,
    Over  =  1,
};

//=====================================================================================
/**
 * @brief FloatComparison - takes 2 root of the quadratic equation. 
 *        Compares variables with type float.
 * 
 * @param x1 First root of the quadratic equation.
 * @param x2 Second root of the quadratic equation.
 * @return value of enam
 * @see enum ComparisonResult
 */
int FloatComparison(const double x1, const double x2);

//=====================================================================================
/**
 * @brief ClearInputBuffer - сalled in a function InputCoeff to erase the input when the 
 *        user entered something wrong.
 */
void ClearInputBuffer();

//===========================================================================

#endif // COMMON_H
