#include <iostream>
/*
@authored By: Reed Ceniviva
@Date 1/19/15
*/

using namespace std;

int main(void)
{
	//all varaibles needed for the program to run the way I set it up.
	double tuition , percent, yearTwo , yearThree, yearFour, yearFive, totalTuition;

	//retrieving the yearly tuition from the user
	cout << "Please enter the amount of tuition in dollars. (example: 40000)" << endl;
	cin >> tuition;
	cout << endl;
	
	//retrieving the annual percent of change from the user
	cout << "Please enter a percentage of yearly increase. (example: 5 for 5%)" << endl;
	cin >> percent;
	percent = (percent / 100);
	cout << endl;


	std::cin.ignore(1);

	//finding the cost of each year given the percent of change and the tuition
	//also finding the total cost over the five years
	yearTwo = (tuition + (tuition*percent));
	yearThree = (yearTwo + (yearTwo*percent));
	yearFour = (yearThree + (yearThree*percent));
	yearFive = (yearFour + (yearFour*percent));
	totalTuition = (tuition + yearTwo + yearThree + yearFour + yearFive);

	//printing the results of the evaluated variables
	cout << "First years' tuition cost: " << tuition << endl;
	cout << "Second years' tuition cost " << yearTwo << endl;
	cout << "Third years' tuition cost " << yearThree << endl;
	cout << "Fourth years' tuition cost " << yearFour << endl;
	cout << "Five years' tuition cost " << yearFive << endl;
	cout << "The total cost of Tuition over 5 years is " << totalTuition << endl;



	

cout << "Enter anything to end the program" << endl;
cin.get();

return 0;
}
