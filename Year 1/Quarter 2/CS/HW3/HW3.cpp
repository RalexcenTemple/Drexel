#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//declaring the prototypes
void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC);
string impairment(double bac);
int promptForInteger(string const &message, int lower, int upper);
char promptForMorF(string const &message);
void showImpairmentChart(int weight, int duration, bool isMale);

//constants given to use 
const double safe = 0.00;
const double someImpairment = 0.04;
const double significantAffected = 0.08;
const double someCriminalPenalties = 0.10;
const double deathPossible = 0.30;
const string SAFE = "Safe To Drive";
const string SOMEIMPAIR = "Some Impairment";
const string SIGNIFICANT = "Driving Skills Significantly Affected";
const string MOST_STATES = "Criminal Penalties in Most US States";
const string ALL_STATES = "Legally Intoxicated - Criminal Penalties in All US States";
const string YOURE_DEAD = "Death is Possible!";

int main(void)
{
	float amount = 0; // equal to number of drinks
	int numDrinks = 0; // the number of drinks injested
	const float beer = 12; // oz of the drink
	const float liquor = 1.25;// oz of the drink
	const float wine = 4;// oz of the drink
	int minutes = 0; // number of minutes
	int duration = 0; // total duration calculated by the minutes
	int weight = 0; // measured in pounds
	double maleBAC = 3.8; // given value
	double femaleBAC = 4.5;// given value
	int end = 0;//used to end the program
	string message = "Enter M if you are a boy and F if you are a girl"; // used to get the gender of the user


	//information for the program

	// BAC = volume of alcohol in blood / volume of blood 
	// volume of alcohol = (drinks/weight) constant(4.5 for females, 3.8 for males)
	// BAC is reduced by .01 every 40 minutes
	//exmpl: 130 female with 3 drinks after 80 minutes has a BAC of .084
	//exmpl: 160 female with 3 drinks after 300 minutes has a BAC of .0094

	// BAC Description:
	//0.00 = safe to drive
	//0.00 - 0.04 = some impairment
	//0.04 - 0.08 = Driving skills significantly affected 
	//0.08 - 0.10 = Criminal Penalties in Most US States
	//>0.10 = Legally intoxicated - criminal penalties in all US states
	// > .30 = possible death

	//prompting the user for nessacary information
	cout << "please enter your weight: ";
	cin >> weight;
	cout << endl;
	cout << "How many minutes has it been since your last drink: ";
	cin >> minutes; 
	cout << endl;

	char Male = ' ';
	bool male = false;

	Male = promptForMorF(message);


	//setting a bool as a result of the char returned from calling promptForMorF

	if (Male == 'M'){
		male = true;
	}
	else if (Male == 'F')
	{
		male = false;
	}
		duration = minutes;
	

	//computeBloodAlcoholConcentration(numDrinks, weight, minutes, maleBAC, femaleBAC);

	//cout << "maleBAC: " << setprecision(3) << maleBAC << "| femaleBAC: " << setprecision(3) << femaleBAC << endl;


	//using the information given we then display the results by calling showImpairmentChart
	showImpairmentChart(weight, minutes, male);


	//allows the user to manually end the program
	cout << "enter a number to end the program: " << endl;
	cin >> end;

}

//compute the BAC of both male and female and setting the value for the paramter maleBAC and femaleBAC respectivly to the results
void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC)
{
	double MBAC = 3.8;
	double FBAC = 4.5;

	//used to make sure someone who does not drink is not given a negative BAC
	if (numDrinks == 0)
	{
		duration = 0;
	}
	//sets the parameters to the result of the BAC equation for both female and male
	maleBAC = ((numDrinks / (double)weight) * (MBAC)) - (.1 * duration * 0.0025);
	femaleBAC = ((numDrinks / (double)weight) * FBAC) - (.1 * duration * 0.0025);

	//meant to catch any negative BAC that result from large durations or numDrinks
	if (maleBAC < 0.0)
	{
		maleBAC = 0;
	}
	if (femaleBAC < 0.0)
	{
		femaleBAC = 0;
	}


}

//returns a string describing how impaired a person is based on the bac that it is sent as a parameter
string impairment(double bac)
{
	if (bac == safe)
	{
		return(SAFE);
	}
	else if (bac < someImpairment)
	{
		return(SOMEIMPAIR);
	}
	else if (bac < significantAffected)
	{
		return(SIGNIFICANT);
	}
	else if (bac < someCriminalPenalties)
	{
		return(MOST_STATES);
	}
	else if (bac <= deathPossible)
	{
		return(ALL_STATES);
	}
	else if (bac > deathPossible)
	{
		return(YOURE_DEAD);
	}

}

//asks for an integer, checks if the integer given is above or equal to the parameter "lower" and below or equal to the parameter "upper", then returns the entered integer, or asks for a valid one
int promptForInteger(string const &message, int lower, int upper)
{
	//(i dont know why we needed this function, i never used it)
	int integer = 0;
	cout << message << endl;
	cin >> integer;
	if (integer >= lower && integer <= upper)
	{
		return integer;
	}
	else
	{
		promptForInteger(message, lower, upper);
	}
	
}

//asks the user if they are a male or a female and returns a char 'M' or 'F', if the user enters an invalid char that the program asks for one again until it gets a correct char
char promptForMorF(string const &message)
{
	cout << message << endl;
	char MF;
	cin >> MF;
	char m = 'M';
	char f = 'F';
	//checks if the given char is one of the char that we are looking for
	if (MF == m || MF == f){
		return MF;
	}
	else
	{
		promptForMorF(message);
	}
}

//outputs a chart that represents the users BAC at different numbers of drinks after a certain number of minutes that the user gives, and based on their weight that they give
void showImpairmentChart(int weight, int duration, bool isMale)
{
	//used to hold the resulting value from computeBloodAlcoholCOncentration
	double male;
	double female;

	//checks the bool that was sent
	if (isMale)
	{
		//outputs neccassary information that was asked for us to show
		cout << weight << " pounds, male, " << duration << " minutes since last drink" << endl;
		cout << "# drinks   BAC Status" << endl;

		//displays a chart as depicted in the reading of the BAC and the amount of impairment as a result of drinks 1-10 in the given time for a given persons weight
		for (int i = 0; i < 11; i++)
		{
			computeBloodAlcoholConcentration(i, weight, duration, male, female);
			double bac = male;
			std::cout << setw(7) << " " << i << " " << fixed << setprecision(3) << bac << " " << impairment(bac) << endl;
		}
	}
	else
	{
		cout << weight << " pounds, female, " << duration << " minutes since last drink" << endl;
		cout << "# drinks    BAC Status" << endl;
		for (int i = 0; i < 11; i++)
		{
			computeBloodAlcoholConcentration(i, weight, duration, male, female);
			double bac = female;
			std::cout << setw(7) << " " << i << " " << setprecision(4) << bac << " " << impairment(bac) << endl;
		}
	}
}
