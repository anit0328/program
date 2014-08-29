#include "main.h"

GameManager* pManager;
GameWindow* pWindow;

// 初期設定関数
void initSetting()
{
	// ゲーム画面作成
	pWindow = new GameWindow();
	pManager = new GameManager();

    // 乱数初期化
    srand((unsigned)time(NULL));

	// 画面作成
	pManager->createGameWindow();

	// タイマーリセット
	timer_val.it_value.tv_usec = 1000;
    timer(0);
}

// タイマー関数
void timer(int signum)
{
	setitimer(ITIMER_REAL,&timer_val,(struct itimerval *)0);
}

int main()
{
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
				timer_val.it_value.tv_usec = 0;
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

				// ゲーム画面削除
				delete pManager;
				delete pWindow;

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

	// ゲーム画面削除
	delete pManager;
	delete pWindow;

	return 0;
}

