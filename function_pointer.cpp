#include "function_pointer.hpp"

void true_function( vector<double>* result, vector<double>* time ){
    
    result->erase(result->begin(), result->end());
    for ( int i = 0; i < time->size(); i++ ){
        double t = (*time)[i];
        result->push_back((((4/1.3)*(exp(0.8*t) - exp(-0.5*t))) + 2*exp(-0.5*t)));
    }
}

void exponential_function( vector<double>* phi , vector<double>* x_i0, vector<double>* time,  vector<double>* h){
    if( x_i0->size() != time->size() || x_i0->size() != h->size() || time->size() != h->size()){
        cout << "ERROR: vectors are not the same dimension to calculate task 3 " << endl;
    } else {
        for( int i = 0; i < x_i0->size(); i ++){
            double t = (*time)[i];
            double x_prev = (*x_i0)[i];
            (*phi).push_back ( 4.0*exp( 0.8* t ) - 0.5*x_prev);
            //    vector<double> time08, exptime08, exptime08_scale4, x_i0_scale05;
            //    scaleVector(0.8, time, &time08);
            //    expVector(&exptime08, &time08);
            //    scaleVector(4.0, &exptime08, &exptime08_scale4);
            //    scaleVector(-0.5, x_i0, &x_i0_scale05);
            //    add_vectors(&exptime08_scale4, &x_i0_scale05, phi);
        }
    }
    return;
}

void forward_euler( void (*function)(vector<double>* , vector<double>* , vector<double>*, vector<double>*) , vector<double>* slope , vector<double>* values, vector<double>* time , vector<double>* march ){
	function( slope, values, time, march );
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

	void (*exp_fcn)(vector<double>* , vector<double>* , vector<double>*, vector<double>* ) = exponential_function;
    vector<double> trueValues;

	vector<double> slope , values;
//    double time , march;
	int n_steps , counter;

    vector<double> time, march, initial;
    double rank = 1;
    time = {0};
    march = {1};
    initial = {2.0};
	n_steps = 5;

	cout << "time:		actual:		forward_euler:" << endl;
	cout << "--------	--------	--------------" << endl;

	for ( int i = 0 ; i < n_steps ; i++ ){
        print_full_vec(&time);
        vector<double> ground_truth;
        true_function(&ground_truth, &time);
        print_full_vec(&ground_truth);
        
        vector<double> new_values;
        
        if( i < 1){
            new_values = initial;
        } else {
            vector<double> march_neg;
            scaleVector(-1.0, &march, &march_neg);
            vector<double> time_prev;
            add_vectors(&time, &march_neg, &time_prev);
            forward_euler( exp_fcn , &slope , &values , &time_prev , &march );
            add_vectors(&values, &slope, &new_values);
        }
        print_full_vec(&new_values);
        values = new_values;
        slope.erase(slope.begin(), slope.end());
        vector<double> new_time;
        add_vectors(&time, &march, &new_time);
        time = new_time;
        cout << endl;
	}


	cout << endl;
	
	return 0;
}
