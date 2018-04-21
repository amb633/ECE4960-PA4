//
//  main.cpp
//  PA4
//
//  Created by Ariana Bruno on 4/18/18.
//  Copyright © 2018 Ariana Bruno. All rights reserved.
//

#include <iostream>
#include "utilityFunctions.hpp"
#include "test_utilityFunctions.hpp"
#include "function_pointer.hpp"
#include "simpleRC.hpp"
#include "phi.hpp"

int main(int argc, const char * argv[]) {

	//cout << fixed;
    cout << " --------------- Testing Utility Functions --------------- " << endl;
    TEST();
    
    cout << " --------------- Testing Simple Circuit Functions --------------- " << endl;
    if ( test_current_generator() )
    	cout << " current generator is working " << endl << endl;
    else cout << " current generator is not working " << endl << endl;

    if ( test_simple_RC_circuit() )
        cout << " simple RC circuit function is working " << endl << endl;
    else cout << " simple RC circuit function is not working " << endl << endl;

    cout << " --------------- Testing Parent Phi function --------------- " << endl;
    test_phi_function();
    cout << endl << endl;

    //
    // PA 4 Tasks 3
    //
    
    cout << fixed;
    void (*exp_fcn)( vector<double>* , vector<double>* , double , double ) = exponential_function;
    
    vector<double> slope , values;
    
    vector<double> initial;
    initial = {2.0};
    double time = 0.0;
    double march = 1.0;
    double n_steps = 5;
    
    cout << "time:      actual:      RK34       k1          k2          k3          k4:" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    
    for ( int i = 0 ; i < n_steps ; i++ ){
        cout << time << "   ";
        double ground_truth = true_function(time);
        cout << ground_truth << "   ";
        
        vector<double> new_values;
        
        if( i < 1){
            new_values = initial;
        } else {
            
            double time_prev = time - march;
            vector<double> k1, k2, k3, k4, Err;
//            forward_euler( exp_fcn , &slope , &values , time_prev , march );
            RK34_function(exp_fcn, &slope, &values, time_prev, march, &k1, &k2, &k3, &k4);
            E_RK34_function(&Err, march, &k1, &k2, &k3, &k4 );
            vector<double> slope_h;
            scaleVector(march, &slope, &slope_h);
            add_vectors(&values, &slope_h, &new_values);
            print_full_vec(&new_values);
            print_full_vec(&k1);
            print_full_vec(&k2);
            print_full_vec(&k3);
            print_full_vec(&k4);
        }
        
        values = new_values;
        slope.erase(slope.begin(), slope.end());
        double new_time = time + march;
        time = new_time;
        cout << endl;
    }
    
    //
    // PA 4 Task 4
    //
    
    cout << endl;

    cout << fixed;
    cout.precision(10);
    void (*simpleCircuit)( vector<double>* , vector<double>* , double , double) = simple_RC_circuit;

    //reset vectors for next task
    values.erase(values.begin());
    initial.erase(initial.begin());
    
    //re-intializing values for this task
    time = 0.0;
    march = 1e-9;
    //    initial = {2.0};
    initial = {0.0 , 0.0};
    n_steps = 5;

    cout << "time1:     RK34 Method->    V1:        V2:     " << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for ( int i = 0 ; i < n_steps ; i++ ){
        cout << time << "   ";
//        vector<double> ground_truth;
//        true_function(&ground_truth, &time);
//        print_full_vec(&ground_truth);

        vector<double> new_values;

        if( i < 1){
            new_values = initial;
        } else {
            double time_prev = time - march;
            vector<double> k1, k2, k3, k4;
//            forward_euler( simpleCircuit , &slope , &values , time_prev , march );
            
            RK34_function(simpleCircuit, &slope, &values, time_prev, march, &k1, &k2, &k3, &k4);
            vector<double> slope_h;
            scaleVector(march, &slope, &slope_h);
            add_vectors(&values, &slope_h, &new_values);
//            print_full_vec(&slope);
            cout << "                   ";
            print_full_vec(&new_values);
//            print_full_vec(&k1);
//            print_full_vec(&k2);
//            print_full_vec(&k3);
//            print_full_vec(&k4);
        }

        values = new_values;
        slope.erase(slope.begin(), slope.end());
        double new_time = time + march;
        time = new_time;
        cout << endl;
    }


    cout << endl;

}
