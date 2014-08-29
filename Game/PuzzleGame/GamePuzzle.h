#ifndef GamePuzzle_h
#define GamePuzzle_h

#include "GameConfig.h"
#include "GameDisplay.h"

class GamePuzzle{

private:
enum ePuzzleState {
	eNoSet = 0,
	eSelected,
	eRemove,
	eMove,
	ePuzzleStateCount
};

	int miPuzzleType;
	int miPuzzleState;
	int miPuzzleIndex;
	GameDisplay* mpDisplay;

public:
    GamePuzzle();
    ~GamePuzzle();

    void printPuzzle();
    int getPuzzleType();
    void setPuzzleType(int _iPuzzleType);
    void setPuzzleTypeRandom();
    int getPuzzleState();
    void setPuzzleState(int _iPuzzleState);
    void setPuzzleStateRemove();
    void setPuzzleStateMove();
    bool isPuzzleStateNoSet();
    bool isPuzzleStateRemove();
    bool isPuzzleStateMove();
    void setPuzzleIndex(int _iPuzzleIndex);
    int getPuzzleIndex();
};

#endif // GamePuzzle_h
