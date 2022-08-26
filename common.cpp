#include "common.h"

//===========================================================================

const double FloatConstant = 1E-6;

//===========================================================================

int FloatComparison(const double x1, const double x2)
{
    if (fabs(x1 - x2) <= FloatConstant)
        return Equal;
    else 
        return ((x1-x2) > FloatConstant) ? Over : Under;
}

//===========================================================================

void ClearInputBuffer()
{
    while (getchar() != '\n') 
        ;
}
