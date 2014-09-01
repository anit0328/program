#include "GamePuzzle.h"

GamePuzzle::GamePuzzle()
{
    // 乱数初期化
    srand((unsigned)time(NULL));

	miPuzzleState = eNoSet;
	miPuzzleIndex = 0;
}

GamePuzzle::~GamePuzzle()
{
}

void GamePuzzle::printPuzzle()
{
	ePuzzleState pzs = static_cast<ePuzzleState>(miPuzzleState);
	switch(pzs){
		case eNoSet:
			GameDisplay::printPuzzleBold(miPuzzleType);
			break;
		case eSelected:
//			GameDisplay::printPuzzleNormal(miPuzzleType);
			break;
		case eRemove:
			GameDisplay::printPuzzleNormal(miPuzzleType);
			break;
		case eMove:
			GameDisplay::printPuzzleDown();
			break;
	}
}

int GamePuzzle::getPuzzleType()
{
	return miPuzzleType;
}

void GamePuzzle::setPuzzleType(int _iPuzzleType)
{
	miPuzzleType = _iPuzzleType;
	miPuzzleState = eNoSet;
	miPuzzleIndex = 0;
}

void GamePuzzle::setPuzzleTypeRandom()
{
	setPuzzleType(rand() % (GameDisplay::ePuzzleTypeCount-1) +1);
}

int GamePuzzle::getPuzzleState()
{
	return miPuzzleState;
}

void GamePuzzle::setPuzzleState(int _iPuzzleState)
{
	miPuzzleState = _iPuzzleState;
}

void GamePuzzle::setPuzzleStateRemove()
{
	miPuzzleState = eRemove;
}

void GamePuzzle::setPuzzleStateMove()
{
	miPuzzleState = eMove;
}

bool GamePuzzle::isPuzzleStateNoSet()
{
	if(miPuzzleState == eNoSet){
		return true;
	}
	return false;
}

bool GamePuzzle::isPuzzleStateRemove()
{
	if(miPuzzleState == eRemove){
		return true;
	}
	return false;
}

bool GamePuzzle::isPuzzleStateMove()
{
	if(miPuzzleState == eMove){
		return true;
	}
	return false;
}

void GamePuzzle::setPuzzleIndex(int _iPuzzleIndex)
{
	miPuzzleIndex = _iPuzzleIndex;
}

int GamePuzzle::getPuzzleIndex()
{
	return miPuzzleIndex;
}
