#include "GameManager.h"

GameManager::GameManager()
{
	// 初期値設定
	miX = GAME_START_INIT_X;
	miY = GAME_START_INIT_Y;
	miScore = SCORE_INIT_VAL;
	miTime = TIMER_INIT_VAL;
	miTimeGauge = TIMER_INIT_VAL;
	meGameState = eGameStateNoSet;

	// ゲーム画面表示
	GameDisplay mGameDisplay;

	// ゲームパズル作成
	GamePuzzleManager mGamePuzzleManager;

	// パズル表示
	printPuzzle();

	// 初期位置に移動
	mGameDisplay.moveLocation(GAME_START_INIT_X, GAME_START_INIT_Y);
}

GameManager::~GameManager()
{
}

void GameManager::moveCursor(const int _moveX, const int _moveY)
{
	int beforeIndex = getIndex();

	if(FRAME_INIT_X*2 >= miX + _moveX || miX + _moveX > FRAME_INIT_X*2 + FRAME_WIDTH*2){
		mGameDisplay.alertBeep();
		return;
	}else{
		miX += _moveX;
	}
	if(FRAME_INIT_Y >= miY + _moveY|| miY + _moveY > FRAME_INIT_Y + FRAME_HEIGHT){
		mGameDisplay.alertBeep();
		return;
	}else{
		miY += _moveY;
	}

	int afterIndex = getIndex();
	mGameDisplay.moveLocation(miX, miY);

	// パズルが選択中か？
	if(mbSelected == true){
		mbSelected = false;

		// パズルを入れ替える
		int removePoint = mGamePuzzleManager.changePuzzle(beforeIndex, afterIndex);
		if(removePoint > 0){
			meGameState = eGameStateRemove;
			printPuzzle();
			addScore(removePoint);
		}else{
			mGameDisplay.alertBeep();
		}
		mGameDisplay.moveLocation(miX, miY);
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
	mGameDisplay.moveLocation(miX, miY);
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
			mGameDisplay.moveLocation(PUZZLE_AREA_INIT_X + i * 2, PUZZLE_AREA_INIT_Y + j);
			mGamePuzzleManager.printPuzzle(j * FRAME_WIDTH + i);
		}
	}
}

void GameManager::checkComboAndUpdateTimer()
{
	if(meGameState == eGameStateRemove){
		mGamePuzzleManager.downPuzzle();
		printPuzzle();
		mGameDisplay.moveLocation(miX, miY);
		meGameState = eGameStateMove;
	}
	else if(meGameState == eGameStateMove){
		mGamePuzzleManager.createNewPuzzle();
		printPuzzle();
		mGameDisplay.moveLocation(miX, miY);

		int removePoint = mGamePuzzleManager.removePuzzle();
		if(removePoint > 0){
			addScore(removePoint);
			printPuzzle();
			mGameDisplay.moveLocation(miX, miY);
			meGameState = eGameStateRemove;
		}else{
			meGameState = eGameStateNoSet;
		}

		// スコア表示
		mGameDisplay.printScore(miScore);
	}

	updateTimer();
	mGameDisplay.moveLocation(miX, miY);
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
	mGameDisplay.printTimer(miTime);

	if(miTime == 1 || miTime % 5 == 0){
		mGameDisplay.printTimerGauge(miTimeGauge++);
	}
}

bool GameManager::isGameOver()
{
	return getTime() >= TIMER_VAL_MAX ? true : false;
}

void GameManager::setGameStateGameOver()
{
	meGameState = eGameStateGameOver;
	mGameDisplay.printGameOver();
}

bool GameManager::isGameStateGameOver()
{
	return meGameState == eGameStateGameOver ? true : false;
}
