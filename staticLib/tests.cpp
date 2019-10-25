#define CATCH_CONFIG_MAIN

#define Point int16_t
#define Points int32_t
#define Coordinate int8_t
#define Length double

#include "catch.hpp"
#include <iostream>
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
//TEST_CASE("Many points №2", "Single Process algorithm") {
//
//    Points* points = new Points(6);
//
//    points[0] = 0b10000000100000000000000000000000;
//    points[1] = 0b1000000010000000111111101111111;
//    points[2] = 0b10000000100000000000000000000000;
//    points[3] = 0b1000000010000000111111101111111;
//    points[4] = 0b10000000100000000000000000000000;
//    points[5] = 0b1000000010000000111111101111111;
//
//    REQUIRE( computeLengthSingleThreaded(points, 6) == 255 * sqrt(2) * 3 + 128 * sqrt(2) * 4);
//    delete(points);
//}
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
//TEST_CASE("Many points №2_multi", "Multi Process algorithm") {
//
//    Points* points = new Points(6);
//
//    points[0] = 0b10000000100000000000000000000000;
//    points[1] = 0b1000000010000000111111101111111;
//    points[2] = 0b10000000100000000000000000000000;
//    points[3] = 0b1000000010000000111111101111111;
//    points[4] = 0b10000000100000000000000000000000;
//    points[5] = 0b1000000010000000111111101111111;
//
//    REQUIRE( static_run(points, 6) == 255 * sqrt(2) * 3);
//    delete(points);
//}