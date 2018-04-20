#include "simpleRC.hpp"

void simple_RC_circuit( vector<double>* phi , vector<double>* values , vector<double>* time , vector<double>* march ){
	double R1 , R2 , R3 , C1 , C2 , cp11 , cp12 , cp21 , cp22 ;
	R1 = 10.0e3;
	R2 = 10.0e3;
	R3 = 10.0e3;

	C1 = 1.0e-12;
	C2 = 1.0e-12;

	cp11 = -( (1.0/(C1*R1)) + (1.0/(C1*R2)) );
	cp12 = 1.0/(C1*R2);
	cp21 = 1.0/(C2*R2);
	cp22 = -( (1.0/(C2*R2)) + (1.0/(C2*R3)) );

	vector<vector<double>> circuit_param = { {cp11 , cp12 } , {cp21 , cp22} };

	vector<double> temp;
	vectorProduct( &temp , &circuit_param , values );

	double current_term = ( generate_current_input( (*time).back() )) / C1;
	// double current_term = ( generate_current_input ( (*time).back() + (*march).back() )) / C1;
	(*phi).push_back( temp[0] + current_term );
	(*phi).push_back( temp[1] + 0.0 );

}

double generate_current_input( double time ){
	
	double gradient = (0.1e-3)/(1.0e-9);
	//cout << gradient << endl;

	if ( time >= 1.0e-9 && time <= 10e-9 ||
		time >= 21e-9 && time <= 30e-9 ||
		time >= 41e-9 && time <= 50e-9 ||
		time >= 61e-9 && time <= 70e-9 ||
		time >= 81e-9 && time <= 90e-9 )
		return( 0.1e-3 );

	else if ( time >= 11e-9 && time <= 20e-9 ||
		time >= 31e-9 && time <= 40e-9 ||
		time >= 51e-9 && time <= 60e-9 ||
		time >= 71e-9 && time <= 80e-9 ||
		time >= 91e-9 && time <= 100e-9)
		return ( 0.0 );

	// period one
	else if ( time >= 0.0 && time < 1.0e-9 )
		return ( gradient * time );

	else if ( time > 10e-9 && time < 11e-9 )
		return(  0.1e-3 - (gradient * (time - 10e-9)));

	// period two
	else if ( time > 20e-9 && time < 21e-9 )
		return ( gradient * (time - 20e-9) );

	else if ( time > 30e-9 && time < 31e-9 )
		return(  0.1e-3 - (gradient * (time - 30e-9)));

	// period three
	else if ( time > 40e-9 && time < 41e-9 )
		return ( gradient * (time - 40e-9) );

	else if ( time > 50e-9 && time < 51e-9 )
		return(  0.1e-3 - (gradient * (time - 50e-9)));

	// period four
	else if ( time > 60e-9 && time < 61e-9 )
		return ( gradient * (time - 60e-9) );

	else if ( time > 70e-9 && time < 71e-9 )
		return(  0.1e-3 - (gradient * (time - 70e-9)));

	// period five
	else if ( time > 80e-9 && time < 81e-9 )
		return ( gradient * (time - 80e-9) );

	else if ( time > 90e-9 && time < 91e-9 )
		return(  0.1e-3 - (gradient * (time - 90e-9)));

	// error return
	else return ( -1.0 );

}

bool test_current_generator( ){
	
	bool flag = true;

	if ( generate_current_input( 7.5e-9 ) != 0.1e-3 
		|| generate_current_input( 26.2e-9 ) != 0.1e-3 
		|| generate_current_input( 43.6e-9 ) != 0.1e-3
		|| generate_current_input( 67.3e-9 ) != 0.1e-3
		|| generate_current_input( 84.6e-9 ) != 0.1e-3)
		flag = false;

	if ( generate_current_input( 17.5e-9 ) != 0.0e-3 
		|| generate_current_input( 36.2e-9 ) != 0.0e-3 
		|| generate_current_input( 53.6e-9 ) != 0.0e-3
		|| generate_current_input( 77.3e-9 ) != 0.0e-3
		|| generate_current_input( 94.6e-9 ) != 0.0e-3)
		flag = false;

	if ( abs( generate_current_input( 0.5e-9 ) - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 20.5e-9 )  - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 40.5e-9 ) - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 60.5e-9 ) - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 80.5e-9 ) - 0.05e-3 ) > 1e-12 )
		flag = false;

	if ( abs( generate_current_input( 10.5e-9 )  - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 30.5e-9 ) - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 50.5e-9 ) - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 70.5e-9 ) - 0.05e-3 ) > 1e-12 
		|| abs( generate_current_input( 90.5e-9 ) - 0.05e-3 ) > 1e-12 )
		flag = false;	

	return flag;
}