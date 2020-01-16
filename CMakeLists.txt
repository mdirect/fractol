cmake_minimum_required(VERSION 3.15)
project(fractol C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(minilibx_macos)

add_library(libmlx STATIC
        minilibx_macos/mlx_shaders.c
        minilibx_macos/mlx_new_window.m
        minilibx_macos/mlx_init_loop.m
        minilibx_macos/mlx_new_image.m
        minilibx_macos/mlx_xpm.c
        minilibx_macos/mlx_int_str_to_wordtab.c)

add_compile_options (-Wall -Werror -Wextra -g -O2)

add_executable(fractol
        fractol.h
        main.c keyboard_control.c complex_number.c draw_fractol.c parce.c mandelbrot_julia.c others_fractols.c formula.c)

target_link_libraries(fractol libmlx "-framework OpenGL" "-framework AppKit")
