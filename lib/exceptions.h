#include <exception>

/**
 * Exception for when the number of iterations runs out.
 */
struct IterException : public std::exception {

    const char* what() const noexcept {
        return "Could not find anything with the specified number of iterations";
    }

};

/**
 * Exception for when the interval isn't valid.
 */
struct IntervalException : public std::exception {

    const char* what() const noexcept {
        return "Invalid interval entered";
    }

};