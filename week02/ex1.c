/**
limits.h need for get INT_MAX
float.h need for get FLT_MAX and DBL_MAX
use sizeof() to get size of variable
**/

#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    int _int = INT_MAX;
    float _float = FLT_MAX;
    double _double = DBL_MAX;

    printf("int max: %d  size of int: %lu\n", _int, sizeof(_int));
    printf("float max: %f  size of float: %lu\n", _float, sizeof(_float));
    printf("double max: %lf  size of double: %lu\n", _double, sizeof(_double));
}
