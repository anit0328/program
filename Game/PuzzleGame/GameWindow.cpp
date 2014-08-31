#include "GameWindow.h"
#include <iomanip>

GameWindow::GameWindow()
{
	mpTermios = new termios();

	// ターミナルの非カノニカルモード開始
	startUnCanon();
}

GameWindow::~GameWindow()
{
	// ターミナルのカノニカルモード再設定
	resetCanon();

	delete mpTermios;
}

// ターミナルの非カノニカルモード開始関数
void GameWindow::startUnCanon(){
	termios* pChangeTermios;

	// ターミナル情報を取得する
	tcgetattr(fileno(stdin), mpTermios);
	pChangeTermios = mpTermios;

	// カノニカルモードを外す
	pChangeTermios->c_iflag &= IGNCR;
	pChangeTermios->c_lflag &= ~ICANON;
	pChangeTermios->c_lflag &= ~ECHO;
	pChangeTermios->c_lflag &= ~ISIG;
	pChangeTermios->c_cc[VMIN] = 1;
	pChangeTermios->c_cc[VTIME] = 0;

	// ターミナル情報を設定する
	tcsetattr(fileno(stdin), TCSANOW, pChangeTermios);
}

// ターミナルのカノニカルモード再設定関数
void GameWindow::resetCanon(){

	// ターミナル情報を元に戻す
	tcsetattr(fileno(stdin), TCSANOW, mpTermios);
}
