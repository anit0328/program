#include "main.h"

// 初期設定関数
void initSetting()
{
	// タイマー＆アラーム作成
	pItimerval = new itimerval();
	pSigaction = new struct sigaction();

	// ゲーム画面作成
	pWindow = new GameWindow();
	pManager = new GameManager();

    // 乱数初期化
    srand((unsigned)time(NULL));

	// 画面作成
	pManager->createGameWindow();

	// タイマーリセット
	pItimerval->it_value.tv_usec = 1000;
    timer(0);
}

// タイマー関数
void timer(int signum)
{
	setitimer(ITIMER_REAL, pItimerval, 0);
}

int main()
{
	// 初期設定
	initSetting();

	// アラーム設定
    pSigaction->sa_handler = timer;
    sigemptyset(&pSigaction->sa_mask);
    pSigaction->sa_flags = 0;
    sigaction(SIGALRM, pSigaction, 0);

	// 時間情報初期化
	time_t last = time(0);
	time_t next;

	while(true)
	{
		// 入力待ち
		int input = fgetc(stdin);
		if(!pManager->isGameStateGameOver())
		{
			// 時間表示
			if (time(&next) != last){
				pManager->checkComboAndUpdateTimer();
				last = next;
			}

			// 終了判定
			if(pManager->isGameOver()){
				pManager->setGameStateGameOver();
				pItimerval->it_value.tv_usec = 0;
			}

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

				// タイマー＆アラーム削除
				delete pItimerval;
				delete pSigaction;

				// ゲーム画面削除
				delete pManager;
				delete pWindow;

				// 初期設定
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

	return 0;
}

