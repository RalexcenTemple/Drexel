#include <string>
#include <iostream>
#include <fstream>
#include "Socialite.h"

using namespace std;

Socialite::Socialite()//defualt constructor
{
	lastName_ = "";
	firstName_ = "";
	userID_ = "";
	picture_ = "";
	website_ = "";
	webdes_ = "";
	vector <string> clique;
	cliques_ = clique;
}

//alternative constructor
Socialite::Socialite(string lastName, string firstName, string userID, string picture, string website, string webdes)
{
	lastName_ = lastName;
	firstName_ = firstName;
	userID_ = userID;
	picture_ = picture;
	website_ = website;
	webdes_ = webdes;
	vector <string> clique;
	cliques_ = clique;
}
Socialite::Socialite(string lastName, string firstName, string userID, string picture, string website, string webdes, vector <string> cliques)
{
	lastName_ = lastName;
	firstName_ = firstName;
	userID_ = userID;
	picture_ = picture;
	website_ = website;
	webdes_ = webdes;
	cliques_ = cliques;
}

//the mutators used to assign attributes for the object
void Socialite::setLastName(string newName)
{
	lastName_ = newName;
}
void Socialite::setFirstName(string newName)
{
	firstName_ = newName;
}
void Socialite::setUserID(string newUserID)
{
	userID_ = newUserID;
}
void Socialite::setPicture(string newPicture)
{
	picture_ = newPicture;
}
void Socialite::setWebsite(string newWebsite)
{
	website_ = newWebsite;
}
void Socialite::setWebDes(string newDesc)
{
	webdes_ = newDesc;
}
void Socialite::addClique(string newClique)//used to add a clique to a socialite
{
	cliques_.push_back(newClique);
}



//inspectors used to look at the attributes of the class
string Socialite::getLastName() const 
{
	return lastName_;
}
string Socialite::getFirstName() const
{
	return firstName_;
}
string Socialite::getUserID() const
{
	return userID_;
}
string Socialite::getPicture() const
{
	return picture_;
}
string Socialite::getWebsite() const
{
	return website_;
}
string Socialite::getWebDes() const
{
	return webdes_;
}

//inspectors used to look at the number of cliques or a single given clique
int Socialite::getNumCliques() const
{ 
	return cliques_.size();
}
string Socialite::getClique(int x) const
{ 
	if (x < cliques_.size())
	{
		return cliques_[x];
	}
}


//used to output the objects to text or html/stream
void Socialite::toString(ostream &out)
{
	out << "First Name: " << firstName_ << endl << "Last Name: " << lastName_ << endl << "User ID: " << userID_ << endl << "Picture: " << picture_ << endl
		<< "Website: " << website_ << endl << "Website Description: " << webdes_ << endl << "Cliques:" << endl;
	for (int i = 0; i < cliques_.size(); i++)
	{
		out << cliques_[i] << endl;
	}
} 
void Socialite::toHTML(ostream &out)
{
	 out << "<html>" << endl
		<< "<head>" << endl
		<< "<title>" << firstName_ << " " << lastName_ << "'s Socialite Page</title>" << endl
		<< "</head>" << endl
		<< "<body>" << endl
		<< "<img SRC=\"" << picture_ << "\" ALT=\"" << firstName_ << " " << lastName_ << "\'s picture\" ALIGN=\"RIGHT\" height=\"500px\" />" << endl
		<< "<h1>Socialite</h1>"
		<< "<h2>" << firstName_ << " " << lastName_ << "</h2>"
		<< "<hr />"
		<< "<p>" << firstName_ << " wants to share <a HREF = \"" << website_ << "\" TARGET = _blank>" << webdes_ << " <break> < / a> with you : <br / >" << website_ << "</p>" << endl
		<< "<hr />" << endl
		<< "<p><i>Cliques:</i></p>" << endl
		<< "<ul>" << endl;
		for (int i = 0; i < cliques_.size(); i++)
		{
			out << "<li>" <<cliques_[i] << "</li>" << endl;
		}
		out << "</ul>" << endl
		<< "</body>" << endl
		<< "</html>";
}


