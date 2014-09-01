#ifndef GamePuzzleManager_h
#define GamePuzzleManager_h

#include "GameConfig.h"
#include "GamePuzzle.h"

#define BONUS_MAX (10)

class GamePuzzleManager{
	GamePuzzle gamePuzzle[FRAME_WIDTH * FRAME_HEIGHT];

public:
    GamePuzzleManager();
    ~GamePuzzleManager();

	int  changePuzzle(int _iBeforeIndex, int _iAfterIndex);
	int  removePuzzle();
	void downPuzzle();
	void printPuzzle(int);
	void createNewPuzzle();
};

#endif // GamePuzzleManager_h
