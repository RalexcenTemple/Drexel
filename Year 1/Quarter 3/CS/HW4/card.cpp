#include "card.h"

Card::Card()
{
	int myRank = 1;
	string mySuit = "spades";
}

Card::Card(int rank, string s)
{
	//cout << "rank: " << rank << "| suit: " << s << endl;
	int myRank = rank;
	string mySuit = s;
	//cout << "rank: " << myRank << "| suit: " << mySuit << endl;
}

/*
int Card::getSuitRank() const
{
	if (mySuit == "spades")        return 3;
	else if (mySuit == "hearts")   return 1;
	else if (mySuit == "diamonds") return 2;
    else                    return 0;
}
*/

void Card::setSuit(string s)
{
	mySuit = s;
}

void Card::setRank(int n)
{
	myRank = n;
}


string Card::rankString(int r) const
// pre: 1 <= r <= 13
{
	//cout << "r: " << r << endl;
    if (1 == r)       return "ace";
    else if (2 == r)  return "two";
    else if (3 == r)  return "three";
    else if (4 == r)  return "four";
    else if (5 == r)  return "five";
    else if (6 == r)  return "six";
    else if (7 == r)  return "seven";
    else if (8 == r)  return "eight";
    else if (9 == r)  return "nine";
    else if (10 == r) return "ten";
    else if (11 == r) return "jack";
    else if (12 == r) return "queen";
    else if (13 == r) return "king";
    else return "joker";
}

string Card::toString() const
{
	return rankString(myRank) + " of " + mySuit;
}

bool Card::SameSuitAs(const Card& c) const
{
    return mySuit == c.mySuit;
}

int Card::getRank() const
{
    return myRank;
}

bool Card::IsJoker() const
{
    return myRank < 1 || 13 < myRank;
}

ostream& operator <<(ostream& out, const Card& c)
{
    out << c.toString();
    return out;
}

bool operator == (const Card& lhs, const Card& rhs)
{
    if (lhs.IsJoker() || rhs.IsJoker())
    {
	return false;
    }
    return lhs.getRank() == rhs.getRank();
}

bool operator < (const Card& lh, const Card& rh)
{

	//if (lh.IsJoker() || rh.IsJoker()) return false;
	//cout << "left rank value" << lh.getRank() << endl;
	//cout << "right rank value" << rh.getRank() << endl;
	if (lh.getRank() < rh.getRank()) return true;
	return false;

}

bool operator > (const Card& lh, const Card& rh)
{

	//if (lh.IsJoker() || rh.IsJoker()) return false;
	//cout << "left rank value" << lh.getRank() << endl;
	//cout << "right rank value" << rh.getRank() << endl;
	if (lh.getRank() > rh.getRank()) return true;
	return false;

}