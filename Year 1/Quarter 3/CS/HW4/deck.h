#ifndef _DECK_H
#define _DECK_H

#include "card.h"
#include <vector>
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// GetCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by Size())
// The idea is that after shuffling, calling GetCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling Shuffle again replenishes the deck with 52 cards.



class Deck
{
  public:
    Deck();           // pristine, sorted deck

    void Shuffle();   // shuffle the deck, all 52 cards present
    Card GetCardTop();   // get a card, after 52 a joker is returned
	void addCardBot(Card c);
	Deck dealDeck(int n);
    int  Size() const; // # cards left in the deck
	vector <Card> myDeck;
	void printDeck();
  private:
	
};

#endif
