#pragma once
#include "utilityFunctions.hpp"

// utility functions
void simple_RC_circuit( vector<double>* phi , vector<double>* values , vector<double>* time , vector<double>* march );
double generate_current_input( double time );

// test functions
bool test_current_generator();