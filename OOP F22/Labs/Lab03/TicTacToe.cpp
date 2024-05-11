#include <iostream>
#include "TicTacToe.h"
using namespace std;

char TicTacToe::getSymbolOfPlayer(int playerNo)
{
	char playerSymbol;
	bool validSymbol;
	do
	{
		cout << "Enter Player " << playerNo << " symbol: ";
		cin >> playerSymbol;
		validSymbol = isValidPlayerSymbol(playerSymbol);
		if (!validSymbol)
		{
			cout << "Not a Valid Symbol \n";
		}
	} while (!validSymbol);
	return playerSymbol;
}

bool TicTacToe::isValidPlayerSymbol(char symbol)
{
	return !(symbol >= '1' && symbol <= '9');
}

void TicTacToe::playGame()
{
	GameBoard board{};
	char player1Symbol;
	char player2Symbol;
	player1Symbol = getSymbolOfPlayer(1);
	player2Symbol = getSymbolOfPlayer(2);
	while (player1Symbol == player2Symbol)
	{
		player2Symbol = getSymbolOfPlayer(2);
	}
	char cellNumber;
	PlayerTurn currentPlayer = FIRST_PLAYER;
	char currentPlayerSymbol = player1Symbol;
	//cout << board.getGameStatus() << endl;// == IN_PROGRESS

	while (board.getGameStatus() == IN_PROGRESS)
	{
		board.displayBoard();
		cout << endl;
		cout << "Player " << currentPlayer << " Turn : Enter Position : ";
		cin >> cellNumber;
		if (board.isValidPosition(cellNumber) && board.isAlreadyMarked(cellNumber) == false)
		{
			board.markBoard(cellNumber, currentPlayerSymbol);
		}
		if (board.getGameStatus() == WIN)
		{
			board.displayBoard();
			cout << "\nGame won by player : " << currentPlayer << endl;
		}
		else if (board.getGameStatus() == DRAW)
		{
			cout << "Game Draw " << endl;
		}
		else
		{
			if (currentPlayer == FIRST_PLAYER)
			{
				currentPlayer = SECOND_PLAYER;
				currentPlayerSymbol = player2Symbol;
			}
			else
			{
				currentPlayer = FIRST_PLAYER;
				currentPlayerSymbol = player1Symbol;
			}
		}
	}
}
