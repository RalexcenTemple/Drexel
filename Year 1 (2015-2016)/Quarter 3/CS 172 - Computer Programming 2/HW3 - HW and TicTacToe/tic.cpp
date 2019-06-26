#include <vector>
#include <iostream>
#include <string>
#include "symbol.h"
#include "tic.h"

using namespace std;

ostream& operator<<(ostream& os, const tBoard& myTable)
{
	return os << " | 0 | 1 | 2 |" << endl
	 << " +-----------+" << endl
	 << "0| " << myTable.tac[0] << " | " << myTable.tac[1] << " | " << myTable.tac[2] << " |" << endl
	 << " +-----------+" << endl
	 << "1| " << myTable.tac[3] << " | " << myTable.tac[4] << " | " << myTable.tac[5] << " |" << endl
	 << " +-----------+" << endl
	 << "2| " << myTable.tac[6] << " | " << myTable.tac[7] << " | " << myTable.tac[8] << " |" << endl
	 << " +-----------+" << endl;
}


	//Default Constructor
	//Makes a board with all blank spaces
	tBoard::tBoard()
	{
		for (int i = 0; i < 9; i++)
		{
			tac.push_back(BLANK);
		}
	}

	//Makes a move on the board
	//X is the row and y is the column
	//m is the symbol to place (either X or O)
	//It returns true if the move was made
	//If the move is illegal, return false and do not change the table
	bool tBoard::move(symbol m, int x, int y)
	{
		string spotString = to_string(x) + to_string(y);
		int spot = stoi(spotString);
		int element = 0;

		switch (spot)
		{
		case 00:
			element = 0;
			break;
		case 01:
			element = 1;
			break;
		case 02:
			element = 2;
			break;
		case 10:
			element = 3;
			break;
		case 11:
			element = 4;
			break;
		case 12:
			element = 5;
			break;
		case 20:
			element = 6;
			break;
		case 21:
			element = 7;
			break;
		case 22:
			element = 8;
			break;
		}

		if (tac[element] == X || tac[element] == O)
		{
			return false;
		}
		else
		{
			tac[element] = m;
			return true;
		}
	}

	//Returns true if the game is over
	//This could be because of a winner or because of a tie
	bool tBoard::game_over()
	{
		if (areSame( 0, 1, 2))
		{
			return true;
		}
		else if (areSame( 3, 4, 5))
		{
			return true;
		}
		else if (areSame( 6, 7, 8))
		{
			return true;
		}
		else if (areSame( 0, 4, 8))
		{
			return true;
		}
		else if (areSame(2, 4, 6))
		{
			return true;
		}
		else if (areSame(0, 3, 6))
		{
			return true;
		}
		else if (areSame( 1, 4, 7))
		{
			return true;
		}
		else if (areSame( 2, 5, 8))
		{
			return true;
		}

		int counter = 0;
		for (int i = 0; i < 9; i++)
		{
			if (tac[i] != BLANK)
			{
				counter++;
			}
		}
		if (counter == 9)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Returns who won X or O.
	//If the game was a tie, return  BLANK
	symbol tBoard::winner()
	{
		if (areSame( 0, 1, 2))
		{
			return tac[0];
		}
		else if (areSame( 3, 4, 5))
		{
			return tac[3];
		}
		else if (areSame( 6, 7, 8))
		{
			return tac[4];
		}
		else if (areSame( 0, 4, 8))
		{
			return tac[0];
		}
		else if (areSame( 2, 4, 6))
		{
			return tac[2];
		}
		else if (areSame( 0, 3, 6))
		{
			return tac[0];
		}
		else if (areSame( 1, 4, 7))
		{
			return tac[1];
		}
		else if (areSame( 2, 5, 8))
		{
			return tac[2];
		}

		int counter = 0;
		for (int i = 0; i < 9; i++)
		{
			if (tac[i] != BLANK)
			{
				counter++;
			}
		}
		if (counter == 9)
		{
			return BLANK;
		}
	}

	bool tBoard::areSame(int x, int y, int z)
	{
		if (tac[x] != BLANK)
		{
			if (tac[x] == tac[y] && tac[y] == tac[z])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		
	}


