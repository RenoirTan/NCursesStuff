cmake_minimum_required(VERSION 3.0)
project(NCursesStuff VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig)
pkg_check_modules(ncurses REQUIRED ncurses)

set(public_include_dir ${PROJECT_SOURCE_DIR}/include)
set(config_folder ${public_include_dir}/ncurses_stuff)
configure_file(${config_folder}/config.h.in ${config_folder}/config.h)

include_directories(
    ${public_include_dir}
)

add_subdirectory(src)
