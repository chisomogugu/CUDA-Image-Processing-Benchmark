cmake_minimum_required(VERSION 3.18)
project(CUDAImageBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} src)

add_executable(cuda_image_benchmark
    src/main.cpp
    src/cpu_ops.cpp
)

target_link_libraries(cuda_image_benchmark ${OpenCV_LIBS})