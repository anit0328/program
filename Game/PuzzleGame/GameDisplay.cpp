#include "GameDisplay.h"

GameDisplay::GameDisplay()
{
}

GameDisplay::~GameDisplay()
{
}

void GameDisplay::clearDisplay()
{
	cout << "\033[H\033[J";
}

void GameDisplay::alertBeep()
{
	cout << "\a";
}
void GameDisplay::printScore(int _iScore)
{
	moveLocation(SCORE_INIT_X, SCORE_INIT_Y);
	cout << setfill('0') << setw(3) << _iScore / 1000000 << ",";
	cout << setfill('0') << setw(3) << _iScore % 1000000 / 1000 << ",";
	cout << setfill('0') << setw(3) << _iScore % 1000;
}

void GameDisplay::printFever()
{
	string str = "FEVER";
	string color[] = {"31m", "34m", "32m", "36m", "33m"};

	// FEVER表示
	moveLocation(FEVER_INIT_X, FEVER_INIT_Y);
	cout << str;

	// FEVER表示
	for(int i = 0; i < str.length(); i++){
		moveLocation(FEVER_INIT_X + i, FEVER_INIT_Y);
		cout << "\033[" << color[i] << str.at(i) << "\033[0m";
	}
}

void GameDisplay::printFrame()
{
	moveLocation(1, 3);
	cout << "┏";
	printFrameStr("━");
	cout << "┓";

	for(int i = 0; i < FRAME_HEIGHT; i++) {
		printFrameSide(4 + i);
	}

	moveLocation(1, 4 + FRAME_HEIGHT);
	cout << "┗";
	printFrameStr("━");
	cout << "┛";
}

void GameDisplay::printFrameStr(string _str)
{
	for(int i = 0; i < FRAME_WIDTH; i++){
		cout << _str;
	}
}

void GameDisplay::printFrameSide(int _iHeight)
{
	moveLocation(1, _iHeight);
	cout << "┃";
	printFrameStr("　");
	cout << "┃";
}

void GameDisplay::printPuzzleBold(int _iPuzzleType)
{
	switch(_iPuzzleType){
		case eTriangle:
			printColorRed("▲");
			break;
		case eSquare:
			printColorBlue("■");
			break;
		case eCircle:
			printColorGreen("●");
			break;
		case eInvertedTriangle:
			printColorCyan("▼");
			break;
		case eStar:
			printColorYellow("★");
			break;
	}
}

void GameDisplay::printPuzzleNormal(int _iPuzzleType)
{
	switch(_iPuzzleType){
		case eTriangle:
			printColorRed("△");
			break;
		case eSquare:
			printColorBlue("□");
			break;
		case eCircle:
			printColorGreen("○");
			break;
		case eInvertedTriangle:
			printColorCyan("▽");
			break;
		case eStar:
			printColorYellow("☆");
			break;
	}
}

void GameDisplay::printPuzzleDown()
{
	printColorCyan("↓");
}

void GameDisplay::printTimer(int _iTime)
{
	if(_iTime == TIMER_INIT_VAL){
		moveLocation(2, 5 + FRAME_HEIGHT);
		for(int i = 0; i < TIMER_GAUGE_WIDTH; i++){
			cout << "_";
		}
		cout << " 1:00";
	} else {
		moveLocation(2 + TIMER_GAUGE_WIDTH, 5 + FRAME_HEIGHT);
		cout << " 0:" << setfill('0') << setw(2) << 60 - _iTime;
	}
}

void GameDisplay::printTimerGauge(int _iX)
{
	moveLocation(2 + _iX, 5 + FRAME_HEIGHT);
	cout << "\033[47m\033[30m \033[0m\033[0m";
}

void GameDisplay::printGameOver()
{
	moveLocation(2, 5 + FRAME_HEIGHT);
	cout << "\033[47m\033[30m  GAME OVER  \033[0m\033[0m";
	moveLocation(2, 6+FRAME_HEIGHT);
	cout << "  continue? (y/n)";
}

void GameDisplay::moveLocation(int _iX, int _iY)
{
	cout << "\033[" << _iY << ";" << _iX << "H";
}

void GameDisplay::printColorRed(string _str)
{
	cout << "\033[31m" << _str << "\033[0m";
}

void GameDisplay::printColorBlue(string _str)
{
	cout << "\033[34m" << _str << "\033[0m";
}

void GameDisplay::printColorGreen(string _str)
{
	cout << "\033[32m" << _str << "\033[0m";
}

void GameDisplay::printColorYellow(string _str)
{
	cout << "\033[33m" << _str << "\033[0m";
}

void GameDisplay::printColorCyan(string _str)
{
	cout << "\033[36m" << _str << "\033[0m";
}

void GameDisplay::printColorMagenta(string _str)
{
	cout << "\033[35m" << _str << "\033[0m";
}

void GameDisplay::printColorWhite(string _str)
{
	cout << "\033[37m" << _str << "\033[0m";
}

void GameDisplay::printColorBlack(string _str)
{
	cout << "\033[30m" << _str << "\033[0m";
}
