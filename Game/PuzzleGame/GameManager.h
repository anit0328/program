#ifndef GameManager_h
#define GameManager_h

#include "GameConfig.h"
#include "GamePuzzle.h"

#define BONUS_MAX (10)

class GameManager{

public:
	enum{
		kGameStateNoSet = 0,
		kGameStateStandby,
		kGameStateRemove,
		kGameStateMove,
		kGameStateGameOver,
		kGameStateCount
	};

	int miGameState;
	int miScore;
	int miTime;
	int miTimeGauge;
	int miX;
	int miY;
	GamePuzzle* mpPuzzle;
	bool mbSelected;

    GameManager();
    ~GameManager();

	void initVariable();
	void createPuzzle();
	bool removePuzzle();
	void downPuzzle();
	void createNewPuzzle();
	void printPuzzle();
	void updateScore();
	void checkComboAndUpdateTimer();
	void moveCursor(int _moveX, int _moveY);
	void selectedCursor();
	int getIndex(int _iX, int _iY);
	void printTimer();
};

#endif // GameManager_h
