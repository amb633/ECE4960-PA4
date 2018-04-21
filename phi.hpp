#pragma once
#include "utilityFunctions.hpp"

#define FORWARD_EULER 0
#define RK34 1

void phi_function( void (*function)(vector<double>* , vector<double>* , double , double) ,
	vector<double>* slope , vector<double>* values , vector<double>* time , vector<double>* march , int method , bool adaptivity = false );
void test_phi_function();