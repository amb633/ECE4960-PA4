#include "function_pointer.hpp"

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
		slope.erase( slope.begin() , slope.end() );
		values.erase( values.begin() , values.end() );
		forward_euler( exp_fcn , &slope , &values , time , march );
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
