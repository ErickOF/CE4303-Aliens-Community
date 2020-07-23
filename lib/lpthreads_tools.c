
#ifndef PROJECT2_LIB_LPTHREADS_TOOLS_C
#define PROJECT2_LIB_LPTHREADS_TOOLS_C

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define FALSE 0
#define TRUE 1

// Functions
/**
 *  This function manages errors on memory allocation
 * 
 *  Params:
 *      size_t size - Size in bytes of the allocated memory space.
 * 
 *  Returns
 *      void* ptr to memory.
 */
void* allocate_mem(size_t size){

    void* mem = malloc(size);
    if (!mem) {
        perror("allocate_mem");
        exit(EXIT_FAILURE);
    }

    return mem;

}


/**
 *  This function uses clone system call to create a thread and manages errors
 * 
 *  Params:
 *      size_t size - Size in bytes of the allocated memory space.
 * 
 *  Returns
 *      int pid to the new thread.
 */
int clone_call(     int (*target_function) (void*), 
                    void* stack, 
                    int flags, 
                    void* args){

    // Launch the thread
    // Set it to stop and start it later when the structure is ready
    int pid = clone(target_function, stack, flags, args);
    if (pid == -1) {
        perror("clone_call");
        exit(EXIT_FAILURE);
    }

    return pid;

}



#endif /* PROJECT2_LIB_LPTHREADS_TOOLS_C */