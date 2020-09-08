// ----------------------------------------------------------------------------
//
// ------------------------------ Spaghetti Code ------------------------------
//
// ----------------------------------------------------------------------------
//
//  Name    : SpaghettiCode
//  Version : 1.1
//  Purpose : Demonstration program to be used for 
//            examining effects of I/O manipulators.
//
//  Author  : Jeffrey L. Popyack
//  Date    : Jan. 20, 1998
//  Modified: Feb. 9, 1999
//            Reformatted: Jan. 8, 2002, Jan. 2003
//
// ----------------------------------------------------------------------------

	#include <iostream>
	#include <string>
	using namespace std; 

// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------

	int main( void )
	{
	// ---------------------------------------------------------------------
	//  These variables signify the respective
	//  costs of meals at Bernoulli's Pasta Palace: 
	// ---------------------------------------------------------------------

		double spaghettiCost   =  4.95 ,
		       vealPiccataCost = 11.95 , 
		       lasagnaCost     =  8.95 ;
		
		cout << "Meal" << "Cost" << endl ;
		cout << "Spaghetti" << spaghettiCost << endl ;
		cout << "Veal Piccata" << vealPiccataCost << endl ;
		cout << "Lasagna" << lasagnaCost << endl ;
		
		return 0 ;
	}  
