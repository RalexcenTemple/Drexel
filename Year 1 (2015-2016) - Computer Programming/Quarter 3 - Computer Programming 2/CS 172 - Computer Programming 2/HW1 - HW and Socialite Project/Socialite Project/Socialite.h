#include <string>
#include <sstream>
#include <ostream>

using namespace std;

class Socialite
{
public:
	Socialite(); //defualt contrustor
	Socialite(string lastName, string firstName, string userID, string picture, string website, string webdes); //alternative constructor


	//used to set the attributes of the object
	void setLastName(string newName);
	void setFirstName(string newName);
	void setUserID(string newUserID);
	void setPicture(string newPicture);
	void setWebsite(string newWebsite);
	void setWebDes(string newDesc);


	//mutators for the object
	string getLastName() const;
	string getFirstName() const;
	string getUserID() const;
	string getPicture() const;
	string getWebsite() const;
	string getWebDes() const;

	//used to export the objects to output and html
	ostream & toString(ostream &out);
	ostream & toHTML(ostream &out);

private:
	//private attributes for the object
	string lastName_;
	string firstName_;
	string userID_;
	string picture_;
	string website_;
	string webdes_;
};