#ifndef GameManager_h
#define GameManager_h

#include "GameConfig.h"
#include "GameDisplay.h"
#include "GamePuzzleManager.h"

class GameManager{

enum{
	kGameStateNoSet = 0,
	kGameStateStandby,
	kGameStateRemove,
	kGameStateMove,
	kGameStateGameOver,
	kGameStateCount
};

private:
	int miX;
	int miY;
	int miScore;
	int miTime;
	int miTimeGauge;
	int miGameState;
	GameDisplay* mpDisplay;
	GamePuzzleManager* mpPuzzleManager;
	bool mbSelected;

public:
    GameManager();
    ~GameManager();

	void createGameWindow();
	void moveCursor(int, int);
	void selectedCursor();
	int  getIndex(int, int);
	void printPuzzle();
	void checkComboAndUpdateTimer();
	void addScore(int);
	int  getTime();
	void updateTimer();
	bool isGameOver();
	void setGameStateGameOver();
	bool isGameStateGameOver();
};

#endif // GameManager_h
