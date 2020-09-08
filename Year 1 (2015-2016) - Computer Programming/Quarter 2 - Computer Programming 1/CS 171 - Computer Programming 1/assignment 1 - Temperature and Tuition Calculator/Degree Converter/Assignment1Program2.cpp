#include <iostream>
/*
@authored By: Reed Ceniviva
@Date 1/19/15
*/


using namespace std;

int main(void)
{

	//states the variables needed as integer types.
	int fo, tsp, gill, cp, pt, qu, gal, bar;


	//retrieves the number of fluid ounces from the user
	cout << "please enter the number of fluid ounces you want to be converted." << endl;
	cin >> fo;

	

	//does the convertions using remainders
	bar = (fo / 5376);
	fo = ( fo % 5376);
	gal = (fo / 128);
	fo = (fo % 128);
	qu = (fo / 32);
	fo = (fo % 32);
	pt = (fo / 16);
	fo = (fo % 16);
	cp = (fo / 8);
	fo = (fo % 8);
	gill = (fo / 4);
	fo = (fo % 4);
	tsp = (fo * 2);


	//prints the findings from the above calculations
	cout << fo << "fluid ounces is " << (int)tsp << " tablespoons" << endl;
	cout << fo << "fluid ounces is " << (int)gill << " gills" << endl;
	cout << fo << "fluid ounces is " << (int)cp << " cups" << endl;
	cout << fo << "fluid ounces is " << (int)pt << " pints" << endl;
	cout << fo << "fluid ounces is " << (int)qu << " quarts" << endl;
	cout << fo << "fluid ounces is " << (int)gal << " gallons" << endl;
	cout << fo << "fluid ounces is " << (int)bar << " barrels" << endl;


	std::cin.ignore(1);

cout << "Enter anything to end the program" << endl;
cin.get();

return 0;
}



