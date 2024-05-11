#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "GameBoard.h"

class TicTacToe
{
private:
	char getSymbolOfPlayer(int playerNo);
	bool isValidPlayerSymbol(char symbol);
public:
	void playGame();
};
#endif // !TIC_TAC_TOE_H
