
cmake_minimum_required(VERSION 3.9.1)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "ERROR: In-source builds are not allowed!. 
  You should create a separate directory for build files.")
endif()

project(numath VERSION 1.0.0 DESCRIPTION "Numerical Methods in C++")

include(GNUInstallDirs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(SOURCES src/singleVariableEquations/incrementalSearch.cpp
            src/singleVariableEquations/closedMethods/bisection.cpp
            src/singleVariableEquations/closedMethods/falsePosition.cpp
            src/singleVariableEquations/openMethods/fixedPoint.cpp
            src/singleVariableEquations/openMethods/newton.cpp
            src/singleVariableEquations/openMethods/secant.cpp
            src/singleVariableEquations/openMethods/multipleRoots.cpp
            src/systemsOfEquations/gaussianElimination/gaussianElimination.cpp
            src/systemsOfEquations/gaussianElimination/gaussianEliminationPartialPivot.cpp
            src/systemsOfEquations/gaussianElimination/gaussianEliminationTotalPivot.cpp
            src/systemsOfEquations/directFactoring/croutMethod.cpp
            src/systemsOfEquations/directFactoring/choleskyMethod.cpp
            src/systemsOfEquations/directFactoring/doolittleMethod.cpp
            src/systemsOfEquations/iterativeMethods/gaussSeidel.cpp
            src/systemsOfEquations/iterativeMethods/jacobi.cpp
            src/systemsOfEquations/iterativeMethods/solveIterative.cpp
            src/interpolation/newtonInterp.cpp
            src/interpolation/lagrange.cpp
            src/interpolation/linearSpline.cpp
            src/interpolation/quadraticSpline.cpp
            src/differentiation/differentiation.cpp
            src/interpolation/cubicSpline.cpp
            src/integration/trapezium.cpp
            src/integration/simpsonOneThird.cpp
            src/integration/simpsonThreeEighths.cpp
            lib/errorFunctions.cpp
            )

# set(HEADER_FILES )

# add_executable(numath "${SOURCES}")
add_library(numath SHARED ${SOURCES})

set_target_properties(numath PROPERTIES 
                      VERSION ${PROJECT_VERSION}
                      SOVERSION 1 
                      PUBLIC_HEADER "include/numath.h;src/singleVariableEquations/incrementalSearch.h;src/singleVariableEquations/closedMethods/bisection.h;src/singleVariableEquations/closedMethods/falsePosition.h;src/singleVariableEquations/openMethods/fixedPoint.h;src/singleVariableEquations/openMethods/newton.h;src/singleVariableEquations/openMethods/secant.h;src/singleVariableEquations/openMethods/multipleRoots.h;src/systemsOfEquations/gaussianElimination/gaussianElimination.h;src/systemsOfEquations/gaussianElimination/gaussianEliminationPartialPivot.h;src/systemsOfEquations/gaussianElimination/gaussianEliminationTotalPivot.h;src/systemsOfEquations/directFactoring/croutMethod.h;src/systemsOfEquations/directFactoring/choleskyMethod.h;src/systemsOfEquations/directFactoring/doolittleMethod.h;src/systemsOfEquations/iterativeMethods/gaussSeidel.h;src/systemsOfEquations/iterativeMethods/jacobi.h;src/systemsOfEquations/iterativeMethods/solveIterative.h;src/interpolation/newtonInterp.h;src/interpolation/lagrange.h;src/interpolation/linearSpline.h;src/interpolation/quadraticSpline.h;src/differentiation/differentiation.h;src/interpolation/cubicSpline.h;src/integration/trapezium.h;src/integration/simpsonOneThird.h;src/integration/simpsonThreeEighths.h;lib/interval.h;lib/exceptions.h;lib/errorFunctions.h;lib/piecewiseFunction.h;lib/point.h"  )

configure_file(numath.pc.in numath.pc @ONLY)
target_include_directories(numath PRIVATE include)
target_include_directories(numath PRIVATE src)
target_include_directories(numath PRIVATE lib)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    # message("OpenMP Found...")
    target_link_libraries(numath PUBLIC OpenMP::OpenMP_CXX)
else()
    message(FATAL_ERROR "Error: OpenMP not found!. Aborting...")
endif()

install(TARGETS numath
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/numath.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# install(TARGETS numath DESTINATION "/usr/local/lib")
# install(FILES ${HEADERS} DESTINATION "/usr/local/include")

# useful links: 
# https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b
# http://www.thebitbangtheory.com/2011/11/how-to-openmp-cmake/ 
# https://cliutils.gitlab.io/modern-cmake/chapters/packages/OpenMP.html