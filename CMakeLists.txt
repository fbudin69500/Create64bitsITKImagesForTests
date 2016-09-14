cmake_minimum_required(VERSION 3.5)
project(CreateITKImagesForTests)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(CreateITKImagesForTests CreateITKImagesForTests.cxx)
target_link_libraries(CreateITKImagesForTests ${ITK_LIBRARIES})
