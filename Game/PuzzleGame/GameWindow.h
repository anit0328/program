#ifndef GameWindow_h
#define GameWindow_h

#include <stdio.h>
#include <stdlib.h>
#include <sys/termios.h>
#include "GameConfig.h"

class GameWindow{

private:
    struct termios mTermios;

public:
    GameWindow();
    ~GameWindow();

	void startUnCanon();
	void resetCanon();
};

#endif // GameWindow_h
