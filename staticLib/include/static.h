//
// Created by MBTSKY on 24.10.2019.
//

#ifndef HW_2_STATIC_H
#define HW_2_STATIC_H
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "compute_distance.h"
#define Points int32_t
void readFromStream(FILE* in, Points* arr, size_t size);
double computeLengthSingleThreaded(Points* arr, size_t size);
double static_run(Points* arr, size_t size);
#endif //HW_2_STATIC_H
