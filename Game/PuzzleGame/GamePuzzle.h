#ifndef GamePuzzle_h
#define GamePuzzle_h

#include "GameConfig.h"

class GamePuzzle{

public:
	enum{
		kPuzzleTypeInvalid = 0,
		kPuzzleTypeTriangle,
		kPuzzleTypeSquare,
		kPuzzleTypeCircle,
		kPuzzleTypeInvertedTriangle,
		kPuzzleTypeStar,
		kPuzzleTypeCount
	};

	enum{
		kPuzzleStateNoSet = 0,
		kPuzzleStateSelected,
		kPuzzleStateRemove,
		kPuzzleStateMove,
		kPuzzleStateCount
	};

	int miPuzzleType;
	int miPuzzleState;
	int miPuzzleIndex;

    GamePuzzle();
    ~GamePuzzle();

    void printPuzzle();
    void printPuzzleBold();
    void printPuzzleNormal();
    void selectedChangePuzzle();
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
