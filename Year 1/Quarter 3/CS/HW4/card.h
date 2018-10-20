#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card
{
  public:
	
    
    Card();          // default, ace of spades

    Card(int rank, string s);

    string toString()              const;  // return string version
    bool SameSuitAs(const Card& c) const;  // true if suit same as c
    int  getRank()                 const;  // return rank, 1..13
	int getSuitRank()      const;  // return "spades", "hearts",...
    bool IsJoker()                 const;  // true if card is valid
	string rankString(int r)       const;
	void setRank(int n);
	void setSuit(string s);
	int myRank;
	string mySuit;

    
};

ostream& operator << (ostream& out, const Card& c);
bool operator == (const Card& lhs, const Card& rhs);
bool operator < (const Card& lhs, const Card& rhs);
bool operator > (const Card& lhs, const Card& rhs);
    


#endif
