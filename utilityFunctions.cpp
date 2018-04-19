//
//  utilityFunctions.cpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include "utilityFunctions.hpp"

/* adds to vectors provided by pointers and returns sum by using a pointer */
void add_vectors( vector<double>* x,  vector<double>* dx,  vector<double>* sum ){
    if((*x).size() != (*dx).size()){
        cout << "vectors have different dimensions... cannot add them togther! " << endl;
    }else{
        for( int i = 0; i < (*x).size(); i++){
            (*sum).push_back((*x)[i] + (*dx)[i]);
        }
    }
}

/* scales the vector provided by a pointer by a scalar which is also provided by a pointer */
void scaleVector( double scalar, vector<double>* a,  vector<double>* result){
    for( int i = 0; i<(*a).size(); i++){
        (*result).push_back((*a)[i]*scalar);
    }
}

void shiftVector( double scalar, vector<double>* a,  vector<double>* result){
    for( int i = 0; i<(*a).size(); i++){
        (*result).push_back((*a)[i] + scalar);
    }
}

/* print the full vector VF given by a pointer */
void print_full_vec( vector<double>* VF ){
    for ( int i = 0 ; i < (*VF).size() ; i++ ){
        cout << (*VF)[i] << "   ";
    }
    cout << endl;
}
