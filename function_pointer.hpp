//
//  function_pointer.hpp
//  PA4
//
//  Created by Ariana Bruno on 4/19/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef function_pointer_hpp
#define function_pointer_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include "utilityFunctions.hpp"

#define FORWARD_EULER 0
#define RK34 1

using namespace std;

void exponential_function( vector<double>* result , vector<double>* input , double time );
void generate_current_input( vector<double>* current_input , double march );
void forward_euler( void (*function)(vector<double>* , vector<double>* , double) , vector<double>* slope , vector<double>* values, double time , double march );
int RUN_function_pointer();

#endif /* function_pointer_hpp */
