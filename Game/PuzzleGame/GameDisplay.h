#ifndef GameDisplay_h
#define GameDisplay_h

#include "GameConfig.h"

class GameDisplay{

public:
enum ePuzzleType{
	eInvalid = 0,
	eTriangle,
	eSquare,
	eCircle,
	eInvertedTriangle,
	eStar,
	ePuzzleTypeCount,
};

private:
	int miDisplay;

public:
    GameDisplay();
    ~GameDisplay();

    void clearDisplay();
    void alertBeep();
    void printScore(int _iScore);
    void printFever();
    void printFrame();
    void printFrameStr(char* _pStr);
    void printFrameSide(int _iHeight);
    static void printPuzzleBold(int _iPuzzleType);
    static void printPuzzleNormal(int _iPuzzleType);
    static void printPuzzleDown();
    void printTimer(int _iTime);
    void printTimerGauge(int _iX);
    void printGameOver();
    void moveLocation(int _iX, int _iY);
	static void printColorRed(char* _pStr);
	static void printColorBlue(char* _pStr);
	static void printColorGreen(char* _pStr);
	static void printColorYellow(char* _pStr);
	static void printColorCyan(char* _pStr);
	static void printColorMagenta(char* _pStr);
	static void printColorWhite(char* _pStr);
	static void printColorBlack(char* _pStr);
};

#endif // GameDisplay_h
