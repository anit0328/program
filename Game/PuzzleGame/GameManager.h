#ifndef GameManager_h
#define GameManager_h

#include "GameConfig.h"
#include "GameDisplay.h"
#include "GamePuzzleManager.h"

class GameManager{

enum eGameState{
	eNoSet = 0,
	eStandby,
	eRemove,
	eMove,
	eGameOver,
	eGameStateCount
};

private:
	int miX;
	int miY;
	int miScore;
	int miTime;
	int miTimeGauge;
	int miGameState;
	GameDisplay gameDisplay;
	GamePuzzleManager gamePuzzleManager;
	bool mbSelected;

public:
    GameManager();
    ~GameManager();

	void moveCursor(const int _moveX, const int _moveY);
	void selectedCursor();
	int  getIndex();
	void printPuzzle();
	void checkComboAndUpdateTimer();
	void addScore(const int _iScore);
	int  getTime();
	void updateTimer();
	bool isGameOver();
	void setGameStateGameOver();
	bool isGameStateGameOver();
};

#endif // GameManager_h
