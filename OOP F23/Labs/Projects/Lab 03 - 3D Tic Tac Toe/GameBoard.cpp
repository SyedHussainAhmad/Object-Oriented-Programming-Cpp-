#include "GameBoard.h"

//Private Functions:
void GameBoard::updateGameStatus()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)          //checking 3D WIN status
		{
			if ((data[0][i][j] < '1') || (data[0][i][j] > '9'))
			{
				if (data[0][i][j] == data[1][i][j] && data[1][i][j] == data[2][i][j])
				{
					gameStatus = WIN;
					return;
				}
			}
		}
	}

	int board = 0;
	while (board < 3)			//checking every board WIN status
	{
		if (checkBoardWinStatus(board))
		{
			gameStatus = WIN;
			return;
		}
		board++;
	}
	if (validMovesCount == 27)
		gameStatus = DRAW;
}

bool GameBoard::checkBoardWinStatus(int board)     //to check every board WIN status
{
	bool status = false;
	if ((data[board][0][0] == data[board][1][1] && data[board][1][1] == data[board][2][2]) || (data[board][0][2] == data[board][1][1] && data[board][1][1] == data[board][2][0]) || (data[board][1][0] == data[board][1][1] && data[board][1][1] == data[board][1][2]) || (data[board][0][1] == data[board][1][1] && data[board][1][1] == data[board][2][2]))
	{
		status = true;
	}
	else if ((data[board][0][0] == data[board][1][0] && data[board][1][0] == data[board][2][0]) || (data[board][0][0] == data[board][0][1] && data[board][0][1] == data[board][0][2]))
	{
		status = true;
	}
	else if ((data[board][2][2] == data[board][1][2] && data[board][1][2] == data[board][0][2]) || (data[board][2][2] == data[board][2][1] && data[board][2][1] == data[board][2][0]))
	{
		status = true;
	}
	return status;
}

//Public Functions:
GameBoard::GameBoard()
{
	char ch = '1';
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++, ch++)
			{
				data[i][j][k] = ch;
			}
		}
		ch = '1';
	}
}

void GameBoard::displayBoard()
{
	cout << endl;
	for (int j = 0; j <= 2; j++)
	{
		for (int k = 0; k <= 2; k++)
		{
			cout << " ";
			for (int i = 0; i <= 2; i++)
			{
				cout << data[k][j][i];
				cout << "   ";
			}
			cout << "    ";
		}
		cout << endl;
	}
	cout << "-----------      -----------      -----------\n     1\t              2\t               3";
	cout << "\n\n";
}

void GameBoard::markBoard(int pos, char playerSymbol)
{
	int i = (pos / 10) - 1, j = (pos % 10) - 1;
	data[i][j / 3][j % 3] = playerSymbol;
	validMovesCount++;
	updateGameStatus();                //updating gameStatus
}

bool GameBoard::isValidPosition(int pos)
{
	if ((pos / 10) < 1 || (pos / 10) > 3)
		return false;
	return ((pos % 10) >= 1 && (pos % 10) <= 9);
}

bool GameBoard::isAlreadyMarked(int pos)
{
	int i = (pos / 10) - 1, j = (pos % 10) - 1;
	return (!(data[i][j / 3][j % 3] >= '1' && data[i][j / 3][j % 3] <= '9'));
}

int GameBoard::getValidMovesCount()
{
	return validMovesCount;
}

GameStatus GameBoard::getGameStatus()
{
	return gameStatus;
}
