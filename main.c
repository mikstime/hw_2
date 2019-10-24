#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Point int32_t
#define Coordinate int32_t
#define Length int32_t

Coordinate separateDigits(Point p, uint32_t from, uint32_t to) {
    return ((p / (uint32_t)pow(10, from))) % (uint32_t)pow( 10, to - from );
}
Coordinate getX1(Point p) {
    return separateDigits(p, 0, 2);
}
Coordinate getY1(Point p) {
    return separateDigits(p, 2, 4);
}
Coordinate getX2(Point p) {
    return separateDigits(p, 4, 6);
}
Coordinate getY2(Point p) {
    return separateDigits(p, 6, 8);
}
Length dist_squared(Point p) {

    Coordinate x1, x2, y1, y2;
    x1 = getX1(p);
    x2 = getX2(p);
    y1 = getY1(p);
    y2 = getY2(p);
    Coordinate deltaX, deltaY;
    deltaX = x2 - x1;
    deltaY = y2 - y1;
    return deltaX * deltaX + deltaY * deltaY;
}
int main() {
    printf("Hello, World!\n");
    return 0;
}