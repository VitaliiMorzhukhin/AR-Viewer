cmake_minimum_required(VERSION 3.10)
project(ar_viewer)

add_executable(ar_viewer main.cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp REQUIRED)

# Emscripten options
if(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sUSE_WEBGL2=1 -sUSE_ES6_IMPORT_META=0 -sALLOW_MEMORY_GROWTH=1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sFULL_ES2=1 -sUSE_WEBGL2=1 -sALLOW_MEMORY_GROWTH=1 -sUSE_PTHREADS=0")
endif()

