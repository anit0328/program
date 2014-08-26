#ifndef GameFever_h
#define GameFever_h

#include "GameConfig.h"

#define PrintFever() 	Location(FEVER_INIT_X, FEVER_INIT_Y); cout << "FEVER"
#define PrintFeverF() 	Location(FEVER_INIT_X, FEVER_INIT_Y); FtColorRed("F")
#define PrintFeverE() 	Location(FEVER_INIT_X+1, FEVER_INIT_Y); FtColorBlue("E")
#define PrintFeverV() 	Location(FEVER_INIT_X+2, FEVER_INIT_Y); FtColorGreen("V")
#define PrintFeverE2() 	Location(FEVER_INIT_X+3, FEVER_INIT_Y); FtColorCyan("E")
#define PrintFeverR() 	Location(FEVER_INIT_X+4, FEVER_INIT_Y); FtColorYellow("R")

class GameFever{

private:
	int miFever;

public:
    GameFever();
    ~GameFever();

    void printFever();
};

#endif // GameFever_h
