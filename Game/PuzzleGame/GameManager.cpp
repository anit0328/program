#include "GameManager.h"

GameManager::GameManager()
{
	mpDisplay = new GameDisplay();
	mpPuzzleManager = new GamePuzzleManager();
	miX = GAME_START_INIT_X;
	miY = GAME_START_INIT_Y;
	miScore = SCORE_INIT_VAL;
	miTime = TIMER_INIT_VAL;
	miTimeGauge = TIMER_INIT_VAL;
	miGameState = kGameStateNoSet;
}

GameManager::~GameManager()
{
	delete mpDisplay;
	delete mpPuzzleManager;
	mpDisplay->moveLocation(1, 15);
}

void GameManager::createGameWindow()
{
	// 画面クリア
	mpDisplay->clearDisplay();

	// スコア表示
	mpDisplay->printScore(miScore);

	// FEVER表示
	mpDisplay->printFever();

	// 枠作成
	mpDisplay->printFrame();

	// パズル作成
	mpPuzzleManager->createPuzzle();

	// パズル表示
	printPuzzle();

	// タイマーゲージ表示
	mpDisplay->printTimer(miTime);

	// 初期位置に移動
	mpDisplay->moveLocation(GAME_START_INIT_X, GAME_START_INIT_Y);
}

void GameManager::moveCursor(int _moveX, int _moveY)
{
	int beforeIndex = getIndex(miX, miY);

	if(FRAME_INIT_X*2 >= miX + _moveX || miX + _moveX > FRAME_INIT_X*2 + FRAME_WIDTH*2){
		mpDisplay->alertBeep();
		return;
	}else{
		miX += _moveX;
	}
	if(FRAME_INIT_Y >= miY + _moveY|| miY + _moveY > FRAME_INIT_Y + FRAME_HEIGHT){
		mpDisplay->alertBeep();
		return;
	}else{
		miY += _moveY;
	}

	int afterIndex = getIndex(miX, miY);
	mpDisplay->moveLocation(miX, miY);

	// パズルが選択中か？
	if(mbSelected == true){
		mbSelected = false;

		// パズルを入れ替える
		int removePoint = mpPuzzleManager->changePuzzle(beforeIndex, afterIndex);
		if(removePoint > 0){
			miGameState = kGameStateRemove;
			printPuzzle();
			addScore(removePoint);
		}else{
			mpDisplay->alertBeep();
		}
		mpDisplay->moveLocation(miX, miY);
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
	mpDisplay->moveLocation(miX, miY);
}

int GameManager::getIndex(int _iX, int _iY)
{
	int width = (_iX - PUZZLE_AREA_INIT_X) / 2;
	int index = (_iY - PUZZLE_AREA_INIT_Y)  * FRAME_WIDTH + width;
	return index;
}

void GameManager::printPuzzle()
{
	for(int i = 0; i< FRAME_WIDTH; i++){
		for(int j = 0; j< FRAME_HEIGHT; j++){
			mpDisplay->moveLocation(PUZZLE_AREA_INIT_X + i * 2, PUZZLE_AREA_INIT_Y + j);
			mpPuzzleManager->printPuzzle(j * FRAME_WIDTH + i);
		}
	}
}

void GameManager::checkComboAndUpdateTimer()
{
	if(miGameState == kGameStateRemove){
		mpPuzzleManager->downPuzzle();
		printPuzzle();
		mpDisplay->moveLocation(miX, miY);
		miGameState = kGameStateMove;
	}
	else if(miGameState == kGameStateMove){
		mpPuzzleManager->createNewPuzzle();
		printPuzzle();
		mpDisplay->moveLocation(miX, miY);

		int removePoint = mpPuzzleManager->removePuzzle();
		if(removePoint > 0){
			addScore(removePoint);
			printPuzzle();
			mpDisplay->moveLocation(miX, miY);
			miGameState = kGameStateRemove;
		}else{
			miGameState = kGameStateNoSet;
		}

		// スコア表示
		mpDisplay->printScore(miScore);
	}

	updateTimer();
	mpDisplay->moveLocation(miX, miY);
}

void GameManager::addScore(int _iScore)
{
	miScore += _iScore;
}

int GameManager::getTime()
{
	return miTime;
}

void GameManager::updateTimer()
{
	miTime++;
	mpDisplay->printTimer(miTime);

	if(miTime == 1 || miTime % 5 == 0){
		mpDisplay->printTimerGauge(miTimeGauge++);
	}
}

bool GameManager::isGameOver()
{
	return getTime() >= TIMER_VAL_MAX ? true : false;
}

void GameManager::setGameStateGameOver()
{
	miGameState = kGameStateGameOver;
	mpDisplay->printGameOver();
}

bool GameManager::isGameStateGameOver()
{
	return miGameState == kGameStateGameOver ? true : false;
}
