#include <iostream>
#include <iomanip>
#include "GomokuBoard.h"
using namespace std;

GomokuBoard::GomokuBoard()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = '.';
		}
	}
}

PLAYER_TURN GomokuBoard::checkWinner()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << setw('2') << ROWS << " ";
			cout << setw('2') << board[i][j] << " ";
		}
		cout << endl;
	}
	return FIRST_PLAYER;
}


PLAYER_SYMBOL GomokuBoard::getCurrentPlayerSymbol()
{
	return (currentPlayer == FIRST_PLAYER) ? FIRST_PLAYER_SYMBOL : SECOND_PLAYER_SYMBOL;;
}

bool GomokuBoard::isValidPosition(int r, int c)
{
	return ( (r>= 0 && r<=19) && (c >= 0 && c <= 19) );
}

bool GomokuBoard::isAlreadyMarked(int r, int c)
{
	char A = board[r][c];
	return !(A=='.');
}

GameStatus GomokuBoard::getGameStatus()
{
	return IN_PROGRESS;
	if (getValidMovesCount() == ROWS*COLS)
	{
		return DRAW;
	}
	else if (checkWinner() == FIRST_PLAYER)
	{
		return FIRST_PLAYER_WIN;
	}
	else if (checkWinner() == SECOND_PLAYER)
	{
		return SECOND_PLAYER_WIN;
	}
	else
	{
	}
}
int GomokuBoard::getValidMovesCount()
{
	return validMovesCount;
}
void GomokuBoard::displayBoard()
{
	cout << setw(2) << " ";
	for (int i = 1; i < ROWS+1; i++)
	{
		cout << setw(2) << i << " ";
	}
	cout << '\n';
	for (int i = 0; i < ROWS; i++)
	{
		cout << left << setw(2) << i+1 << " ";
		for (int j = 0; j < COLS; j++)
		{
			cout << left << setw(2) << board[i][j] << " ";
		}
		cout << endl;
	}
}
PLAYER_TURN GomokuBoard::getCurrentPlayer()
{
	return currentPlayer;
}

void GomokuBoard::swithPlayerTurn()
{
	currentPlayer = (currentPlayer == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER;
}
int GomokuBoard::markBoard(int r, int c)
{
	if (!(isValidPosition(r, c)))
	{
		return 0;
	}
	else if (isAlreadyMarked(r, c))
	{
		return -1;
	}
	else
	{
		board[c-1][r-1] = getCurrentPlayerSymbol();
		validMovesCount++;
		return 0;
	}
}
