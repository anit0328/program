#include "GameManager.h"

int iBonus[] = {0, 0, 250, 400, 600, 900, 1500, 3000, 6000, 9999};

GameManager::GameManager()
{
	mpPuzzle = new GamePuzzle[FRAME_WIDTH * FRAME_HEIGHT]();
	initVariable();
}

GameManager::~GameManager()
{
	delete[] mpPuzzle;
}

void GameManager::initVariable()
{
	miScore = SCORE_INIT_VAL;
	miTime = TIMER_INIT_VAL;
	miTimeGauge = TIMER_INIT_VAL;
	miX = GAME_START_INIT_X;
	miY = GAME_START_INIT_Y;
}

void GameManager::createPuzzle()
{
	for(int i = 0; i< FRAME_WIDTH; i++){
		for(int j = 0; j< FRAME_HEIGHT; j++){
			mpPuzzle[j * FRAME_WIDTH + i].setPuzzleTypeRandom();
		}
	}

	miGameState = kGameStateStandby;

	while(true){
		if(!removePuzzle()){
			break;
		}
		downPuzzle();
		createNewPuzzle();
	}
	printPuzzle();

	miGameState = kGameStateNoSet;
}

bool GameManager::removePuzzle()
{
	int pzIndex = 0;
	int pzRemovCnt[FRAME_WIDTH * FRAME_HEIGHT];

	for(int j = 0; j < FRAME_HEIGHT; j++){
		for(int i = 0; i < FRAME_WIDTH; i++){
			int index = j * FRAME_WIDTH + i;

			pzIndex++;
			pzRemovCnt[pzIndex] = 0;

			// 削除パズル数算出用のIndex設定
			int nowPzIndex = pzIndex;
			int tempPzIndex = mpPuzzle[index].getPuzzleIndex();
			if(tempPzIndex != 0){
				nowPzIndex = tempPzIndex;
			}

			// 右に検索
			int xHit = 0;
			for(int k = i + 1; k < FRAME_WIDTH; k++){
				int searchIndex = j * FRAME_WIDTH + k;
				if(mpPuzzle[index].getPuzzleType() == mpPuzzle[searchIndex].getPuzzleType()){

					// 削除パズル数算出用のIndex検索
					int tempPzIndex = mpPuzzle[searchIndex].getPuzzleIndex();
					if(tempPzIndex != 0){
						nowPzIndex = tempPzIndex;
					}
					xHit++;
				}
				else{
					break;
				}
			}

			for(int k = i; k <= i + xHit; k++){
				int searchIndex = j * FRAME_WIDTH + k;
				if(!mpPuzzle[searchIndex].isPuzzleStateRemove()){
					if(xHit >= 2){
						mpPuzzle[searchIndex].setPuzzleStateRemove();
						pzRemovCnt[nowPzIndex]++;
					}
					mpPuzzle[searchIndex].setPuzzleIndex(nowPzIndex);
				}
			}

			// 下に検索
			int yHit = 0;
			for(int k = j + 1; k < FRAME_HEIGHT; k++){
				int searchIndex = k * FRAME_WIDTH + i;
				if(mpPuzzle[index].getPuzzleType() == mpPuzzle[searchIndex].getPuzzleType()){
					yHit++;
				}
				else{
					break;
				}
			}

			for(int k = j; k <= j + yHit; k++){
				int searchIndex = k * FRAME_WIDTH + i;
				if(!mpPuzzle[searchIndex].isPuzzleStateRemove()){
					if(yHit >= 2){
						mpPuzzle[searchIndex].setPuzzleStateRemove();
						pzRemovCnt[nowPzIndex]++;
					}
				}
				mpPuzzle[searchIndex].setPuzzleIndex(nowPzIndex);
			}
		}
	}

	// スコア計算
	bool isHit = false;
	for(int i = 1; i < FRAME_WIDTH * FRAME_HEIGHT; i++){
		int removeCnt = pzRemovCnt[i];
		if(removeCnt > 0){
			if(miGameState != kGameStateStandby){
				if(removeCnt > BONUS_MAX){
					removeCnt = BONUS_MAX;
				}
				miScore += iBonus[removeCnt-1];
				miGameState = kGameStateRemove;
			}
			isHit = true;
		}
	}

	return isHit;
}

