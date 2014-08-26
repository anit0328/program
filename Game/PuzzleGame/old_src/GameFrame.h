#ifndef GameFrame_h
#define GameFrame_h

#include "GameConfig.h"

#define PrintFrameBorder()	for(int i=0;i<FRAME_WIDTH;i++) cout << "━"
#define PrintFrameBlank()	for(int i=0;i<FRAME_WIDTH;i++) cout << "　"
#define PrintFrameTop() 	Location(1, 3); cout << "┏"; PrintFrameBorder(); cout << "┓"
#define PrintFrameSide(h) 	Location(1, h); cout << "┃"; PrintFrameBlank(); cout << "┃"
#define PrintFrameSides() 	for(int i=0;i<FRAME_HEIGHT;i++) {PrintFrameSide(4+i);}
#define PrintFrameBottom() 	Location(1, 4+FRAME_HEIGHT); cout << "┗"; PrintFrameBorder(); cout << "┛"

class GameFrame{

public:
	static void printFrame();
};

#endif // GameFrame_h
