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
#include "amplifierRC.hpp"
#include "phi.hpp"

int main(int argc, const char * argv[]) {
//    for( int i = 0; i<=argc; i++){
//        cout << argv[i] << endl;
//    }
    string first_arg = argv[1];
    string second_arg = argv[3];
    string test_arg = "TEST";
    string task3_arg = "TASK3";
    string task4_arg = "TASK4";
    
    void (*exp_fcn)( vector<double>* , vector<double>* , double , double ) = exponential_function;
    void (*simpleCircuit)( vector<double>* , vector<double>* , double , double) = simple_RC_circuit;
    void (*amplifierCircuit)( vector<double>* , vector<double>* , double , double ) = amplifier_circuit;
    
    if(first_arg == test_arg){
        //cout << fixed;
        cout << " --------------- Testing Utility Functions --------------- " << endl;
        TEST();
        
        cout << " --------------- Testing Circuit Functions --------------- " << endl;
        if ( test_current_generator() )
            cout << " current generator is working " << endl << endl;
        else cout << " current generator is not working " << endl << endl;

        if ( test_simple_RC_circuit() )
            cout << " simple RC circuit function is working " << endl << endl;
        else cout << " simple RC circuit function is not working " << endl << endl;

        if ( test_amplifier_circuit() )
            cout << " amplifier circuit function is working " << endl << endl;
        else cout << " amplifier circuit function is not working " << endl << endl;

        cout << endl << endl;
        
    } else if( first_arg == task3_arg){

    //
    // PA 4 Tasks 3
    //
    
        cout << fixed;
        
        vector<double> slope , values;
        
        vector<double> initial;
        initial = {2.0};
        double time = 0.0;
        double march = 1.0;
        double end_time = 4;
        values = initial;
        
        if( second_arg == "RK34" ){ cout << "time:      actual:      RK34:  " << endl; };
        if( second_arg == "Forward" ){ cout << "time:      actual:      Forward:  " << endl; };
        cout << "---------------------------------------------------------------------------" << endl;
        
        while(time <= end_time){
            cout << time << "   ";
            double ground_truth = true_function(time);
            cout << ground_truth << "   ";
            if( second_arg == "RK34" ){
                if( (string)argv[4] == "Adaptation" ){
                    ODE_Solver( exp_fcn , &slope , &values , time , march , RK34, true);
                } else {
                    ODE_Solver( exp_fcn , &slope , &values , time , march , RK34);
                }
            } else {
                //Forward Euler is default
                ODE_Solver( exp_fcn , &slope , &values , time , march , FORWARD_EULER);
            }
        }
        cout << endl;
    } else if( first_arg == task4_arg ){
    
        //
        // PA 4 Task 4
        //
        
        cout << endl;

        cout << fixed;
        cout.precision(10);
        
        //reset vectors for next task
        vector<double> slope, values, initial;
        
        //re-intializing values for this task
        double time = 0.0;
        double march = 1e-9;
        //    initial = {2.0};
        initial = {0.0 , 0.0};
        values = initial;
        double end_time = 100e-9;

        if( second_arg == "RK34" ){
            if((string)argv[4] == "Adaptation"){
                cout << "RK34 Adaptation Method: " << endl;
                
            } else{
                cout << "RK34 Method: " << endl;
            }
        };
        if( second_arg == "Forward" ){ cout << "Forward Euler Method: " << endl; };
        cout << "time:     V1:        V2:     " << endl;
        cout << "--------------------------------------" << endl;

        while(time <= end_time){
            cout << time << "   ";
            
            if( second_arg == "RK34" ){
                if( (string)argv[4] == "Adaptation"){
                    if( (string)argv[6] == "Amplifier"){
                        ODE_Solver( amplifierCircuit , &slope , &values , time , march , RK34, true);
                    } else {
                        // Simple Circuit is default for RK34 with adaption
                        ODE_Solver( simpleCircuit , &slope , &values , time , march , RK34, true);
                    }
                } else {
                    //RK34 without adaption is the default
                    if( (string)argv[5] == "Amplifier"){
                        ODE_Solver( amplifierCircuit , &slope , &values , time , march , RK34);
                    } else {
                        //Simple Circuit is default fr RK34 without adaption
                        ODE_Solver( simpleCircuit , &slope , &values , time , march , RK34);
                    }
                }
            } else {
                if( (string)argv[6] == "Amplifier"){
                    ODE_Solver( amplifierCircuit , &slope , &values , time , march , FORWARD_EULER);
                } else {
                    // Simple Circuit is default for Forward Euler
                    ODE_Solver( simpleCircuit , &slope , &values , time , march , FORWARD_EULER);
                }
                
            }
            
        }


        cout << endl;
        cout << argc << endl;
    }

}
