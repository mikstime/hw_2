//
// Created by MBTSKY on 24.10.2019.
//

#define Points int32_t
#define Point int16_t
#define Coordinate int8_t
#define Length double

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/sysinfo.h>
#include "compute_distance.h"

double computeLengthSingleThreaded(Points* arr, size_t size) {
    return computeTotalDistance(arr, size);
}

void prepare_for_run(const size_t* const arr_size, const size_t* const num_cores,
        size_t* active_cors, size_t* arr_step) {
    if (*arr_size < *num_cores) {
        *active_cors = *arr_size;
        *arr_step = 1;
    } else {
        *active_cors = *num_cores;
        *arr_step = *arr_size / *num_cores;
    }
}

double static_run(const Points* const arr, const size_t size) {
    Length curLength = 0, totalLength = 0;

    const size_t cores = get_nprocs_conf();
    size_t active_cores, chunk_size;

    prepare_for_run(&size, &cores, &active_cores, &chunk_size);
    int status = 0;
    pid_t wpid = 0, pid = 0;
    //Useful vars
    int fd[2 * active_cores];
    for(size_t i = 0; i < active_cores; i++)
        pipe(&fd[2 * i]);

    for(size_t i = 0; i < active_cores; ++i) {
        pid = fork();
        if( pid == 0) {
            // Child process
            curLength = computeTotalDistance((arr + i), chunk_size);
            write(fd[2 * i + 1], &curLength, sizeof(curLength));
            close(fd[2 * i + 1]);

            exit(EXIT_SUCCESS);
        } else {

            close(fd[2 * i + 1]);
        }
    }

    for(size_t i = chunk_size - 1; i < size - 1; i+= chunk_size) {
        totalLength += distance((Point)(arr[i]), (Point)(arr[i + 1] >> 16));
    }

    if(size % chunk_size != 0) {
        totalLength += computeTotalDistance((arr + size - (size % chunk_size) - 1), size % chunk_size);
    }

    while (wpid = wait(&status) > 0);

    for(size_t i = 0; i < active_cores; i++) {
        read(fd[2 * i ], &curLength, sizeof(size_t));
        close(fd[2 * i]);
        totalLength += curLength;
    }

    return totalLength;
}