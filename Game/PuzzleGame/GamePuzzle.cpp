#include "GamePuzzle.h"

GamePuzzle::GamePuzzle()
{
}

GamePuzzle::~GamePuzzle()
{
}

void GamePuzzle::printPuzzle()
{
	switch(miPuzzleState){
		case kPuzzleStateNoSet:
			GameDisplay::printPuzzleBold(miPuzzleType);
			break;
		case kPuzzleStateSelected:
//			GameDisplay::printPuzzleNormal(miPuzzleType);
			break;
		case kPuzzleStateRemove:
			GameDisplay::printPuzzleNormal(miPuzzleType);
			break;
		case kPuzzleStateMove:
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
	miPuzzleState = kPuzzleStateNoSet;
}

void GamePuzzle::setPuzzleTypeRandom()
{
	miPuzzleType = rand() % (GameDisplay::kPuzzleTypeCount-1) +1;
	miPuzzleState = kPuzzleStateNoSet;
	miPuzzleIndex = 0;
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
	miPuzzleState = kPuzzleStateRemove;
}

void GamePuzzle::setPuzzleStateMove()
{
	miPuzzleState = kPuzzleStateMove;
}

bool GamePuzzle::isPuzzleStateNoSet()
{
	if(miPuzzleState == kPuzzleStateNoSet){
		return true;
	}
	return false;
}

bool GamePuzzle::isPuzzleStateRemove()
{
	if(miPuzzleState == kPuzzleStateRemove){
		return true;
	}
	return false;
}

bool GamePuzzle::isPuzzleStateMove()
{
	if(miPuzzleState == kPuzzleStateMove){
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
