cmake_minimum_required(VERSION 3.0)

project(COMPLEX VERSION 1.0 LANGUAGES C)

set(sources
        src/cmplx_hard_math.c
        src/cmplx_simple_operation.c
        src/set_num.c)

include_directories(includes)

add_library(libcomp STATIC
        ${sources})

