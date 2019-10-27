//
// Created by MBTSKY on 24.10.2019.
//
#ifndef STATIC_VERSION_LIB_H
#define STATIC_VERSION_LIB_H

#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length double
#include <math.h>
#include <stdlib.h>
//*******************************
Length distance(Point p1, Point p2);
double computeTotalDistance(const Points *array, size_t size);
#endif //STATIC_VERSION_LIB_H
