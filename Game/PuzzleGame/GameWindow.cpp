#include "GameWindow.h"
#include <iomanip>

GameWindow::GameWindow()
{
	// ターミナルの非カノニカルモード開始
	startUnCanon();
}

GameWindow::~GameWindow()
{
	// ターミナルのカノニカルモード再設定
	resetCanon();
}

// ターミナルの非カノニカルモード開始関数
void GameWindow::startUnCanon(){
    struct termios changeTermios;

	// ターミナル情報を取得する
    if(tcgetattr(fileno(stdin), &mTermios) == -1){
        exit(EXIT_FAILURE);
    }else{
        changeTermios = mTermios;
    }

    // カノニカルモードを外す
    changeTermios.c_iflag &= IGNCR;
    changeTermios.c_lflag &= ~ICANON;
    changeTermios.c_lflag &= ~ECHO;
    changeTermios.c_lflag &= ~ISIG;
    changeTermios.c_cc[VMIN] = 1;
    changeTermios.c_cc[VTIME] = 0;

	// ターミナル情報を設定する
    if(tcsetattr(fileno(stdin), TCSANOW, &changeTermios) == -1){
        exit(EXIT_FAILURE);
    }
}

// ターミナルのカノニカルモード再設定関数
void GameWindow::resetCanon(){

	// ターミナル情報を元に戻す
    if(tcsetattr(fileno(stdin), TCSANOW, &mTermios) == -1){
        exit(EXIT_FAILURE);
    }
}
