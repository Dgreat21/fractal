cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(complex PUBLIC
        cmplx_hard_math.c
        cmplx_simple_operation.c
        set_num.c
        abs.c)