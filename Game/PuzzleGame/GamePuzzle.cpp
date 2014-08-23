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
			printPuzzleBold();
			break;
		case kPuzzleStateSelected:
//			printPuzzleNormal();
			break;
		case kPuzzleStateRemove:
			printPuzzleNormal();
			break;
		case kPuzzleStateMove:
			FtColorCyan("↓");
			break;
	}
}

void GamePuzzle::printPuzzleBold()
{
	switch(miPuzzleType){
		case kPuzzleTypeTriangle:
			FtColorRed("▲");
			break;
		case kPuzzleTypeSquare:
			FtColorBlue("■");
			break;
		case kPuzzleTypeCircle:
			FtColorGreen("●");
			break;
		case kPuzzleTypeInvertedTriangle:
			FtColorCyan("▼");
			break;
		case kPuzzleTypeStar:
			FtColorYellow("★");
			break;
	}
}

void GamePuzzle::printPuzzleNormal()
{
	switch(miPuzzleType){
		case kPuzzleTypeTriangle:
			FtColorRed("△");
			break;
		case kPuzzleTypeSquare:
			FtColorBlue("□");
			break;
		case kPuzzleTypeCircle:
			FtColorGreen("○");
			break;
		case kPuzzleTypeInvertedTriangle:
			FtColorCyan("▽");
			break;
		case kPuzzleTypeStar:
			FtColorYellow("☆");
			break;
	}
}

void GamePuzzle::selectedChangePuzzle()
{
	if(miPuzzleState == kPuzzleStateNoSet){
		miPuzzleState = kPuzzleStateSelected;
	}else{
		miPuzzleState = kPuzzleStateNoSet;
	}
	printPuzzle();
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
	miPuzzleType = rand() % (GamePuzzle::kPuzzleTypeCount-1) +1;
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
