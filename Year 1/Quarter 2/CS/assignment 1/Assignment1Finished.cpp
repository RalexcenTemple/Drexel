#include <iostream>
#include <iomanip>
/*
@authored By: Reed Ceniviva
@Date 1/19/15
*/
/*
using namespace std;

int main(void)
{
	//all varaibles needed for the program to run the way I set it up.
	long tuition , yearTwo , yearThree, yearFour, yearFive, totalTuition;
	double percent;

	//retrieving the yearly tuition from the user
	cout << "Please enter the amount of tuition in dollars. (example: 40000)" << endl;
	cin >> tuition;
	tuition = tuition * 100;
	cout << endl;
	
	//retrieving the annual percent of change from the user
	cout << "Please enter a percentage of yearly increase. (example: 5 for 5%)" << endl;
	cin >> percent;
	percent = ((percent / 100)+1);
	cout << endl;


	std::cin.ignore(1);

	//finding the cost of each year given the percent of change and the tuition
	//also finding the total cost over the five years
	yearTwo = (tuition * percent);
	yearThree = (yearTwo * percent);
	yearFour = (yearThree * percent);
	yearFive = (yearFour * percent);
	totalTuition = (tuition + yearTwo + yearThree + yearFour + yearFive);

	int decimal = 2;

	//printing the results of the evaluated variables
	cout << "First years' tuition cost: " << fixed << setprecision(decimal) << tuition << endl;
	cout << "Second years' tuition cost " << fixed << setprecision(decimal) << yearTwo << endl;
	cout << "Third years' tuition cost " << fixed << setprecision(decimal) << yearThree << endl;
	cout << "Fourth years' tuition cost " << fixed << setprecision(decimal) << yearFour << endl;
	cout << "Five years' tuition cost " << fixed << setprecision(decimal) << yearFive << endl;
	cout << "The total cost of Tuition over 5 years is " << fixed << setprecision(decimal) << totalTuition << endl;



	

cout << "Enter anything to end the program" << endl;
cin.get();

return 0;
}
*/
