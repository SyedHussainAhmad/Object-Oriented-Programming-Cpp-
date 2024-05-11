#include "TicTacToe.h"

//Private Functions:
bool TicTacToe::isValidPlayerSymbol(char symbol)
{
	return !(symbol >= '1' && symbol <= '9');
}

void TicTacToe::initPlayers(char& player1Symbol, char& player2Symbol)
{
	bool validSymbol;
	do
	{
		cout << "Enter Player 1 Symbol : ";
		cin >> player1Symbol;
		validSymbol = isValidPlayerSymbol(player1Symbol);
		if (!validSymbol)
			cout << "Not a Valid Symbol!\n";
	} 
	while (!validSymbol);

	do
	{
		cout << "\nEnter Player 2 Symbol : ";
		cin >> player2Symbol;
		validSymbol = isValidPlayerSymbol(player2Symbol);
		if (!validSymbol || player2Symbol == player1Symbol)
			cout << "Not a Valid Symbol!\n";
	} 
	while (!validSymbol || player2Symbol == player1Symbol);
}

//Public Functions:
void TicTacToe::playGame()
{
	char player1Symbol;
	char player2Symbol;
	initPlayers(player1Symbol,player2Symbol);

	GameBoard board;
	int pos;


	PlayerTurn currentPlayer = FIRST_PLAYER;
	char currentSymbol = player1Symbol;
	while (board.getGameStatus() == IN_PROGRESS)
	{
		bool status = false;
		board.displayBoard();
		do
		{
			cout << "\nPlayer " << currentPlayer << " turn: Enter Cell #: ";
			cin >> pos;
			if (board.isValidPosition(pos) && !board.isAlreadyMarked(pos))
			{
				board.markBoard(pos, currentSymbol);
				status = true;
			}
		} 
		while (!status);

		if (board.getGameStatus() == WIN)
		{
			cout << "\nPlayer " << currentPlayer << " WON !";
		}
		else if (board.getGameStatus() == DRAW)
		{
			cout << "\nGame has DRAWN";
		}
		else
		{
			currentSymbol = (currentPlayer == FIRST_PLAYER ? player2Symbol : player1Symbol);
			currentPlayer = (currentPlayer == FIRST_PLAYER ? SECOND_PLAYER : FIRST_PLAYER);
		}
	}
	board.displayBoard();
}
