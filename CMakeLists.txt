cmake_minimum_required(VERSION 3.8)
project(Fillit)

set(CMAKE_C_STANDARD 99)

# You need to download and compile the Libft specificly for you machine
# put header file and .a file in "Libft" folder in your project
link_directories(${PROJECT_SOURCE_DIR}/Libft)
include_directories(${PROJECT_SOURCE_DIR}/Libft)

set(SOURCE_FILES
        src/main.c
        src/file_checker.c
        src/processfile.c
        src/field.c
        src/header.h
        src/check_figure.c src/figures_top_left.c src/map.c src/solver.c src/width_height.c src/help.c)

add_executable(Fillit ${SOURCE_FILES})
target_link_libraries(Fillit -lft)
