//
// Created by MBTSKY on 24.10.2019.
//

#include <stdlib.h>
#include <sys/wait.h>

#include <stdio.h>
#include "compute_distance.h"
#include "types.h"
void readFromStream(FILE* in, Points* arr, size_t size) {

    for(size_t i = 0; i < size; i++)
        fscanf(in, "%d", (arr + i));
}

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
    //@TODO dynamically
    const size_t cores = 2;
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
            //close(fd[2 * i]);
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

        totalLength += curLength;
    }
    //free(fd);

    return totalLength;
}