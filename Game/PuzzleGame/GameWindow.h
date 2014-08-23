#ifndef GameWindow_h
#define GameWindow_h

#include <stdio.h>
#include <stdlib.h>
#include <sys/termios.h>
#include <errno.h>
#include "GameConfig.h"

class GameWindow{

public:
    GameWindow();
    ~GameWindow();

	void createGameWindow();
	struct termios startCanon();
	void endCanon(struct termios);
};

#endif // GameWindow_h
