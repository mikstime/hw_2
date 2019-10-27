#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic.h"
#include "static.h"

#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length double

void *library;
#define ARR_SIZE 10000
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
    Points* array = calloc(ARR_SIZE, sizeof(Points));

    Points p;
    for(size_t i = 0; i < ARR_SIZE; i++) {
        array[i] = rand();

    }

    Length res1 = imports->computeLength(array, ARR_SIZE);
    Length res2 = static_run(array, ARR_SIZE);
    printf("%s", (res1 == res2 ? "Equal results" : "Something is wrong"));
    free(array);
    return EXIT_SUCCESS;
}