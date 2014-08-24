#include "GamePuzzleManager.h"

int iBonus[] = {0, 0, 250, 400, 600, 900, 1500, 3000, 6000, 9999};

GamePuzzleManager::GamePuzzleManager()
{
	mpPuzzle = new GamePuzzle[FRAME_WIDTH * FRAME_HEIGHT]();
}

GamePuzzleManager::~GamePuzzleManager()
{
	delete[] mpPuzzle;
}

void GamePuzzleManager::createPuzzle()
{
	for(int i = 0; i< FRAME_WIDTH; i++){
		for(int j = 0; j< FRAME_HEIGHT; j++){
			mpPuzzle[j * FRAME_WIDTH + i].setPuzzleTypeRandom();
		}
	}

	while(true){
		if(removePuzzle() < 1){
			break;
		}
		downPuzzle();
		createNewPuzzle();
	}
	printPuzzle();
}

int GamePuzzleManager::changePuzzle(int _iBeforeIndex, int _iAfterIndex)
{
	// パズルを入れ替える
	GamePuzzle puzzle = mpPuzzle[_iBeforeIndex];
	mpPuzzle[_iBeforeIndex] = mpPuzzle[_iAfterIndex];
	moveLocation(_iBeforeIndex);
	mpPuzzle[_iBeforeIndex].printPuzzle();

	mpPuzzle[_iAfterIndex] = puzzle;
	moveLocation(_iAfterIndex);
//	mpPuzzle[_iAfterIndex].selectedChangePuzzle();
	mpPuzzle[_iAfterIndex].printPuzzle();

	int removePoint = removePuzzle();
	if(removePoint < 1){
		Beep();

		// パズルを元に戻す
		GamePuzzle puzzle = mpPuzzle[_iBeforeIndex];
		mpPuzzle[_iBeforeIndex] = mpPuzzle[_iAfterIndex];
		moveLocation(_iBeforeIndex);
		mpPuzzle[_iBeforeIndex].printPuzzle();

		mpPuzzle[_iAfterIndex] = puzzle;
		moveLocation(_iAfterIndex);
		mpPuzzle[_iAfterIndex].printPuzzle();
	}
	return removePoint;
}

int GamePuzzleManager::removePuzzle()
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
	int removePoint = 0;

	for(int i = 1; i < FRAME_WIDTH * FRAME_HEIGHT; i++){
		if(pzRemovCnt[i] > 0){
			int removeCnt = pzRemovCnt[i];
			if(removeCnt > BONUS_MAX){
				removeCnt = BONUS_MAX;
			}
			removePoint += iBonus[removeCnt-1];
		}
	}

	return removePoint;
}

void GamePuzzleManager::downPuzzle()
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

void GamePuzzleManager::createNewPuzzle()
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

void GamePuzzleManager::printPuzzle()
{
	for(int i = 0; i< FRAME_WIDTH; i++){
		for(int j = 0; j< FRAME_HEIGHT; j++){
			Location(PUZZLE_AREA_INIT_X + i * 2, PUZZLE_AREA_INIT_Y + j);
			mpPuzzle[j * FRAME_WIDTH + i].printPuzzle();
		}
	}
}

void GamePuzzleManager::moveLocation(int _iIndex)
{
	int x = PUZZLE_AREA_INIT_X, y = PUZZLE_AREA_INIT_Y;
	x += _iIndex % FRAME_WIDTH * 2;
	y += _iIndex / FRAME_WIDTH;
	Location(x, y);
}
