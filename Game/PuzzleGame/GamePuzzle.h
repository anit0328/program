#ifndef GamePuzzle_h
#define GamePuzzle_h

#include "GameConfig.h"
#include "GameDisplay.h"

enum PuzzleState {
	ePuzzleStateNoSet = 0,
	ePuzzleStateSelected,
	ePuzzleStateRemove,
	ePuzzleStateMove,
	ePuzzleStateCount
};

class GamePuzzle{
	PuzzleType mePuzzleType;
	PuzzleState mePuzzleState;
	int miPuzzleIndex;

public:
    GamePuzzle();
    ~GamePuzzle();

    void printPuzzle();
    int getPuzzleType();
    void setPuzzleType(const int _iPuzzleType);
    void setPuzzleTypeRandom();
    int getPuzzleState();
    void setPuzzleStateRemove();
    void setPuzzleStateMove();
    bool isPuzzleStateNoSet();
    bool isPuzzleStateRemove();
    bool isPuzzleStateMove();
    void setPuzzleIndex(const int _iPuzzleIndex);
    int getPuzzleIndex();
};

#endif // GamePuzzle_h
