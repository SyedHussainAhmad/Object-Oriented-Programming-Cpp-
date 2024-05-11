#ifndef GAME_BOARD_H
#define GAME_BOARD_H

enum PlayerTurn { FIRST_PLAYER = 1, SECOND_PLAYER = 2 };
enum GameStatus { DRAW, WIN, IN_PROGRESS };

class GameBoard
{
private:
	char data[3][3];
	GameStatus gameStatus = IN_PROGRESS;
	int validMovesCount;
public:
	GameBoard();
	void displayBoard();
	void markBoard(char pos, char playerSymbol);
	bool isValidPosition(char pos);
	bool isAlreadyMarked(char pos);
	int getValidMovesCount();
	bool checkWinningStatus();
	GameStatus getGameStatus();
};
#endif // !GAME_BOARD_H
