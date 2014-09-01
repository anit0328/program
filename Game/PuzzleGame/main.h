#include <sys/time.h>

#include "GameConfig.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "GamePuzzle.h"

itimerval timer_val;
struct sigaction act;

GameManager* pManager;
GameWindow gameWindow;

void initSetting();
void timer(int _iSig);
