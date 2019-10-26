#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/dynamic.h"

#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length double
void *library;

int main() {
    //libdn_lib.so
    library = dlopen("dynamic_lib.so", RTLD_LAZY);
    struct exportVtable *imports;
    if (!library) {
        return EXIT_FAILURE;
    }

    imports = dlsym(library, "exports");
    if (!imports) {
        return EXIT_FAILURE;
    }
    size_t size;
    if(scanf("%zu", &size))
        return EXIT_FAILURE;
    Points* array = calloc(size, sizeof(Points));

    for(size_t i = 0; i < size; i++)
        scanf("%i", &array[i]);

    Length res = imports->computeLength(array, size);
    printf("%lf", res);
    free(array);
    return 0;
}