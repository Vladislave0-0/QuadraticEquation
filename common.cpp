#include "common.h"

const double FloatConstant = 1E-6;

int FloatComparison(double x1, double x2)
{
    return (fabs((x1) - (x2)) <= FloatConstant);
}

void ClearInputBuffer()
{
    while (getchar() != '\n') {};
}
