#include "amplifierRC.hpp"

void amplifier_circuit( vector<double>* phi , vector<double>* values , double time , double march ){
	// function to generate the instantaneous slope at the given time interval
	// based on figure 5a in the handout

	// declare given parameters of the circuit
	double Is , kappa , Vth , Vdd , R , C;
	Vdd = 5.0;
	R = 10.0e3;
	C = 1.0e-12;

	// obtain the current input at the present time
	double current_term = ( generate_current_input( time )) / C;
	// calculate the slope of V1
	double phi_1 = ( (-(*values)[0])/(R*C) ) + current_term;
	// calculate the slope of V2
	double ID = calculate_ID( (*values)[0] , (*values)[1] );
	double phi_2 = (-ID / C ) - (((*values)[1])/(R*C)) + (Vdd/(R*C));

	// push values into the return vector
	(*phi).push_back(phi_1);
	(*phi).push_back(phi_2);
}

double calculate_ID( double vgs , double vds ){
    // function to calculate the ID,EKF current values
    // based on equation 01 in the handout
    // code reused from programmin assignment 3
    double kappa = 0.7;
    double vth = 1.0;
    double is = 5.0e-6;
    double vt = 26.0e-3;
    double term_1 = log(1.0 + exp( ( kappa*( vgs -  vth ) ) / ( 2*vt ) ));
    term_1 = term_1*term_1;
    double term_2 = log(1.0 + exp( ( kappa*(vgs-vth)-vds ) / (2*vt) ));
    term_2 = term_2*term_2;
    return is*(term_1 - term_2);
}

bool test_amplifier_circuit(){
	// function to test if the amplifier function returns the correct values withing a tolerance
	// "true" values are obtained from the matlab implementation
	// returns true is all the values are correct
	// returns false if there are any incorrect values

	bool flag = true;
	double march = 1e-9;
	double tolerance = 1.0;
	
	// test 1
    vector<double> test_1 , values_1 ;
	double time_1 = 20.5e-9 ;
	values_1 = { 1.0 , 1.0 };
	amplifier_circuit( &test_1 , &values_1 , time_1 , march );
	if ( abs( test_1[0] - ( -0.499999999999999e8 ) ) > tolerance
		|| abs( test_1[1] - ( 3.975977349304090e8 ) ) > tolerance ){
		flag = false;
		print_full_vec( &test_1 );
		cout << endl;
	}


	// test 2
	vector<double> test_2 , values_2 ; 
	double time_2 = 64.5e-9 ;
	values_2 = { 2.0 , 4.0 };
	amplifier_circuit( &test_2 , &values_2 , time_2 , march );
	if ( abs( test_2[0] - ( -1.0000e8 ) ) > tolerance
		|| abs( test_2[1] - ( -8.060652805458858e8 ) ) > tolerance ){
		flag = false;
		print_full_vec( &test_2 );
		cout << endl;
	}

	// test 3
	vector<double> test_3 , values_3 ;
	double time_3 = 76.3e-9;
	values_3 = { 3.0 , 5.0 };
	amplifier_circuit( &test_3 , &values_3 , time_3 , march );
	if ( abs( test_3[0] - ( -0.3000e9 ) ) > tolerance
		|| abs( test_3[1] - ( -3.6242603550301333e9 ) ) > tolerance ){
		flag = false;
		print_full_vec( &test_3 );
		cout << endl;
	}

	// return error flag
	return flag;

}