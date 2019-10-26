#define CATCH_CONFIG_MAIN

#define Point int16_t
#define Points int32_t
#define Coordinate int8_t
#define Length double
#include <dlfcn.h>
#include "catch.hpp"
extern "C" {
#include "dynamic.h"
#include "static.h"
};

void *library;
TEST_CASE("Two Points", "Single Process algorithm") {
    library = dlopen("dynamic_lib.so", RTLD_LAZY);
    struct exportVtable *imports;
    REQUIRE(!!library == 1);
    imports = dlsym(library, "exports");
    REQUIRE(!!imports == 1);

    Points* points = new Points(1);

    points[0] = 0b10000000100000000000000000000000;
    REQUIRE( imports->computeLength(points, 1) == static_run(points, 1));
    delete(points);
}
TEST_CASE("Four points", "Single Process algorithm") {

    library = dlopen("dynamic_lib.so", RTLD_LAZY);
    struct exportVtable *imports;
    REQUIRE(!!library == 1);
    imports = dlsym(library, "exports");
    REQUIRE(!!imports == 1);

    Points* points = new Points(2);

    points[0] = 0b10000000100000000000000000000000;
    points[1] = 0b1000000010000000111111101111111;
    REQUIRE( imports->computeLength(points, 2) == static_run(points, 2));
    delete(points);
}
TEST_CASE("Four Points №2", "Single Process algorithm") {

    library = dlopen("dynamic_lib.so", RTLD_LAZY);
    struct exportVtable *imports;
    REQUIRE(!!library == 1);
    imports = dlsym(library, "exports");
    REQUIRE(!!imports == 1);

    Points* points = new Points(2);

    points[0] = 0b10000000100000000000000000000000;
    points[1] = 0b1000000010000000111111101111111;
    REQUIRE( imports->computeLength(points, 2) == static_run(points, 2));
    delete(points);
}