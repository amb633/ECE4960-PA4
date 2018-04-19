//
//  utilityFunctions.hpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#ifndef utilityFunctions_hpp
#define utilityFunctions_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void add_vectors( vector<double>* x,  vector<double>* dx,  vector<double>* sum );

void scaleVector( double scalar, vector<double>* a,  vector<double>* result);

void print_full_vec( vector<double>* VF );

#endif /* utilityFunctions_hpp */