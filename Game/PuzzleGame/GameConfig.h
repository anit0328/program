#ifndef GameConfig_h
#define GameConfig_h

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

#define FRAME_HEIGHT (8)
#define FRAME_WIDTH (8)

#define SCORE_INIT_X (2)
#define SCORE_INIT_Y (2)
#define SCORE_INIT_VAL (0)

#define FEVER_INIT_X (14)
#define FEVER_INIT_Y (2)

#define FRAME_INIT_X (1)
#define FRAME_INIT_Y (3)
#define FRAME_BORDER_WIDTH (1)

#define PUZZLE_AREA_INIT_X (3)
#define PUZZLE_AREA_INIT_Y (4)

#define GAME_START_INIT_X (FRAME_INIT_X + 4*2)
#define GAME_START_INIT_Y (FRAME_INIT_Y + 4)

#define TIMER_GAUGE_INIT_HEIGHT (FRAME_INIT_X + FRAME_HEIGHT + FRAME_BORDER_WIDTH*2)
#define TIMER_GAUGE_WIDTH (13)
#define TIMER_INIT_VAL (0)
#define TIMER_VAL_MAX (60)

#define Beep()				cout << "\a"
#define Clear()				cout << "\033[H\033[J"
#define Location(x,y) 		cout << "\033[" << y << ";" << x << "H"
#define DebugPrintXY(x,y) 	Location(5+FRAME_WIDTH*2, 4); cout << "x:" << x << " y:" << y << "   ";Location(x,y)
#define DebugPrintIndex(i) 	Location(5+FRAME_WIDTH*2, 5); cout << "index:"  << i << "     "
#define DebugPrintBool(b) 	Location(5+FRAME_WIDTH*2, 6); cout << "select:" << b << "     "
#define DebugPrintFps(n) 	Location(5+FRAME_WIDTH*2, 7); cout << "fps:"    << n << "     "
#define UnderLine()			cout << "\033[4m" << " " << "\033[0m"

#define FtColorRed(str)	  	cout << "\033[31m" << str << "\033[0m"
#define FtColorBlue(str)	cout << "\033[34m" << str << "\033[0m"
#define FtColorGreen(str)	cout << "\033[32m" << str << "\033[0m"
#define FtColorYellow(str)	cout << "\033[33m" << str << "\033[0m"
#define FtColorCyan(str)	cout << "\033[36m" << str << "\033[0m"
#define FtColorMagenta(str)	cout << "\033[35m" << str << "\033[0m"
#define FtColorWhite(str)	cout << "\033[37m" << str << "\033[0m"
#define FtColorBlack(str)	cout << "\033[30m" << str << "\033[0m"

#define BgColorRed(str)	  	cout << "\033[41m" << str << "\033[0m"
#define BgColorBlue(str)	cout << "\033[44m" << str << "\033[0m"
#define BgColorGreen(str)	cout << "\033[42m" << str << "\033[0m"
#define BgColorYellow(str)	cout << "\033[43m" << str << "\033[0m"
#define BgColorCyan(str)	cout << "\033[46m" << str << "\033[0m"
#define BgColorMagenta(str)	cout << "\033[45m" << str << "\033[0m"
#define BgColorWhite(str)	cout << "\033[47m\033[30m" << str << "\033[0m\033[0m"
#define BgColorBlack(str)	cout << "\033[37m" << str << "\033[0m"

#define PrintMillion(n)		cout << setfill('0') << setw(3) << n/1000000 << ","
#define PrintThousand(n)	cout << setfill('0') << setw(3) << n%1000000/1000 << ","
#define PrintScore(n) 		Location(SCORE_INIT_X, SCORE_INIT_Y); PrintMillion(n); \
							PrintThousand(n); cout << setfill('0') << setw(3) << n%1000

#define PrintFever() 		Location(FEVER_INIT_X, FEVER_INIT_Y); cout << "FEVER"
#define PrintFeverF() 		Location(FEVER_INIT_X, FEVER_INIT_Y); FtColorRed("F")
#define PrintFeverE() 		Location(FEVER_INIT_X+1, FEVER_INIT_Y); FtColorBlue("E")
#define PrintFeverV() 		Location(FEVER_INIT_X+2, FEVER_INIT_Y); FtColorGreen("V")
#define PrintFeverE2() 		Location(FEVER_INIT_X+3, FEVER_INIT_Y); FtColorCyan("E")
#define PrintFeverR() 		Location(FEVER_INIT_X+4, FEVER_INIT_Y); FtColorYellow("R")

#define PrintFrameBorder()	for(int i=0;i<FRAME_WIDTH;i++) cout << "━"
#define PrintFrameBlank()	for(int i=0;i<FRAME_WIDTH;i++) cout << "　"
#define PrintFrameTop() 	Location(1, 3); cout << "┏"; PrintFrameBorder(); cout << "┓"
#define PrintFrameSide(h) 	Location(1, h); cout << "┃"; PrintFrameBlank(); cout << "┃"
#define PrintFrameSides() 	for(int i=0;i<FRAME_HEIGHT;i++) {PrintFrameSide(4+i);}
#define PrintFrameBottom() 	Location(1, 4+FRAME_HEIGHT); cout << "┗"; PrintFrameBorder(); cout << "┛"

#define PrintTimerGauge() 	for(int i=0;i<TIMER_GAUGE_WIDTH;i++) {cout << "_";}
#define PrintInitTimer() 	Location(2, 5+FRAME_HEIGHT); PrintTimerGauge(); cout << " 1:00"
#define UpdateTimer(t)		Location(2+TIMER_GAUGE_WIDTH, 5+FRAME_HEIGHT);  cout << " 0:" << setfill('0') << setw(2) << 60-t
#define UpdateTimerGauge(x)	Location(2+x, 5+FRAME_HEIGHT); BgColorWhite(" ")

#define PrintGameOver() 	Location(2, 5+FRAME_HEIGHT); BgColorWhite("  GAME OVER  "); PrintGameContinue()
#define PrintGameContinue()	Location(2, 6+FRAME_HEIGHT); cout << "  continue? (y/n)"
#define ClearGameContinue()	Location(2, 6+FRAME_HEIGHT); cout << "\033[K"

#endif // GameConsig_h