// ■コンパイル方法
// g++ main.cpp GameManager.cpp GameWindow.cpp GamePuzzle.cpp  -o exe/PuzzleGame

#include "main.h"

GameManager* pManager;
GameWindow* pWindow;

int main()
{
	// ゲーム画面作成
	pManager = new GameManager();
	pWindow = new GameWindow();

	// ターミナルのカノニカルモード開始
    struct termios save_term;
	save_term = pWindow->startCanon();

    // 乱数初期化
    srand((unsigned)time(NULL));

	// 画面クリア
	Clear();

	// 初期設定＆タイマー起動
	initSetting();

	// シグアラーム設定
    act.sa_handler = timer;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, 0);

	// 時間情報初期化
	time_t last = time(0);
	time_t next;

	while(true)
	{
		// 時間表示
		if (time(&next) != last){
			pManager->checkComboAndUpdateTimer();
			last = next;
		}

		// 終了判定
		if(pManager->miTime == 60){
			pManager->miGameState = GameManager::kGameStateGameOver;
			timer_val.it_value.tv_usec = 0;
			PrintGameOver();
		}

		// 入力待ち
		int input = fgetc(stdin);
		if(pManager->miGameState != GameManager::kGameStateGameOver)
		{
			switch(input){
				case 'D': 		   /* '←' で左に動かす */
					pManager->moveCursor(-2, 0);
					break;
				case 'C': 		   /* '→' で右に動かす */
					pManager->moveCursor(2, 0);
					break;
				case 'B': 		   /* '↑' で上に動かす */
					pManager->moveCursor(0, 1);
					break;
				case 'A': 		   /* '↓' で下に動かす */
					pManager->moveCursor(0, -1);
					break;

				case ' ': 		   /* ' ' でパズル選択 */
					pManager->selectedCursor();
					break;
			}
		}else{
			if(input == 'y'){		/* 'y' でゲーム再開 */
				ClearGameContinue();
				initSetting();
			}
			else if(input == 'n'){	/* 'n' で終了 */
				break;
			}
		}
		if(input == 'q'){		/* 'q' で終了 */
			break;
		}
	}

	// ターミナルのカノニカルモード終了
	pWindow->endCanon(save_term);

	// ゲーム画面削除
	delete pWindow;
	delete pManager;
	Location(1, 15);

	return 0;
}

// 初期設定関数
void initSetting()
{
	// 画面作成
	pManager->initVariable();
	pWindow->createGameWindow();

	// タイマーリセット
	timer_val.it_value.tv_usec = 1000;
    timer(0);

	// パズル作成
	pManager->createPuzzle();

	// 初期位置に移動
//	DebugPrintXY(pManager->miX, pManager->miY);
	pManager->getIndex(pManager->miX, pManager->miY);
//	DebugPrintBool(pManager->mbSelected);
	Location(pManager->miX, pManager->miY);
}

// タイマー関数
void timer(int signum)
{
//	frameCnt++;
	setitimer(ITIMER_REAL,&timer_val,(struct itimerval *)0);
}
