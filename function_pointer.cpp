#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

#define BACKWARD_EULER 0;
#define FORWARD_EULER 1;
#define TRAPEZOIDAL_EULER 2;
#define HEUN_ONE_STEP 2;
#define HEUN_ITR 3;
#define RK34 4;
#define ADAPTIVE_RK34 5;

using namespace std;

void exponential_function( vector<double>* result , vector<double>* input , double time ){
	(*result).push_back ( 4.0*exp( 0.8* time ) - 0.5*(*input).back() );
	return;
}

void forward_euler( void (*function)(vector<double>* , vector<double>* , double) , vector<double>* slope , vector<double>* values, double time , double march ){
	function( slope , values , time );
	return;
}

int main(int argc, char const *argv[])
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
		forward_euler( exp_fcn , &slope , &values , time , march );
		values.push_back( (slope.back() * march) + values.back() );
		time += march;
	}
	

	return 0;
}