void GameManager::downPuzzle()
{
	for(int j = FRAME_HEIGHT -1; j >= 0; j--){
		for(int i = FRAME_WIDTH -1; i >= 0; i--){

			if(!mpPuzzle[j * FRAME_WIDTH + i].isPuzzleStateRemove() && 
				!mpPuzzle[j * FRAME_WIDTH + i].isPuzzleStateMove()){
				continue;
			}

			// 上に検索
			bool isHit = false;
			for(int k = j; k >= 0; k--){
				if(mpPuzzle[k * FRAME_WIDTH + i].isPuzzleStateNoSet()){
					mpPuzzle[j * FRAME_WIDTH + i] = mpPuzzle[k * FRAME_HEIGHT + i];
					mpPuzzle[k * FRAME_WIDTH + i].setPuzzleStateMove();
					isHit = true;
					break;
				}
			}
			if(!isHit){
				mpPuzzle[j * FRAME_WIDTH + i].setPuzzleStateMove();
			}
		}
	}
}

void GameManager::createNewPuzzle()
{
	for(int j = FRAME_HEIGHT -1; j >= 0; j--){
		for(int i = FRAME_WIDTH -1; i >= 0; i--){
			if(!mpPuzzle[j * FRAME_WIDTH + i].isPuzzleStateRemove() && 
				!mpPuzzle[j * FRAME_WIDTH + i].isPuzzleStateMove()){
				continue;
			}

			// 新しいパズル作成
			mpPuzzle[j * FRAME_WIDTH + i].setPuzzleTypeRandom();
		}
	}
}

void GameManager::printPuzzle()
{
	for(int i = 0; i< FRAME_WIDTH; i++){
		for(int j = 0; j< FRAME_HEIGHT; j++){
			Location(PUZZLE_AREA_INIT_X + i * 2, PUZZLE_AREA_INIT_Y + j);
			mpPuzzle[j * FRAME_WIDTH + i].printPuzzle();
		}
	}
}

void GameManager::checkComboAndUpdateTimer()
{
	if(miGameState == kGameStateRemove){
//		Clear();
		downPuzzle();
		printPuzzle();
		Location(miX, miY);
		miGameState = kGameStateMove;
	}
	else if(miGameState == kGameStateMove){
//		Clear();
		createNewPuzzle();
		printPuzzle();
		Location(miX, miY);

		if(removePuzzle()){
			printPuzzle();
			Location(miX, miY);
			miGameState = kGameStateRemove;
		}else{
			miGameState = kGameStateNoSet;
		}

		// スコア表示
		PrintScore(miScore);
	}

	printTimer();
}

void GameManager::moveCursor(int _moveX, int _moveY)
{
	int backX = miX, backY = miY;
	int index = getIndex(miX, miY);

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

		// パズルを入れ替える
		GamePuzzle puzzle = mpPuzzle[index];
		mpPuzzle[index] = mpPuzzle[afterIndex];
		Location(backX, backY);
		mpPuzzle[index].printPuzzle();

		mpPuzzle[afterIndex] = puzzle;
		Location(miX, miY);
//		mpPuzzle[afterIndex].selectedChangePuzzle();
		mpPuzzle[afterIndex].printPuzzle();
		mbSelected = false;

		if(!removePuzzle()){
			Beep();

			// パズルを元に戻す
			GamePuzzle puzzle = mpPuzzle[index];
			mpPuzzle[index] = mpPuzzle[afterIndex];
			Location(backX, backY);
			mpPuzzle[index].printPuzzle();

			mpPuzzle[afterIndex] = puzzle;
			Location(miX, miY);
			mpPuzzle[afterIndex].printPuzzle();
		}

//		DebugPrintBool(mbSelected);
		Location(miX, miY);
	}
}

void GameManager::selectedCursor()
{
	int index = getIndex(miX, miY);
//	mpPuzzle[index].selectedChangePuzzle();
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

void GameManager::printTimer()
{
	miTime++;
	UpdateTimer(miTime);

	if(miTime == 1 || miTime % 5 == 0){
		UpdateTimerGauge(miTimeGauge++);
	}
	Location(miX, miY);
}

int GameManager::getTime()
{
	return miTime;
}

void GameManager::setGameStateGameOver()
{
	miGameState = kGameStateGameOver;
}

bool GameManager::isGameStateGameOver()
{
	return miGameState == kGameStateGameOver ? true : false;
}
