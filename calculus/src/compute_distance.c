//
// Created by MBTSKY on 24.10.2019.
//
#include "types.h"
double distance(Point p1, Point p2) {
    Coordinate x1, x2, y1, y2;
    x1 = p1 >> 8;
    y1 = p1;
    x2 = p2 >> 8;
    y2 = p2;

    Length deltaX, deltaY;
    deltaX = x2 - x1;
    deltaY = y2 - y1;

    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

double computeTotalDistance(const int32_t* const array, size_t size) {

    Point prev, next;
    double dist = 0;

    prev = (*array) >> 16;
    next = *array;
    size_t i = 1;

    while(i < 2 * size) {

        dist+= distance(prev, next);
        prev = next;
        ++i;
        if(i % 2 == 1) {
            next = *(array + i / 2);
        } else {
            next = *(array + i / 2) >> 16;
        }

    }

    return dist;
}