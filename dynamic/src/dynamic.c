//
// Created by MBTSKY on 26.10.2019.
//
#include "../include/dynamic.h"
#include "compute_distance.h"
#include <stdlib.h>
#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length double
double computeLength(const Points*const arr, size_t size) {

    return computeTotalDistance(arr, size);
}
struct exportVtable exports = {*computeLength};