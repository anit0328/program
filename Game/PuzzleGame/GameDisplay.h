#ifndef GameDisplay_h
#define GameDisplay_h

#include "GameConfig.h"

class GameDisplay{

enum{
	kPuzzleStateNoSet = 0,
	kPuzzleStateSelected,
	kPuzzleStateRemove,
	kPuzzleStateMove,
	kPuzzleStateCount
};

public:
enum{
	kPuzzleTypeInvalid = 0,
	kPuzzleTypeTriangle,
	kPuzzleTypeSquare,
	kPuzzleTypeCircle,
	kPuzzleTypeInvertedTriangle,
	kPuzzleTypeStar,
	kPuzzleTypeCount,
};

private:
	int miDisplay;

public:
    GameDisplay();
    ~GameDisplay();

    void clearDisplay();
    void alertBeep();
    void printScore(int);
    void printFever();
    void printFrame();
    void printFrameStr(string);
    void printFrameSide(int);
    static void printPuzzleBold(int);
    static void printPuzzleNormal(int);
    static void printPuzzleDown();
    void printTimer(int);
    void printTimerGauge(int);
    void printGameOver();
    void moveLocation(int, int);
	static void printColorRed(string);
	static void printColorBlue(string);
	static void printColorGreen(string);
	static void printColorYellow(string);
	static void printColorCyan(string);
	static void printColorMagenta(string);
	static void printColorWhite(string);
	static void printColorBlack(string);
};

#endif // GameDisplay_h
