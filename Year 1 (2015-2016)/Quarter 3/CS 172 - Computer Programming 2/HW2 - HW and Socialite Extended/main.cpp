#include <string>
#include <iostream>
#include <fstream>
#include "Socialite.h"
#include "Socialite.cpp"

using namespace std;

void readIn(istream &in);


int main()
{
	ifstream socialites;
	socialites.open("Socialite_setup.txt");
	readIn(socialites);
	cout << "enter a number to end the program" << endl;
	int end = 0;
	cin >> end;
}

void readIn(istream &in)//reads in socialites from a file and outputs the information to the screen and creates socialite html files with the data.
{
	string line = "";//creates temp string to hold information read in
	while (!in.eof())// checks if the file has reached the end yet
	{
		Socialite temp;//temp socialite to hold the different socialite data
		
		//hardcode the first 6 lines of the socialite inport file.
		getline(in, line);
		temp.setUserID(line);
		getline(in, line);
		temp.setFirstName(line);
		getline(in, line);
		temp.setLastName(line);
		getline(in, line);
		temp.setPicture(line);
		getline(in, line);
		temp.setWebsite(line);
		getline(in, line);
		temp.setWebDes(line);
		getline(in, line);

		//loop to add in the cliques for the current socialite
		while (line != "++++")
		{
			temp.addClique(line);
			line = "";
			getline(in, line);
		}

		temp.toString(cout);//sends information to the screen
		string userHtml = temp.getUserID() + ".html"; // creates the string that holds the name of the html file to be made for the socialite
		ofstream userHTML;
		userHTML.open(userHtml);//creates html file to hold the socialite
		if (userHTML)
		{
			temp.toHTML(userHTML);//writes the socialite to the html
		}

	}