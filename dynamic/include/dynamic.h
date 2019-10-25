//
// Created by MBTSKY on 26.10.2019.
//

#ifndef HW_2_DYNAMIC_H
#define HW_2_DYNAMIC_H

#include <stdlib.h>

#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length double

struct exportVtable {
    double (*computeLength)(const Points*const arr, size_t size);
};
#endif //HW_2_DYNAMIC_H
