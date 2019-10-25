#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "compute_distance.h"
#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length int32_t

#define ARR_SIZE 26214400

int main() {

    Points* test = calloc(3, sizeof(Point));
    test[0] = 0b10000000100000000000000000000000;
    test[1] = 0b000000000000000000000000000000;
    test[2] = 0b0000010000001000000000000000001;
    printf("%lf", computeTotalDistance(test, 3));
    return 0;
}