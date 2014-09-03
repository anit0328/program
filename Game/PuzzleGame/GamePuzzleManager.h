#ifndef GamePuzzleManager_h
#define GamePuzzleManager_h

#include "GameConfig.h"
#include "GamePuzzle.h"

#define BONUS_MAX (10)

class GamePuzzleManager{
	GamePuzzle mGamePuzzle[FRAME_WIDTH * FRAME_HEIGHT];

public:
    GamePuzzleManager();
    ~GamePuzzleManager();

	int  changePuzzle(const int _iBeforeIndex, const int _iAfterIndex);
	int  removePuzzle();
	void downPuzzle();
	void printPuzzle(const int _iIndex);
	void createNewPuzzle();
};

#endif // GamePuzzleManager_h
