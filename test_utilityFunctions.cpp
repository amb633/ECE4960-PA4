//
//  test_utilityFunctions.cpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "test_utilityFunctions.hpp"
#include "utilityFunctions.hpp"

bool TEST_add_vectors( vector<double>* x,  vector<double>* y,  vector<double>* sum, vector<double>* expected_result ){
    add_vectors(x, y, sum);
    if( *sum == *expected_result){
        return true;
    } else{
        return false;
    }
    
}
bool TEST_scaleVector( double scalar, vector<double>* a,  vector<double>* result, vector<double>* expected_result){
    scaleVector(scalar, a, result);
    if( *result == *expected_result ){
        return true;
    } else {
        return false;
    }
    
}

void TEST(){
    cout << "Testing the vector add function: " << endl << endl;
    vector<double> a = {1, 1, 1, 1};
    vector<double> b = {2, 2, 2, 2};
    vector<double> c;
    vector<double> expected_c = {3,3,3,3};
    add_vectors(&a, &b, &c);
    cout << "{1, 1, 1, 1} + {2, 2, 2, 2} = ";
    print_full_vec(&c);
    bool test_add1 = TEST_add_vectors(&a, &b, &c, &expected_c);
    cout << "vector of 1s plus a vector of 2s is eqaul to vector of 3s: " << test_add1 << endl << endl;
    
    cout << "Testing the vector scale function: " << endl << endl;
    vector<double> d;
    scaleVector(5, &c, &d);
    cout << "{3, 3, 3, 3} * 5 = ";
    print_full_vec(&d);
    bool test_scale1 = TEST_add_vectors(&a, &b, &c, &expected_c);
    cout << "vector of 3s scaled by 5 is eqaul to vector of 15s: " << test_scale1 << endl << endl;
}
