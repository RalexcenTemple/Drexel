#ifndef _Socialite_Header_
#define _Socialite_Header_

#include <string>
#include <sstream>
#include <ostream>
#include <vector>

using namespace std;

class Socialite
{
public:
	Socialite(); //defualt contrustor
	Socialite(string lastName, string firstName, string userID, string picture, string website, string webdes, vector <string> cliques); //alternative constructor
	Socialite(string lastName, string firstName, string userID, string picture, string website, string webdes);


	//used to set the attributes of the object /mutators
	void setLastName(string newName);
	void setFirstName(string newName);
	void setUserID(string newUserID);
	void setPicture(string newPicture);
	void setWebsite(string newWebsite);
	void setWebDes(string newDesc);
	void addClique(string newClique);//function for adding cliques


	//inspectors for the object
	string getLastName() const;
	string getFirstName() const;
	string getUserID() const;
	string getPicture() const;
	string getWebsite() const;
	string getWebDes() const;
	int getNumCliques() const; // getting the number of cliques for a socialites
	string getClique(int x) const; //gets a clique from a socialite at a certain point in the vector of cliques


	//used to export the objects to output and html
	void toString(ostream &out);
	void toHTML(ostream &out);

private:
	//private attributes for the object
	string lastName_;
	string firstName_;
	string userID_;
	string picture_;
	string website_;
	string webdes_;
	vector <string> cliques_;
};

#endif