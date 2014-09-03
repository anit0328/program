#ifndef GameManager_h
#define GameManager_h

#include "GameConfig.h"
#include "GameDisplay.h"
#include "GamePuzzleManager.h"

enum GameState{
	eGameStateNoSet = 0,
	eGameStateStandby,
	eGameStateRemove,
	eGameStateMove,
	eGameStateGameOver,
	eGameStateCount
};

class GameManager{
	int miX;
	int miY;
	int miScore;
	int miTime;
	int miTimeGauge;
	GameState meGameState;
	GameDisplay mGameDisplay;
	GamePuzzleManager mGamePuzzleManager;
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
