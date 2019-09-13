#pragma once

/** 
 * Representation of an interval. It's Fields are:
 * first (double): The initial value of the interval.
 * last (double): The final value fo the interval.
 * successful (bool): If an interval (or root) could actually be found.
 * isRoot (bool): If the two values represent a root instead of an interval. 
 */
typedef struct Interval {
    double first;
    double last;
    bool wasSuccessful;
    bool isRoot;
} Interval;