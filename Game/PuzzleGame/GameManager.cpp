#include "GameManager.h"

GameManager::GameManager()
{
	mpScore = new GameScore();
	mpFever = new GameFever();
	mpTimeGauge = new GameTimeGauge();
	mpPuzzleManager = new GamePuzzleManager();
	miX = GAME_START_INIT_X;
	miY = GAME_START_INIT_Y;
	miGameState = kGameStateNoSet;
}

GameManager::~GameManager()
{
	delete mpScore;
	delete mpFever;
	delete mpTimeGauge;
	delete mpPuzzleManager;
}

void GameManager::createGameWindow()
{
	// スコア表示
	mpScore->printScore();

	// FEVER表示
	mpFever->printFever();

	// 枠作成
	GameFrame::printFrame();

	// パズル作成
	mpPuzzleManager->createPuzzle();

	// タイマーゲージ表示
	mpTimeGauge->printInitTimer();
}

void GameManager::moveCursor(int _moveX, int _moveY)
{
	int beforeIndex = getIndex(miX, miY);

	if(FRAME_INIT_X*2 >= miX + _moveX || miX + _moveX > FRAME_INIT_X*2 + FRAME_WIDTH*2){
		Beep();
		return;
	}else{
		miX += _moveX;
	}
	if(FRAME_INIT_Y >= miY + _moveY|| miY + _moveY > FRAME_INIT_Y + FRAME_HEIGHT){
		Beep();
		return;
	}else{
		miY += _moveY;
	}

	int afterIndex = getIndex(miX, miY);
//	DebugPrintXY(miX, miY);
	Location(miX, miY);

	// パズルが選択中か？
	if(mbSelected == true){
		mbSelected = false;

		// パズルを入れ替える
		int removePoint = mpPuzzleManager->changePuzzle(beforeIndex, afterIndex);
		if(removePoint > 0){
			miGameState = kGameStateRemove;
			mpScore->addScore(removePoint);
		}

//		DebugPrintBool(mbSelected);
		Location(miX, miY);
	}
}

void GameManager::selectedCursor()
{
	int index = getIndex(miX, miY);
	if(mbSelected == false){
		mbSelected = true;
	}else{
		mbSelected = false;
	}
//	DebugPrintBool(mbSelected);
	Location(miX, miY);
}

int GameManager::getIndex(int _iX, int _iY)
{
	int width = (_iX - PUZZLE_AREA_INIT_X) / 2;
	int index = (_iY - PUZZLE_AREA_INIT_Y)  * FRAME_WIDTH + width;
//	DebugPrintIndex(index);
//	Location(miX, miY);
	return index;
}

void GameManager::checkComboAndUpdateTimer()
{
	if(miGameState == kGameStateRemove){
//		Clear();
		mpPuzzleManager->downPuzzle();
		mpPuzzleManager->printPuzzle();
		Location(miX, miY);
		miGameState = kGameStateMove;
	}
	else if(miGameState == kGameStateMove){
//		Clear();
		mpPuzzleManager->createNewPuzzle();
		mpPuzzleManager->printPuzzle();
		Location(miX, miY);

		int removePoint = mpPuzzleManager->removePuzzle();
		if(removePoint > 0){
			mpScore->addScore(removePoint);
			mpPuzzleManager->printPuzzle();
			Location(miX, miY);
			miGameState = kGameStateRemove;
		}else{
			miGameState = kGameStateNoSet;
		}

		// スコア表示
		mpScore->printScore();
	}

	mpTimeGauge->updateTimer();
	Location(miX, miY);
}

bool GameManager::isGameOver()
{
	return mpTimeGauge->getTime() >= TIMER_VAL_MAX ? true : false;
}

void GameManager::setGameStateGameOver()
{
	miGameState = kGameStateGameOver;
}

bool GameManager::isGameStateGameOver()
{
	return miGameState == kGameStateGameOver ? true : false;
}
