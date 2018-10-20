#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main(void)
{
	float gravity = -1.63;
	cout << "please enter the initial altitude in terms of meters" << endl;
	float altitude = 0;
	cin >> altitude;
	cout << "please enter the initial velocity in terms of meters per second" << endl;
	float velocity = 0;
	cin >> velocity;
	int second = 1;
	while ((altitude - (velocity*second + gravity*second)) >= 0)
	{
		float distance = (altitude - (velocity*second + gravity*second));
		cout << "distence from ground: " << distance << " meters" << endl;
		second++;
		cout << "Enter anything to continue the program" << endl;
		cin.get();
	}
	return 0;
}