#include "GamePuzzleManager.h"

int iBonus[] = {0, 0, 250, 400, 600, 900, 1500, 3000, 6000, 9999};

GamePuzzleManager::GamePuzzleManager()
{
	for(int i = 0; i< FRAME_WIDTH; i++){
		for(int j = 0; j< FRAME_HEIGHT; j++){
			mGamePuzzle[j * FRAME_WIDTH + i].setPuzzleTypeRandom();
		}
	}

	while(true){
		if(removePuzzle() < 1){
			break;
		}
		downPuzzle();
		createNewPuzzle();
	}
}

GamePuzzleManager::~GamePuzzleManager()
{
}

int GamePuzzleManager::changePuzzle(const int _iBeforeIndex, const int _iAfterIndex)
{
	// パズルを入れ替える
	GamePuzzle gamePuzzle = mGamePuzzle[_iBeforeIndex];
	mGamePuzzle[_iBeforeIndex] = mGamePuzzle[_iAfterIndex];
	mGamePuzzle[_iAfterIndex] = gamePuzzle;

	int removePoint = removePuzzle();
	if(removePoint == 0){
		// パズルを元に戻す
		gamePuzzle = mGamePuzzle[_iBeforeIndex];
		mGamePuzzle[_iBeforeIndex] = mGamePuzzle[_iAfterIndex];
		mGamePuzzle[_iAfterIndex] = gamePuzzle;
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
			int tempPzIndex = mGamePuzzle[index].getPuzzleIndex();
			if(tempPzIndex != 0){
				nowPzIndex = tempPzIndex;
			}

			// 右に検索
			int xHit = 0;
			for(int k = i + 1; k < FRAME_WIDTH; k++){
				int searchIndex = j * FRAME_WIDTH + k;
				if(mGamePuzzle[index].getPuzzleType() == mGamePuzzle[searchIndex].getPuzzleType()){

					// 削除パズル数算出用のIndex検索
					int tempPzIndex = mGamePuzzle[searchIndex].getPuzzleIndex();
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
				if(!mGamePuzzle[searchIndex].isPuzzleStateRemove()){
					if(xHit >= 2){
						mGamePuzzle[searchIndex].setPuzzleStateRemove();
						pzRemovCnt[nowPzIndex]++;
					}
					mGamePuzzle[searchIndex].setPuzzleIndex(nowPzIndex);
				}
			}

			// 下に検索
			int yHit = 0;
			for(int k = j + 1; k < FRAME_HEIGHT; k++){
				int searchIndex = k * FRAME_WIDTH + i;
				if(mGamePuzzle[index].getPuzzleType() == mGamePuzzle[searchIndex].getPuzzleType()){
					yHit++;
				}
				else{
					break;
				}
			}

			for(int k = j; k <= j + yHit; k++){
				int searchIndex = k * FRAME_WIDTH + i;
				if(!mGamePuzzle[searchIndex].isPuzzleStateRemove()){
					if(yHit >= 2){
						mGamePuzzle[searchIndex].setPuzzleStateRemove();
						pzRemovCnt[nowPzIndex]++;
					}
				}
				mGamePuzzle[searchIndex].setPuzzleIndex(nowPzIndex);
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

			if(!mGamePuzzle[j * FRAME_WIDTH + i].isPuzzleStateRemove() && 
				!mGamePuzzle[j * FRAME_WIDTH + i].isPuzzleStateMove()){
				continue;
			}

			// 上に検索
			bool isHit = false;
			for(int k = j; k >= 0; k--){
				if(mGamePuzzle[k * FRAME_WIDTH + i].isPuzzleStateNoSet()){
					mGamePuzzle[j * FRAME_WIDTH + i] = mGamePuzzle[k * FRAME_HEIGHT + i];
					mGamePuzzle[k * FRAME_WIDTH + i].setPuzzleStateMove();
					isHit = true;
					break;
				}
			}
			if(!isHit){
				mGamePuzzle[j * FRAME_WIDTH + i].setPuzzleStateMove();
			}
		}
	}
}

void GamePuzzleManager::printPuzzle(const int _iIndex)
{
	mGamePuzzle[_iIndex].printPuzzle();
}

void GamePuzzleManager::createNewPuzzle()
{
	for(int j = FRAME_HEIGHT -1; j >= 0; j--){
		for(int i = FRAME_WIDTH -1; i >= 0; i--){
			if(!mGamePuzzle[j * FRAME_WIDTH + i].isPuzzleStateRemove() && 
				!mGamePuzzle[j * FRAME_WIDTH + i].isPuzzleStateMove()){
				continue;
			}

			// 新しいパズル作成
			mGamePuzzle[j * FRAME_WIDTH + i].setPuzzleTypeRandom();
		}
	}
}
