cmake_minimum_required(VERSION 3.9.1)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "ERROR: In-source builds are not allowed!. 
  You should create a separate directory for build files.")
endif()

project(NuMath C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(SOURCES src/main_test.c
            src/singleVariableEquations/incrementalSearch.c
            src/singleVariableEquations/incrementalSearch.h
            lib/interval.h)

add_executable(NuMath ${SOURCES})

# Link to math library on linux
target_link_libraries(NuMath m)

# useful links: 
# https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b
# http://www.thebitbangtheory.com/2011/11/how-to-openmp-cmake/ 
# https://cliutils.gitlab.io/modern-cmake/chapters/packages/OpenMP.html