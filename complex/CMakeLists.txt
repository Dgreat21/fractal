cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

project(COMPLEX VERSION 1.0 LANGUAGES C)

add_library(complex STATIC)

set(${PROJECT_NAME}_INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/includes
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

include_directories(${LIBFT_INCLUDE_DIRS})

add_subdirectory(src)