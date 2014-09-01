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
	termios changeTerm;

	// ターミナル情報を取得する
	tcgetattr(fileno(stdin), &term);
	changeTerm = term;

	// カノニカルモードを外す
	changeTerm.c_iflag &= IGNCR;
	changeTerm.c_lflag &= ~ICANON;
	changeTerm.c_lflag &= ~ECHO;
	changeTerm.c_lflag &= ~ISIG;
	changeTerm.c_cc[VMIN] = 1;
	changeTerm.c_cc[VTIME] = 0;

	// ターミナル情報を設定する
	tcsetattr(fileno(stdin), TCSANOW, &changeTerm);
}

// ターミナルのカノニカルモード再設定関数
void GameWindow::resetCanon(){

	// ターミナル情報を元に戻す
	tcsetattr(fileno(stdin), TCSANOW, &term);
}
