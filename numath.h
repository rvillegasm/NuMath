#pragma once

#include "src/singleVariableEquations/incrementalSearch.h"
#include "src/singleVariableEquations/closedMethods/bisection.h"
#include "src/singleVariableEquations/closedMethods/falsePosition.h"
#include "src/singleVariableEquations/openMethods/fixedPoint.h"
#include "src/singleVariableEquations/openMethods/multipleRoots.h"
#include "src/singleVariableEquations/openMethods/newton.h"
#include "src/singleVariableEquations/openMethods/secant.h"

#include "src/systemsOfEquations/gaussianElimination/gaussianElimination.h"
#include "src/systemsOfEquations/gaussianElimination/gaussianEliminationPartialPivot.h"
#include "src/systemsOfEquations/gaussianElimination/gaussianEliminationTotalPivot.h"
#include "src/systemsOfEquations/directFactoring/choleskyMethod.h"
#include "src/systemsOfEquations/directFactoring/croutMethod.h"
#include "src/systemsOfEquations/directFactoring/doolittleMethod.h"
#include "src/systemsOfEquations/iterativeMethods/solveIterative.h"
#include "src/systemsOfEquations/iterativeMethods/jacobi.h"
#include "src/systemsOfEquations/iterativeMethods/gaussSeidel.h"

#include "src/interpolation/newton.h"
#include "src/interpolation/lagrange.h"
#include "src/interpolation/linearSpline.h"
#include "src/interpolation/quadraticSpline.h"
#include "src/interpolation/cubicSpline.h"

#include "src/differentiation/differentiation.h"

#include "lib/errorFunctions.h"
#include "lib/interval.h"
#include "lib/piecewiseFunction.h"
#include "lib/point.h"
#include "lib/exceptions.h"
