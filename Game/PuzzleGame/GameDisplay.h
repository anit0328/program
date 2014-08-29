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
    void printFrameStr(string _str);
    void printFrameSide(int _iHeight);
    static void printPuzzleBold(int _iPuzzleType);
    static void printPuzzleNormal(int _iPuzzleType);
    static void printPuzzleDown();
    void printTimer(int _iTime);
    void printTimerGauge(int _iX);
    void printGameOver();
    void moveLocation(int _iX, int _iY);
	static void printColorRed(string _str);
	static void printColorBlue(string _str);
	static void printColorGreen(string _str);
	static void printColorYellow(string _str);
	static void printColorCyan(string _str);
	static void printColorMagenta(string _str);
	static void printColorWhite(string _str);
	static void printColorBlack(string _str);
};

#endif // GameDisplay_h
