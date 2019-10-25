//
// Created by MBTSKY on 25.10.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "static.h"

#define ARR_SIZE 2
int main() {

    Points* array = calloc(ARR_SIZE, sizeof(Points));

    array[0] = 0b10000000100000000000000000000000;
    array[1] = 0b1000000010000000111111101111111;
    //printf("%d %d", array[0], array[1]);
//            free(array);
//            return EXIT_FAILURE;
    Length res = static_run(array, ARR_SIZE);
    printf("\n%lf\n", res);

}