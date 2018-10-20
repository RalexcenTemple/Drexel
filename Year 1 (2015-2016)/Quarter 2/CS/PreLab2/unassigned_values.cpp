// ----------------------------------------------------------------------------
//
// ----------------------------- Unassigned Values ----------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose : To see what values are assigned to data 
//            objects upon creation.
//
//  Author  : Paul Zoski
//  Date    : 4/3/99
//  Modified: reformatted, JL Popyack Jan. 2003.
//
// ----------------------------------------------------------------------------

	#include <iostream> 
	using namespace std;
 
// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------

	int main(void)
	{
		int normal_sized_int;
		short int short_int;
		long int long_int;
		
		float normal_sized_float;
		double normal_sized_double;
		long double long_double;
		
		char a_character;

		cout << "The normal sized int was assigned the value: " 
		     << normal_sized_int << endl;
		cout << "The short int was assigned the value: " 
		     << short_int << endl;
	 	cout << "The long int was assigned the value: " 
	 	     << long_int << endl << endl;;
		
		cout << "The normal sized float was assigned the value: " 
		     << normal_sized_float << endl;
		cout << "The normal sized double was assigned the value: " 
		     << normal_sized_double << endl;
		cout << "The long double was assigned the value: " 
		     << long_double << endl << endl;
		
		cout << "The char was assigned the value: " 
		     << a_character << endl;
		
		return 0;
	}