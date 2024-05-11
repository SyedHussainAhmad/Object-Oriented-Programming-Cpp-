#include<iostream>
#include "GomokuBoard.h"
#include "GomokuGame.h"
using namespace std;

void GomokuGame::playGame()
{
	GomokuBoard board{};

	while (board.getGameStatus() == IN_PROGRESS)
	{
		board.displayBoard();
		int row, cols;
		cout << endl;
		cout << "Player " << board.getCurrentPlayerSymbol() <<  " Turn : Enter Position (row,column) : ";
		cin >> row >> cols;

		if (!(board.isValidPosition(row,cols) && board.isAlreadyMarked(row, cols)))
		{
			board.markBoard(row,cols);
		}

		if (board.getGameStatus() == FIRST_PLAYER_WIN)
		{
			board.displayBoard();
			cout << "\n" << board.getCurrentPlayerSymbol() << "player win: ";
		}
		else if (board.getGameStatus() == DRAW)
		{
			cout << "Game Draw " << endl;
		}
		else
		{
			board.swithPlayerTurn();
		}
	}
}