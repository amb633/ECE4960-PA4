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
    RUN_function_pointer();
}
