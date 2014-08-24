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
	int  changePuzzle(int, int);
	int  removePuzzle();
	void downPuzzle();
	void createNewPuzzle();
	void printPuzzle();
	void moveLocation(int);
};

#endif // GamePuzzleManager_h
