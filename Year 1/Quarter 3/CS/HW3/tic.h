// CS 172 - Assignment 3 - Tic-Tac-Toe
// Main File by Mark Boady
// Drexel University 2016

//You may add new methods (public or private) and new private attributes.
//You may NOT remove or change any methods given.

#ifndef _TIC_TAC_TOE_
#define _TIC_TAC_TOE_

#include <vector>
#include <iostream>
#include <string>
#include "symbol.h"
using namespace std;

class tBoard
{
	private:
		//You can pick your own data structure
	public:
		vector <symbol> tac;
		//Default Constructor
		//Makes a board with all blank spaces
		tBoard::tBoard();
		//Makes a move on the board
		//X is the row and y is the column
		//m is the symbol to place (either X or O)
		//It returns true if the move was made
		//If the move is illegal, return false and do not change the table
		bool tBoard::move(symbol m, int x, int y);
		//Returns true if the game is over
		//This could be because of a winner or because of a tie
		bool tBoard::game_over();
		//Returns who won X or O.
		//If the game was a tie, return  BLANK
		symbol tBoard::winner();
		//checks if three symbols in the indexs of the ints passed are the same symbol
		//returns true if the symbols are the same
		bool tBoard::areSame(int x, int y, int z);

		//bool tBoard::isSymbol(int x, int y);
};
//Overload the output operator
ostream & operator<<(ostream& os, const tBoard& myTable);

#endif
