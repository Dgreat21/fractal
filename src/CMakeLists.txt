cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

target_sources(fractol PUBLIC
        draw.c
        fractol.c
        init.c
        key_press.c
        main.c
        fractal_mandelbrot.c
        fractal_julia.c
        fractal_burning_ship.c
        struct.c)