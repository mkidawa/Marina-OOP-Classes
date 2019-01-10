cmake_minimum_required(VERSION 3.4)

project(Program)

set(BOOST_ROOT "/usr/lib64")

set(SOURCE_FILES
        src/main.cpp
        )

find_package(Boost 1.60 REQUIRED)

add_executable(Program ${SOURCE_FILES})

target_link_libraries(Program
    port
    boost_date_time)

target_include_directories(Program PUBLIC include)

enable_testing()
