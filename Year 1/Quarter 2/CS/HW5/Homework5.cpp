#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name);
void updateStatus(double &velocity, double burnAmount, double &fuelRemaining, double &height);
void touchdown(double &elapsedTime, double &velocity, double &burnAmount, double &height);
void finalAnalysis(ostream &os, double velocity);
void introduction(istream &is, ostream &os, string target, string replacement);


int main(void)
{
	double velocity = 5;
	double height = 1000;
	double time = 0;
	double fuel;
	double fuelRemaining = 150;
	ifstream is;
	is.open("input.txt");
	ofstream os;
	os.open("output.txt");
	string name = "";
	cout << "please enter the name of your spacecraft: " << endl;
	cin >> name;

	cout << "would you like to see the instructions? (y or n)" << endl;
	char yn;
	cin >> yn;
	switch (yn)
	{
	case 'y':
		introduction(is, cout, "$SPACECRAFT", name);
	}


	// to loop every second to allow the user to make changes to different variables
	while (height >= 0)
	{
		if (fuelRemaining <= 0)// check if the fuel has run out
		{
			fuelRemaining = 0;
			cout << "There is no more fuel to burn" << endl;
		}
		else
		{
			cout << "Enter fuel burn amount: " << endl;
			cin >> fuel;
			if (fuel < 0 || fuel > 30){ // check if the fuel to use is a valid input
				cout << "please enter a positive value for fuel bellow 30 now" << endl;
				cin >> fuel;
			}
			if ((fuelRemaining - fuel) < 0) // check if the fuel to use is greater than the fuel available
			{
				fuel = fuelRemaining;// to use the remaining fuel
				//fuelRemaining = fuelRemaining - fuel;
			}
			else
			{
				//fuelRemaining = fuelRemaining - fuel;
			}
		}

		time++; // incrimenting the number of seconds that have passed
		reportStatus(cout, time, height, velocity, fuelRemaining, name); // to output a check on the status
		updateStatus(velocity, fuel, fuelRemaining, height);
	}
	touchdown(time, velocity, fuel, height);
	reportStatus(cout, time, height, velocity, fuel, name);
	finalAnalysis(cout, velocity);

	cout << "enter a number to end the program" << endl;
	int END;
	cin >> END;
	is.close();
	os.close();
}


//output data in a user friendly and as directed way to show the status of the decent
void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name)
{
	os << "Status of your " << name << " spacecraft: " << endl;
	os << setw(6) << setfill(' ') << "Time" << ":" << "  " << time << " seconds" << endl;
	os << setw(6) << setfill(' ') << "Height" << ":" << "  " << height << " feet" << endl;
	os << setw(6) << setfill(' ') << "Speed" << ":" << "  " << velocity << " feet/sec/sec" << endl;
	os << setw(6) << setfill(' ') << "Fuel" << ":" << "  " << fuel << " units" << endl;
}


// to update the status variables of the spacecraft
void updateStatus(double &velocity, double burnAmount, double &fuelRemaining, double &height)
{
	fuelRemaining = (fuelRemaining - burnAmount); // update amount of fuel based on the amount used
	double tempVel = velocity; // set value for velocity when the function is called 
	velocity += 5; // adjusting velocity for gravity
	velocity -= burnAmount; // adjusting gravity due to thrust
	double fall; // varaible for the distance decended 
	fall = (velocity + tempVel) / 2; // calculate the distence dropped
	height -= fall; // finding the current hieght of the spacecraft
}

//the introduction of the program
void introduction(istream &is, ostream &os, string target, string replacement)
{
	string n; //to hold the line read in

	while (!is.eof()){ // to scan through the program
		getline(is, n, '\n'); // to get the line
		while (n.find(target) != -1) // to see if the word is in a line
		{
			int targetPos = n.find(target);
			int targetSize = target.size();
			n.replace(targetPos, targetSize, replacement); // replaces the target word with the replacement word 
		}
		if (is.eof()) // mid loop check
		{
			break;
		}
		os << n << endl; // sends line to file with changes if neccassary
	}
}


//to find the exact time and velocity at touchdown of the spacecraft
void touchdown(double &elapsedTime, double &velocity, double &burnAmount, double &height)
{
	double oldVel = (velocity + (burnAmount - 5));
	double oldheight = height + (oldVel + velocity) / 2.0;
	double oldTime = (elapsedTime - 1.0);
	if (burnAmount == 5.0) //given formula does not work when the burned fuel is equal to zero
	{
		double Moment = oldheight / oldVel; // finding time passed 

		//setting the passed by refference variables to their correct values
		elapsedTime = (elapsedTime - (1 - Moment));
		velocity = (oldVel + ((5.0 - burnAmount)*Moment));
		height = 0.0;
	}
	else
	{
		//calculations neccassary to find the time elapsed in the last second before touchdown
		double toSquare = pow(oldVel, 2.0) + (oldheight * (10.0 - (2.0 * burnAmount)));
		double moment = (sqrt(toSquare) - oldVel) / (5.0 - burnAmount);

		//setting the elements to their correct values

		elapsedTime = (elapsedTime - (1 - moment));
		velocity = (oldVel + ((5.0 - burnAmount)*moment));
		height = 0.0;
	}
}



//function to output the condition of the spaceship and or the pilot when the spacecraft touches down on the lunar surface
void finalAnalysis(ostream &os, double velocity)
{

	// would have used a switch statement but i did not know how to handle parameters greater than a single integer or less than something, you know what i mean.
	if (velocity >= 0)
	{
		if (velocity == 0)
		{
			os << "Congratulations!A perfect landing!!" << endl << "Your license will be renewed...later." << endl;
		}
		else if (velocity > 0 && velocity < 2)
		{
			os << "A little bumpy." << endl;
		}
		else if (velocity >= 2 && velocity < 5)
		{
			os << "You blew it!!!!!! " << endl << "Your family will be notified...by post." << endl;
		}
		else if (velocity >= 5 && velocity < 10)
		{
			os << "Your ship is a heap of junk !!!!!" << endl << "Your family will be notified...by post." << endl;
		}
		else if (velocity >= 10 && velocity < 30)
		{
			os << "You blasted a huge crater !!!!!" << endl << "Your family will be notified...by post." << endl;
		}
		else if (velocity >= 30 && velocity < 50)
		{
			os << "Your ship is a wreck !!!!! " << endl << "Your family will be notified...by post." << endl;
		}
		else
		{
			os << "You totaled an entire mountain !!!!!" << endl << "Your family will be notified...by post." << endl;
		}
	}
	else
	{
		os << "The velocity was invalid" << endl;
	}
}
