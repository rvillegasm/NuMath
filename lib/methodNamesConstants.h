#pragma once

/**
 * Enumeration that associates the name of each single variable method to an integer.
 * Possible values are:
 *   BISECTION
 *   FALSE_POSITION
 *   FIXED_POINT
 *   NEWTON
 *   SECANT
 *   MULT_ROOTS
 */
enum methodName {INCR_SEARCH, BISECTION, FALSE_POSITION, FIXED_POINT, NEWTON, SECANT, MULT_ROOTS};