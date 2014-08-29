#ifndef GamePuzzleManager_h
#define GamePuzzleManager_h

#include "GameConfig.h"
#include "GamePuzzle.h"

#define BONUS_MAX (10)

class GamePuzzleManager{

private:
	GamePuzzle* mpPuzzle;

public:
    GamePuzzleManager();
    ~GamePuzzleManager();

	void createPuzzle();
	int  changePuzzle(int _iBeforeIndex, int _iAfterIndex);
	int  removePuzzle();
	void downPuzzle();
	void printPuzzle(int);
	void createNewPuzzle();
};

#endif // GamePuzzleManager_h
