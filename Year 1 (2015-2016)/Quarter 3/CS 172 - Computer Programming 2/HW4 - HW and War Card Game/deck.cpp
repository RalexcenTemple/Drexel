#include "deck.h"
#include "card.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int SIZE = 52;

Deck::Deck()
{
	for (int i = 0; i < 52; i++)
	{
		Card temp;
		myDeck.push_back(temp);
	}
	//put all the face values in an array as strings
	vector <int> faces { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	vector <string> Suit = { "clubs", "hearts", "diamonds", "spades" };
	//put all the suit values in an array as strings
	//initilize deck from the card class to a new array using the word "new"
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				myDeck[(13 * i) + j].setRank(faces[j]);
				myDeck[(13 * i) + j].setSuit(Suit[i]);
				//cout << myDeck[(13 * i) + j] << endl;
			}
		}
	
}

void Deck::Shuffle()
{

	srand(time(0));
	random_shuffle(myDeck.begin(), myDeck.end());

}

Card Deck::GetCardTop()
{

	Card temp = myDeck[myDeck.size() - 1];
	myDeck.pop_back();
	return temp;

}

void Deck::addCardBot(Card c)
{

	myDeck.insert(myDeck.begin(), c);

}

Deck Deck::dealDeck(int n)
{

	Deck Deal;
	Deal.myDeck.clear();
	for (int i = 0; i < n; i++)
	{
		Card temp = myDeck[myDeck.size()-1];
		Deal.myDeck.push_back(temp);
		myDeck.pop_back();
	}
	return Deal;

}

int Deck::Size() const
{
    return myDeck.size();
}

void Deck::printDeck()
{

	for (int i = 0; i < myDeck.size(); i++)
	{
		cout << myDeck[i] << endl;
	}

}