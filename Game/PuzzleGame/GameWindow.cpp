#include "GameWindow.h"
#include <iomanip>

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{
}

void GameWindow::createGameWindow()
{
	// スコア表示
	PrintScore(SCORE_INIT_VAL);

	// FEVER表示
	PrintFever();

	// FEVER表示
	PrintFeverF();
	PrintFeverE();
	PrintFeverV();
	PrintFeverE2();
	PrintFeverR();

	// 枠作成
	PrintFrameTop();
	PrintFrameSides();
	PrintFrameBottom();

	// タイマーゲージ作成
	PrintInitTimer();
}

// ターミナルのカノニカルモード開始関数
struct termios GameWindow::startCanon(){
    struct termios save_term;
    struct termios temp_term;

    /* 現在の端末設定を取得 */
    errno = 0;
    if(tcgetattr(fileno(stdin), &save_term) == -1){
        perror("tcgetattr failure");
        exit(EXIT_FAILURE);
    }else{
        temp_term = save_term;
    }

    /* 受信したCRを無視 */
    temp_term.c_iflag &= IGNCR;
    /* カノニカルモードを外す */
    temp_term.c_lflag &= ~ICANON;
    /* 入力をエコーしない */
    temp_term.c_lflag &= ~ECHO;
    /* シグナルを無効化 */
    temp_term.c_lflag &= ~ISIG;
    /* 何文字受け取ったらreadが返るか */
    temp_term.c_cc[VMIN] = 1;
    /* 何秒経ったらreadが返るか */
    temp_term.c_cc[VTIME] = 0;

    errno = 0;
    if(tcsetattr(fileno(stdin), TCSANOW, &temp_term) == -1){
        perror("tcsetattr(temp_term) failure");
        exit(EXIT_FAILURE);
    }

	return save_term;
}

// ターミナルのカノニカルモード終了関数
void GameWindow::endCanon(struct termios save_term){
    /* 端末設定をもとに戻す */
    errno = 0;
    if(tcsetattr(fileno(stdin), TCSANOW, &save_term) == -1){
        perror("tcsetattr(save_term) failure");
        exit(EXIT_FAILURE);
    }
}
