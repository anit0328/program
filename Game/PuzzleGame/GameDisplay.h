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
    void printScore(const int _iScore);
    void printFever();
    void printFrame();
    void printFrameStr(const char* _pStr);
    void printFrameSide(const int _iHeight);
    static void printPuzzleBold(const int _iPuzzleType);
    static void printPuzzleNormal(const int _iPuzzleType);
    static void printPuzzleDown();
    void printTimer(const int _iTime);
    void printTimerGauge(const int _iX);
    void printGameOver();
    void moveLocation(const int _iX, const int _iY);
	static void printColorRed(const char* _pStr);
	static void printColorBlue(const char* _pStr);
	static void printColorGreen(const char* _pStr);
	static void printColorYellow(const char* _pStr);
	static void printColorCyan(const char* _pStr);
	static void printColorMagenta(const char* _pStr);
	static void printColorWhite(const char* _pStr);
	static void printColorBlack(const char* _pStr);
};

#endif // GameDisplay_h
