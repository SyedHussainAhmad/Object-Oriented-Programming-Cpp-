#ifndef GOMOKU_BOARD_H
#define GOMOKU_BOARD_H


enum PLAYER_TURN
{
	FIRST_PLAYER = 'W',
	SECOND_PLAYER = 'B'
};

enum PLAYER_SYMBOL
{
	FIRST_PLAYER_SYMBOL = 'W',
	SECOND_PLAYER_SYMBOL = 'B'
};

enum GameStatus
{
	FIRST_PLAYER_WIN,
	SECOND_PLAYER_WIN,
	DRAW,
	IN_PROGRESS
};

#define ROWS 19
#define COLS 19

class GomokuBoard
{
	char board[ROWS][COLS];
	GameStatus gameStatus = IN_PROGRESS;
	PLAYER_TURN currentPlayer = FIRST_PLAYER;
	int validMovesCount = 0;
	PLAYER_TURN checkWinner();

public:
	GomokuBoard();
	GameStatus getGameStatus();
	bool isValidPosition(int, int);
	bool isAlreadyMarked(int, int);
	PLAYER_SYMBOL getCurrentPlayerSymbol();
	int getValidMovesCount();
	void displayBoard();
	PLAYER_TURN getCurrentPlayer();
	void swithPlayerTurn();
	int markBoard(int, int);
};

#endif // !GOMOKU_BOARD_H