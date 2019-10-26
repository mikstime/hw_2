#define CATCH_CONFIG_MAIN

#include <stdlib.h>
#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length double

#include "../catch.hpp"
extern "C" {
#include "static.h"
};

TEST_CASE("Two Points", "Single Process algorithm") {

    Points* points = new Points(1);

    points[0] = 0b10000000100000000000000000000000;
    REQUIRE( computeLengthSingleThreaded(points, 1) == 128 * sqrt(2));
    delete(points);
}
TEST_CASE("Four points", "Single Process algorithm") {

    Points* points = new Points(2);

    points[0] = 0b10000000100000000000000000000000;
    points[1] = 0b1000000010000000111111101111111;
    REQUIRE( computeLengthSingleThreaded(points, 2) == 255 * sqrt(2));
    delete(points);
}
TEST_CASE("Four Points №2", "Single Process algorithm") {

    Points* points = new Points(2);

    points[0] = 0b10000000100000000000000000000000;
    points[1] = 0b1000000010000000111111101111111;
    REQUIRE( computeLengthSingleThreaded(points, 2) == 255 * sqrt(2));
    delete(points);
}
TEST_CASE("Two Points_multi", "Multi Process algorithm") {

    Points* points = new Points(1);

    points[0] = 0b10000000100000000000000000000000;
    REQUIRE( static_run(points, 1) == 128 * sqrt(2));
    delete(points);
}
TEST_CASE("Four points_multi", "Multi Process algorithm") {

    Points* points = new Points(2);

    points[0] = 0b10000000100000000000000000000000;
    points[1] = 0b1000000010000000111111101111111;
    REQUIRE( static_run(points, 2) == 255 * sqrt(2));
    delete(points);
}
TEST_CASE("Four Points №2_multi", "Multi Process algorithm") {

    Points* points = new Points(2);

    points[0] = 0b10000000100000000000000000000000;
    points[1] = 0b1000000010000000111111101111111;
    REQUIRE( static_run(points, 2) == 255 * sqrt(2));
    delete(points);
}