#ifndef GameManager_h
#define GameManager_h

#include "GameConfig.h"
#include "GamePuzzle.h"

#define BONUS_MAX (10)

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
	int miGameState;
	int miScore;
	int miTime;
	int miTimeGauge;
	int miX;
	int miY;
	GamePuzzle* mpPuzzle;
	bool mbSelected;

	bool removePuzzle();
	void downPuzzle();
	void createNewPuzzle();
	void printPuzzle();

public:
    GameManager();
    ~GameManager();

	void initVariable();
	void createPuzzle();
	void updateScore();
	void checkComboAndUpdateTimer();
	void moveCursor(int _moveX, int _moveY);
	void selectedCursor();
	int  getIndex(int _iX, int _iY);
	void printTimer();
	int  getTime();
	void setGameStateGameOver();
	bool isGameStateGameOver();
};

#endif // GameManager_h
