# NuMath

NuMath is a C++ shared library that implements several numerical methods.

Right now it implements the following methods:
- Single variable equations
  - Incremental search
  - Bisection
  - Flase position
  - Fixed point
  - Newton
  - Secant
  - Multiple roots
  
- Systems of equations
  - Simple gaussian elimination
  - Gaussian elimination with partial pivoting
  - Gaussian elimination with total pivoting
  - Doolittle Factorization
  - Crout Factorization
  - Cholesky Factorization
  - Gauss-Seidel
  - Jacobi
  
- Interpolation
    - Newton
    - Lagrage
    - Linear splines
    - Quadratic splines
    - Cubic splines

- Numerical Diferentiation
    - With 2 points
    - With 3 points
    - With 5 points

- Numerical Integration
    - General Trapezium
    - General Simpson 1/3
    - General Simpson 3/8

## Getting started

First, clone the repository using: 
```bash
git clone https://github.com/rvillegasm/NuMath.git
```

### Prerequisits

Make sure that you have the following dependencies installed in your system:

- A C++ compiler that supports OpenMP and C++11 standards (like [gcc](https://gcc.gnu.org/)).
- The GNU [make](https://www.gnu.org/software/make/) tool.
- The [CMake](https://cmake.org/) tool.

### Installation

In the NuMath root directory, create a build directory:
```bash
mkdir build
cd build
```
Then run CMake and compile using Make:
```bash
cmake ..
make
```
That will compile the library and create a shared object in the ```build/lib``` directory.

After that, install it in your system with:
```bash
sudo make install
sudo ldconfig
```

By doing this you will have NuMath available in your system as **libnumath**.

## Usage

To use NuMath simply include the header file in your C++ file:

```c++
#include "numath.h"

int main() {
    // ... your code goes here
}
```

### Proyect structure

Every numerical method is located inside the ```numath::<method_category>``` namespace, so in order to use the lagrange interpolation method, you would have to call:
```c++
numath::interpolation::lagrange(/*Arguments*/);
```

Check out the documentation of every method to know theirs parameters, as well as what they return.
