#include "phi.hpp"
#include "simpleRC.hpp"
// #include "function_pointer.hpp"

void phi_function( void (*function)(vector<double>* , vector<double>* , double , double) ,
	vector<double>* slope , vector<double>* values , vector<double>* time , vector<double>* march , int method , bool adaptivity ){
	switch( method ){
		case FORWARD_EULER : { 
			cout << " forward euler method chosen " << endl; 
			// call function here
			break; 
		}
		case RK34 :{
			if ( adaptivity ) { 
				cout << " adative RK34 method chosen " << endl; 
				// call function here
				break; }
			else if ( !adaptivity ) { 
				cout << " non-adaptive RK34 method chosen " << endl; 
				// call function here
				break; }
		}
	}
	return;
}

void test_phi_function(){
	void (*simpleCircuit)( vector<double>* , vector<double>* , double , double ) = simple_RC_circuit;
	vector<double> time , march , slope , values;
	phi_function( simpleCircuit , &slope , &values , &time , &march , FORWARD_EULER);
	phi_function( simpleCircuit , &slope , &values , &time , &march , RK34 );
	phi_function( simpleCircuit , &slope , &values , &time , &march , RK34 , true);
	return;
}