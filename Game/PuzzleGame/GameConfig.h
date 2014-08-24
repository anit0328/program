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
#define FEVER_INIT_VAL (0)

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

#endif // GameConsig_h