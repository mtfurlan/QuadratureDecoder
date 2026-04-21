cmake_minimum_required(VERSION 3.12)

set(PROJECT QuadratureDecoder)
project(${PROJECT} C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (NOT DEFINED PICO_SDK_PATH)
    message( FATAL_ERROR "PICO_SDK_PATH not set, that is required")
endif()

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()



add_library(${PROJECT} STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/QuadratureDecoder.cpp
)

# this needs full path
pico_generate_pio_header(${PROJECT} ${CMAKE_CURRENT_LIST_DIR}/src/QuadratureDecoder.pio)

target_include_directories(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT} PUBLIC
    pico_stdlib
    hardware_pio hardware_dma
)
