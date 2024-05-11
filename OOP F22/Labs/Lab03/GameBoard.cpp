#include<iostream>
using namespace std;
#include "GameBoard.h"

GameBoard::GameBoard()
{
	int  num = 49;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = num;
			num++;
		}
	}
}

void GameBoard::displayBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

bool GameBoard::checkWinningStatus()
{
	if (data[0][0] == data[1][1] && data[1][1] == data[2][2])
	{
		return true;
	}
	else if (data[0][2] == data[1][1] && data[1][1] == data[2][0])
	{
		return true;
	}
	else if (data[0][0] == data[0][1] && data[0][1] == data[0][2] || data[2][0] == data[2][1] && data[2][0] == data[2][2])
	{
		return true;
	}
	else if (data[0][0] == data[1][0] && data[0][0] == data[2][0] || data[2][0] == data[1][2] && data[2][0] == data[2][2])
	{
		return true;
	}
	else if (data[0][1] == data[1][1] && data[1][1] == data[2][1])
	{
		return true;
	}
	else if (data[1][0] == data[1][1] && data[1][1] == data[1][2])
	{
		return true;
	}
	return false;
}

void GameBoard::markBoard(char pos, char playerSymbol)
{
	int position = pos - '0';
	if (!(isValidPosition(pos) && isAlreadyMarked(pos)))
	{
		data[(position - 1) / 3][(position - 1) % 3] = playerSymbol;
		validMovesCount++;
	}
}

bool GameBoard::isValidPosition(char pos)
{
	return (pos >= '0' && pos <= '9');
}

bool GameBoard::isAlreadyMarked(char pos)
{
	int position = pos - '0';
	char A = data[(position - 1) / 3][(position - 1) % 3];
	return !(A >= '0' && A <= '9');
}

int GameBoard::getValidMovesCount()
{
	return validMovesCount;
}

GameStatus GameBoard::getGameStatus()
{
	if (getValidMovesCount() == 9)
	{
		return DRAW;
	}
	else if (checkWinningStatus())
	{
		return WIN;
	}
	else
	{
		return IN_PROGRESS;
	}
}
