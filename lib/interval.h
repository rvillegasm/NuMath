#pragma once

namespace numath {

    /** 
     * Representation of an interval. It's Fields are:
     * 
     * first (double): The initial value of the interval.
     * last (double): The final value fo the interval.
     * successful (bool): If an interval (or root) could actually be found.
     * isRoot (bool): If the two values represent a root instead of an interval. 
     */
    struct Interval {
        double first;      /* Starting point of the interval. */
        double last;       /* Final point of the interval. */
        bool wasSuccessful;          
        bool isRoot;       /* Condition that specifies if the interval is actually just a root. */
    };

}