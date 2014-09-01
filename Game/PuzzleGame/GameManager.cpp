#include "GameManager.h"

GameManager::GameManager()
{
	// 初期値設定
	miX = GAME_START_INIT_X;
	miY = GAME_START_INIT_Y;
	miScore = SCORE_INIT_VAL;
	miTime = TIMER_INIT_VAL;
	miTimeGauge = TIMER_INIT_VAL;
	miGameState = eNoSet;

	// ゲーム画面表示
	GameDisplay gameDisplay;

	// ゲームパズル作成
	GamePuzzleManager gamePuzzleManager;

	// パズル表示
	printPuzzle();

	// 初期位置に移動
	gameDisplay.moveLocation(GAME_START_INIT_X, GAME_START_INIT_Y);
}

GameManager::~GameManager()
{
}

void GameManager::moveCursor(const int _moveX, const int _moveY)
{
	int beforeIndex = getIndex();

	if(FRAME_INIT_X*2 >= miX + _moveX || miX + _moveX > FRAME_INIT_X*2 + FRAME_WIDTH*2){
		gameDisplay.alertBeep();
		return;
	}else{
		miX += _moveX;
	}
	if(FRAME_INIT_Y >= miY + _moveY|| miY + _moveY > FRAME_INIT_Y + FRAME_HEIGHT){
		gameDisplay.alertBeep();
		return;
	}else{
		miY += _moveY;
	}

	int afterIndex = getIndex();
	gameDisplay.moveLocation(miX, miY);

	// パズルが選択中か？
	if(mbSelected == true){
		mbSelected = false;

		// パズルを入れ替える
		int removePoint = gamePuzzleManager.changePuzzle(beforeIndex, afterIndex);
		if(removePoint > 0){
			miGameState = eRemove;
			printPuzzle();
			addScore(removePoint);
		}else{
			gameDisplay.alertBeep();
		}
		gameDisplay.moveLocation(miX, miY);
	}
}

void GameManager::selectedCursor()
{
	int index = getIndex();
	if(mbSelected == false){
		mbSelected = true;
	}else{
		mbSelected = false;
	}
	gameDisplay.moveLocation(miX, miY);
}

int GameManager::getIndex()
{
	int width = (miX - PUZZLE_AREA_INIT_X) / 2;
	int index = (miY - PUZZLE_AREA_INIT_Y)  * FRAME_WIDTH + width;
	return index;
}

void GameManager::printPuzzle()
{
	for(int i = 0; i< FRAME_WIDTH; i++){
		for(int j = 0; j< FRAME_HEIGHT; j++){
			gameDisplay.moveLocation(PUZZLE_AREA_INIT_X + i * 2, PUZZLE_AREA_INIT_Y + j);
			gamePuzzleManager.printPuzzle(j * FRAME_WIDTH + i);
		}
	}
}

void GameManager::checkComboAndUpdateTimer()
{
	if(miGameState == eRemove){
		gamePuzzleManager.downPuzzle();
		printPuzzle();
		gameDisplay.moveLocation(miX, miY);
		miGameState = eMove;
	}
	else if(miGameState == eMove){
		gamePuzzleManager.createNewPuzzle();
		printPuzzle();
		gameDisplay.moveLocation(miX, miY);

		int removePoint = gamePuzzleManager.removePuzzle();
		if(removePoint > 0){
			addScore(removePoint);
			printPuzzle();
			gameDisplay.moveLocation(miX, miY);
			miGameState = eRemove;
		}else{
			miGameState = eNoSet;
		}

		// スコア表示
		gameDisplay.printScore(miScore);
	}

	updateTimer();
	gameDisplay.moveLocation(miX, miY);
}

void GameManager::addScore(const int _iScore)
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
	gameDisplay.printTimer(miTime);

	if(miTime == 1 || miTime % 5 == 0){
		gameDisplay.printTimerGauge(miTimeGauge++);
	}
}

bool GameManager::isGameOver()
{
	return getTime() >= TIMER_VAL_MAX ? true : false;
}

void GameManager::setGameStateGameOver()
{
	miGameState = eGameOver;
	gameDisplay.printGameOver();
}

bool GameManager::isGameStateGameOver()
{
	return miGameState == eGameOver ? true : false;
}
