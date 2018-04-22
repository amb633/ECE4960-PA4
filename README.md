# ECE4960-PA4 - Programming Assignment 4 Compact SPICE for ODE Solutions

**Summary**
This program focuses on building ODE solvers for SPICE-like circuit simulation. Three different one-step solvers (Euler, Standard Runge-Kutta, and Adaptive Runge-Kutta) were built and tested. The main program builds all relevant functions in the C++ language. A succint implementation on MATLAB is included to cross-check that the values obtained are accurate.

***************************************************************************
### Part 0 - Utility Functions
***************************************************************************
**Overview:** Common utility functions that will be accessed and used commonly throughout the assignment. All functions have been resused from previous programming assignments.

**Documentation:** 
- `add_vectors( a , b , sum )`: elementwise addition of vectors `a` and `b` with result being stored in `sum`
- `scaleVector( scalar , a , result )`: multiplies vector `a` by a constant `scalar` and stores it in `result`
- `shiftVector( scalar , a , result )`: adds a constant `scalar` to vector `a` and stores it in `result`
- `expVector( result , input )`: takes the elementwise exponential of the elements in `input` and stores it in `result`
- `vectorMultiplication ( a , b , result )`: elementwise multiplication of vectors `a` and `b`
- `vectorProduct( results , A , b )`: matrix product of a matrix `A` and a vector `b`
- `print_full_vec( a )`: prints all elements in vector `a` to screen
- `calculateNorm ( a )`: calculates the norm of vector `a`

***************************************************************************
### Part 1 - Differential Functions
***************************************************************************
**Overview:** Implementation of ODE functions that will be solved using the three methods discussed in Part 2.

**Documentation:**
All functions have to created/ called with the standarad function signature: 
- `phi`: `vector<double>` for storing the slope of the function at the current time step
- `xi`: `vector<double` for sending the values of the function at the current time step
- `time`: `double` value for sending the current time step
- `march`: `double` value for sending the time interval (march) value at each iteration 

**`exponential_function()`**: exponential test function as detailed in the hacker practices
**`simple_RC_circuit()`**: differential equations for simple circuit given in Figure 03 of handout
**`amplifier_circuit()`**: differential equatiosn for common source amplifier given in Figure 5a of handout

Other helper functions:
- `generate_current_input( time )`: returns the current at the given `time`, following the function given in Figure 6
- `calculate_ID( vgs , vds )`: returns the ID,EKF current for the given parameters, as defined in Equation 1 of the handout - reused from Programming Assignment 03

Testing functions:
- `test_current_generator()`: testing function to check that `generate_current_input( time )` returns the correct values
- `test_simple_RC_circuit()`: testing function to check that `simple_RC_circuit()` returns the correct values - values are cross-referenced with the MATLAB implementation
- `test_amplifier_circuit()`: testing function to check that the `amplifier_circuit()` returns the corret values - values are cross-referenced with the MATLAB implementation