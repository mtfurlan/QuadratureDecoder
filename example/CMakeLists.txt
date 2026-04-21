cmake_minimum_required(VERSION 3.14)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)


set(PROJECT quadrature_example)
project(${PROJECT} C CXX)

pico_sdk_init()

add_executable(${PROJECT})

target_sources(${PROJECT} PUBLIC
    main.cpp
)

pico_enable_stdio_usb(${PROJECT} 1)
pico_enable_stdio_uart(${PROJECT} 1)

pico_add_extra_outputs(${PROJECT})

target_link_libraries(${PROJECT} PUBLIC pico_stdlib)



add_subdirectory(../ libasdf)
target_link_libraries(${PROJECT} PRIVATE QuadratureDecoder)
