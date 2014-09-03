#include "GameDisplay.h"

GameDisplay::GameDisplay()
{
	// 画面クリア
	clearDisplay();

	// スコア表示
	printScore(SCORE_INIT_VAL);

	// FEVER表示
	printFever();

	// 枠作成
	printFrame();

	// タイマーゲージ表示
	printTimer(TIMER_INIT_VAL);
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
void GameDisplay::printScore(const int _iScore)
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

void GameDisplay::printFrameStr(const char* _pStr)
{
	for(int i = 0; i < FRAME_WIDTH; i++){
		cout << _pStr;
	}
}

void GameDisplay::printFrameSide(const int _iHeight)
{
	moveLocation(1, _iHeight);
	cout << "┃";
	printFrameStr("　");
	cout << "┃";
}

void GameDisplay::printPuzzleBold(const PuzzleType _ePuzzleType)
{
	switch(_ePuzzleType){
		case ePuzzleTypeTriangle:
			printColorRed("▲");
			break;
		case ePuzzleTypeSquare:
			printColorBlue("■");
			break;
		case ePuzzleTypeCircle:
			printColorGreen("●");
			break;
		case ePuzzleTypeInvertedTriangle:
			printColorCyan("▼");
			break;
		case ePuzzleTypeStar:
			printColorYellow("★");
			break;
	}
}

void GameDisplay::printPuzzleNormal(const PuzzleType _ePuzzleType)
{
	switch(_ePuzzleType){
		case ePuzzleTypeTriangle:
			printColorRed("△");
			break;
		case ePuzzleTypeSquare:
			printColorBlue("□");
			break;
		case ePuzzleTypeCircle:
			printColorGreen("○");
			break;
		case ePuzzleTypeInvertedTriangle:
			printColorCyan("▽");
			break;
		case ePuzzleTypeStar:
			printColorYellow("☆");
			break;
	}
}

void GameDisplay::printPuzzleDown()
{
	printColorCyan("↓");
}

void GameDisplay::printTimer(const int _iTime)
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

void GameDisplay::printTimerGauge(const int _iX)
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

void GameDisplay::moveLocation(const int _iX, const int _iY)
{
	cout << "\033[" << _iY << ";" << _iX << "H";
}

void GameDisplay::printColorRed(const char* _pStr)
{
	cout << "\033[31m" << _pStr << "\033[0m";
}

void GameDisplay::printColorBlue(const char* _pStr)
{
	cout << "\033[34m" << _pStr << "\033[0m";
}

void GameDisplay::printColorGreen(const char* _pStr)
{
	cout << "\033[32m" << _pStr << "\033[0m";
}

void GameDisplay::printColorYellow(const char* _pStr)
{
	cout << "\033[33m" << _pStr << "\033[0m";
}

void GameDisplay::printColorCyan(const char* _pStr)
{
	cout << "\033[36m" << _pStr << "\033[0m";
}

void GameDisplay::printColorMagenta(const char* _pStr)
{
	cout << "\033[35m" << _pStr << "\033[0m";
}

void GameDisplay::printColorWhite(const char* _pStr)
{
	cout << "\033[37m" << _pStr << "\033[0m";
}

void GameDisplay::printColorBlack(const char* _pStr)
{
	cout << "\033[30m" << _pStr << "\033[0m";
}
