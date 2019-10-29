
cmake_minimum_required(VERSION 3.9.1)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "ERROR: In-source builds are not allowed!. 
  You should create a separate directory for build files.")
endif()

project(NuMath)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(SOURCES src/main_test.cpp
            src/singleVariableEquations/printTable.cpp
            src/singleVariableEquations/printTable.h
            src/singleVariableEquations/incrementalSearch.cpp
            src/singleVariableEquations/incrementalSearch.h
            src/singleVariableEquations/closedMethods/bisection.cpp
            src/singleVariableEquations/closedMethods/bisection.h
            src/singleVariableEquations/closedMethods/falsePosition.cpp
            src/singleVariableEquations/closedMethods/falsePosition.h
            src/singleVariableEquations/openMethods/fixedPoint.cpp
            src/singleVariableEquations/openMethods/fixedPoint.h
            src/singleVariableEquations/openMethods/newton.cpp
            src/singleVariableEquations/openMethods/newton.h
            src/singleVariableEquations/openMethods/secant.cpp
            src/singleVariableEquations/openMethods/secant.h
            src/singleVariableEquations/openMethods/multipleRoots.cpp
            src/singleVariableEquations/openMethods/multipleRoots.h
            src/systemsOfEquations/gaussianElimination/gaussianElimination.cpp
            src/systemsOfEquations/gaussianElimination/gaussianElimination.h
            src/systemsOfEquations/gaussianElimination/gaussianEliminationPartialPivot.cpp
            src/systemsOfEquations/gaussianElimination/gaussianEliminationPartialPivot.h
            src/systemsOfEquations/gaussianElimination/gaussianEliminationTotalPivot.cpp
            src/systemsOfEquations/gaussianElimination/gaussianEliminationTotalPivot.h
            src/systemsOfEquations/directFactoring/croutMethod.cpp
            src/systemsOfEquations/directFactoring/croutMethod.h
            src/systemsOfEquations/directFactoring/choleskyMethod.cpp
            src/systemsOfEquations/directFactoring/choleskyMethod.h
            src/systemsOfEquations/directFactoring/doolittleMethod.cpp
            src/systemsOfEquations/directFactoring/doolittleMethod.h
            src/systemsOfEquations/iterativeMethods/gaussSeidel.cpp
            src/systemsOfEquations/iterativeMethods/gaussSeidel.h
            src/systemsOfEquations/iterativeMethods/jacobi.cpp
            src/systemsOfEquations/iterativeMethods/jacobi.h
            src/systemsOfEquations/iterativeMethods/solveIterative.cpp
            src/systemsOfEquations/iterativeMethods/solveIterative.h
            src/interpolation/newton.cpp
            src/interpolation/newton.h
            src/interpolation/lagrange.cpp
            src/interpolation/lagrange.h
            lib/interval.h
            lib/statusConstants.h
            lib/exceptions.h
            lib/methodNamesConstants.h
            lib/errorFunctions.h
            external/tinyExpression/tinyexpr.c
            external/tinyExpression/tinyexpr.h)

add_executable(NuMath ${SOURCES})

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    # message("OpenMP Found...")
    target_link_libraries(NuMath PUBLIC OpenMP::OpenMP_CXX)
else()
    message(FATAL_ERROR "Error: OpenMP not found!. Aborting...")
endif()

# useful links: 
# https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b
# http://www.thebitbangtheory.com/2011/11/how-to-openmp-cmake/ 
# https://cliutils.gitlab.io/modern-cmake/chapters/packages/OpenMP.html