#include "function_pointer.hpp"
#include "utilityFunctions.hpp"

void exponential_function( vector<double>* result , vector<double>* input , double time ){
	(*result).push_back ( 4.0*exp( 0.8* time ) - 0.5*(*input).back() );
	return;
}

void generate_current_input( vector<double>* current_input , double march ){
	
	double gradient = 0.1e-3/1.0e-9;
	for ( int i = 0 ; i < 100/20 ; i++ ){
		for ( double time = 0.0 ; time < 1e-9 ; time += march ){
			(*current_input).push_back( gradient*time );
		}
		for ( double time = 1e-9 ; time < 10e-9 ; time += march ){
			(*current_input).push_back( 0.1e-3 );
		}
		for ( double time = 0.0 ; time < 1e-9 ; time += march ){
			(*current_input).push_back( -gradient*time );
		}
		for ( double time = 1e-9 ; time < 10e-9 ; time += march ){
			(*current_input).push_back( 0.0 );
		}
	}
}

void forward_euler( void (*function)(vector<double>* , vector<double>* , double) , vector<double>* slope , vector<double>* values, double time , double march ){
	function( slope , values , time );
	return;
}

//void RK34_k1( void (*function)(vector<double>* , vector<double>* , double), vector<double>* k1, vector<double>* x_prev, double t, vector<double>* h){
//    function( k1, x_prev , t );
//}
//
//double RK34_k2( void (*function)(vector<double>* , vector<double>* , double), vector<double>* k2, vector<double>* x_prev, double t, vector<double>* h, vector<double>* k1){
//    vector<double> k1_h, k1_h_2, h_2, x_prev_k2, t_k2;
//    add_vectors(k1, h, &k1_h);
//    scaleVector(0.5, &k1_h, &k1_h_2);
//    scaleVector(0.5, h, &h_2);
//    shiftVector(t, &h_2, &t_k2);
//    add_vectors(x_prev, &k1_h_2, &x_prev_k2);
//    function(k2, &x_prev_k2, &t_k2);
//    return h62_dx_dt(x_prev + (k1*h/2.0), t + (h/2.0));
//}
//
//double RK34_k3(double x_prev, double t, double h, double k2){
//    return h62_dx_dt(x_prev + (3.0*k2*h/4.0), t + (3.0*h/4.0));
//}
//
//double RK34_k4(double x_prev, double t, double h, double k3){
//    return h62_dx_dt(x_prev + k3*h, t + h);
//}
//
//double RK34(double x_prev, double k1, double k2, double k3, double k4, double h){
//    return x_prev + ((1.0/24.0)*((7.0*k1) + (6.0*k2) + (8.0*k3) + (3.0*k4))*h);
//}
//
//double RK34_error(double k1, double k2, double k3, double k4, double h){
//    return ((1/72.0)*(-5.0*k1 + 6.0*k2 + 8.0*k3 -9*k4)*h);
//}

int RUN_function_pointer()
{
	cout << fixed;

	void (*exp_fcn)(vector<double>* , vector<double>* , double ) = exponential_function;
	double trueValues[] = {2.0 , 6.1946 , 14.843 , 33.677 , 75.339 };

	vector<double> slope , values;
	double time , march;
	int n_steps , counter;

	time = 0.0;
	march = 1.0;
	values.push_back(2.0);
	n_steps = 5;

	cout << "time:		actual:		forward_euler:" << endl;
	cout << "--------	--------	--------------" << endl;

	for ( int i = 0 ; i < n_steps ; i++ ){
		cout << time << "	";
		cout << trueValues[i] << "	";
		cout << values.back();
		cout << endl;
		//slope.erase( slope.begin() , slope.end() );
		//values.erase( values.begin() , values.end() );
		forward_euler( exp_fcn , &slope , &values , time , march );
		values.push_back( slope.back() * march  + values.back() );
		time += march;
	}


	cout << endl;
	vector<double> current_input;
	generate_current_input( &current_input , 0.2e-9 );
	// for ( int i = 0 ; i < current_input.size() ; i ++ ){
	// 	cout << current_input[i] << endl;
	// }
	// cout << current_input.size() << endl;
	return 0;
}