/*
int main()
{
	//setting up the streams for the file modifications
	
	ofstream TextOne;
	TextOne.open("textOut1.txt");
	ofstream SiteOne;
	SiteOne.open("Site1.html");

	ofstream TextTwo;
	TextTwo.open("textOut2.txt");
	ofstream SiteTwo;
	SiteTwo.open("Site2.html");

	ofstream TextThree;
	TextThree.open("textOut3.txt");
	ofstream SiteThree;
	SiteThree.open("Site3.html");

	ofstream TextFour;
	TextFour.open("textOut4.txt");
	ofstream SiteFour;
	SiteFour.open("Site4.html");

	ofstream TextFive;
	TextFive.open("textOut5.txt");
	ofstream SiteFive;
	SiteFive.open("Site5.html");


	//object for my own profile
	Socialite Reed;
	//setting up attributes 
	Reed.setLastName("Ceniviva");
	Reed.setFirstName("Reed");
	Reed.setUserID("5647");
	Reed.setPicture("https://pbs.twimg.com/profile_images/547293093159247872/7iPHOYsI.jpeg");
	Reed.setWebsite("http://www.script-o-rama.com/movie_scripts/a1/bee-movie-script-transcript-seinfeld.html");
	Reed.setWebDes("The Entire Bee Movie Script");
	
	Reed.toString(TextOne);
	Reed.toHTML(SiteOne);

	//entertainer/sports person
	Socialite Mango;
	//setting up attributes 
	Mango.setLastName("Marquez");
	Mango.setFirstName("Joseph");
	Mango.setUserID("12101991");
	Mango.setPicture("https://i.ytimg.com/vi/syqQbSu5KQ4/hqdefault.jpg");
	Mango.setWebsite("https://www.twitch.tv/mang0");
	Mango.setWebDes("Mango Live Twitch Streaming Chanel");

	//sending the attributes to files
	Mango.toString(TextTwo);
	Mango.toHTML(SiteTwo);


	//political person
	Socialite Napoleon;
	//setting up attributes 
	Napoleon.setLastName("Napoleon");
	Napoleon.setFirstName("Bonaparte");
	Napoleon.setUserID("50068546");
	Napoleon.setPicture("http://i.telegraph.co.uk/multimedia/archive/01818/napoleon_1818323b.jpg");
	Napoleon.setWebsite("http://www.biography.com/people/napoleon-9420291");
	Napoleon.setWebDes("Small Biography about me");

	//sending the attributes to files
	Napoleon.toString(TextThree);
	Napoleon.toHTML(SiteThree);

	//cartoon
	Socialite Rick;
	//setting up attributes 
	Rick.setLastName("Rick");
	Rick.setFirstName("Sanchez");
	Rick.setUserID("73195857");
	Rick.setPicture("https://pbs.twimg.com/profile_images/618808516036440064/D6IBXCCc.jpg");
	Rick.setWebsite("http://www.adultswim.com/games/web/rick-and-mortys-rushed-licensed-adventure/");
	Rick.setWebDes("Rick and Morty's Ruched Licensed Adventure");

	//sending the attributes to files
	Rick.toString(TextFour);
	Rick.toHTML(SiteFour);

	//other(Street art character)
	Socialite Bines;
	//setting up attributes 
	Bines.setLastName("Bines");
	Bines.setFirstName("");
	Bines.setUserID("215311");
	Bines.setPicture("https://c2.staticflickr.com/2/1642/25848937875_eb18a22eed_b.jpg");
	Bines.setWebsite("https://www.youtube.com/channel/UC9vrYkPaH1D60jr4jwGDIlg");
	Bines.setWebDes("Free Radio Revolution");

	//sending the attributes to files
	Bines.toString(TextFive);
	Bines.toHTML(SiteFive);
	
}
*/