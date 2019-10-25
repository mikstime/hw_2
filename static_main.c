//
// Created by MBTSKY on 25.10.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "static.h"

int main() {
    size_t size;
    if(scanf("%zu", &size) != 1)
        return EXIT_FAILURE;
    Points* array = calloc(size, sizeof(Points));
    for(size_t i = 0; i < size; i++)
        if(scanf("%i", &array[i]) != 1) {
            free(array);
            return EXIT_FAILURE;
        }
    Length res = static_run(array, size);
    printf("\n%lf\n", res);
    free(array);
    return 0;
}