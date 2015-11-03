cmake_minimum_required(VERSION 2.8)

project(pdi)

find_package(OpenCV REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE lib_sources src/*.cpp)
file(GLOB_RECURSE lib_includes include/*.h)

add_executable(pdi ${lib_sources} ${lib_includes})

target_link_libraries(pdi ${OpenCV_LIBS})

install(TARGETS pdi RUNTIME DESTINATION bin)
