#include <iostream>

#include "deck.h"
#include "card.h"


int main()
{
	Deck deck;
	//deck.printDeck();
//	lhand.myDeck.clear();
//	rhand.myDeck.clear();

	deck.Shuffle();
	//deck.printDeck();
	Deck lhand = deck.dealDeck(deck.myDeck.size() / 2);
	Deck rhand = deck.dealDeck(deck.myDeck.size());
	//lhand.printDeck();
	//cout << "-----------------------------" << endl;
	//rhand.printDeck();
	cout << "-----------------------------" << endl;
	
	while (lhand.myDeck.size() > 0 && rhand.myDeck.size() > 0)
	{
		Card ltop = lhand.GetCardTop();
		Card rtop = rhand.GetCardTop();
		cout << ltop << " vs " << rtop << endl;
		deck.myDeck.push_back(rtop);
		deck.myDeck.push_back(ltop);
		if ( deck.myDeck[deck.myDeck.size()-2] > deck.myDeck[deck.myDeck.size()-1] )
		{
			//cout << "left win" << endl;
			for (int i = 0; i < deck.myDeck.size(); i++)
				lhand.addCardBot(deck.myDeck[i]);
		}
		else if (deck.myDeck[deck.myDeck.size() - 2] < deck.myDeck[deck.myDeck.size() - 1])
		{
			//cout << "right win" << endl;
			for (int i = 0; i < deck.myDeck.size(); i++)
				rhand.addCardBot(deck.myDeck[i]);
		}
		else if (deck.myDeck[deck.myDeck.size() - 2] == deck.myDeck[deck.myDeck.size() - 1])
		{
			cout << "WAR" << endl;
			Card ltopwar = lhand.GetCardTop();
			Card rtopwar = rhand.GetCardTop();
			deck.myDeck.push_back(rtopwar);
			deck.myDeck.push_back(ltopwar);
		}
	}
	if (lhand.myDeck.size() == 0)
		cout << "left has lost, Right has won!" << endl;
	else
		cout << "right has lost, Left has won!" << endl;

	cout << "enter a number to end the program" << endl;
	int end = 0;
	cin >> end;
}
