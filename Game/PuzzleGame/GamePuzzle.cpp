#include "GamePuzzle.h"

GamePuzzle::GamePuzzle()
{
    // 乱数初期化
    srand((unsigned)time(NULL));

	mePuzzleState = ePuzzleStateNoSet;
	miPuzzleIndex = 0;
}

GamePuzzle::~GamePuzzle()
{
}

void GamePuzzle::printPuzzle()
{
	switch(mePuzzleState){
		case ePuzzleStateNoSet:
			GameDisplay::printPuzzleBold(mePuzzleType);
			break;
		case ePuzzleStateSelected:
//			GameDisplay::printPuzzleNormal(mePuzzleType);
			break;
		case ePuzzleStateRemove:
			GameDisplay::printPuzzleNormal(mePuzzleType);
			break;
		case ePuzzleStateMove:
			GameDisplay::printPuzzleDown();
			break;
	}
}

int GamePuzzle::getPuzzleType()
{
	return mePuzzleType;
}

void GamePuzzle::setPuzzleType(const int _iPuzzleType)
{
	mePuzzleType = static_cast<PuzzleType>(_iPuzzleType);;
	mePuzzleState = ePuzzleStateNoSet;
	miPuzzleIndex = 0;
}

void GamePuzzle::setPuzzleTypeRandom()
{
	setPuzzleType(rand() % (ePuzzleTypeCount-1) +1);
}

int GamePuzzle::getPuzzleState()
{
	return mePuzzleState;
}

void GamePuzzle::setPuzzleStateRemove()
{
	mePuzzleState = ePuzzleStateRemove;
}

void GamePuzzle::setPuzzleStateMove()
{
	mePuzzleState = ePuzzleStateMove;
}

bool GamePuzzle::isPuzzleStateNoSet()
{
	if(mePuzzleState == ePuzzleStateNoSet){
		return true;
	}
	return false;
}

bool GamePuzzle::isPuzzleStateRemove()
{
	if(mePuzzleState == ePuzzleStateRemove){
		return true;
	}
	return false;
}

bool GamePuzzle::isPuzzleStateMove()
{
	if(mePuzzleState == ePuzzleStateMove){
		return true;
	}
	return false;
}

void GamePuzzle::setPuzzleIndex(const int _iPuzzleIndex)
{
	miPuzzleIndex = _iPuzzleIndex;
}

int GamePuzzle::getPuzzleIndex()
{
	return miPuzzleIndex;
}
