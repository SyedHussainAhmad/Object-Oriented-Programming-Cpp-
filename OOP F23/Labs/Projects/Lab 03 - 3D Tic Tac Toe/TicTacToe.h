#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include"GameBoard.h"
class TicTacToe
{
	bool isValidPlayerSymbol(char );
	void initPlayers(char& player1Symbol, char& player2Symbol);
public:
	void playGame();
};

#endif // !TIC_TAC_TOE_H
