#include <sys/time.h>
#include <csignal>

#include "GameConfig.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "GamePuzzle.h"

itimerval *pItimerval;
struct sigaction *pSigaction;

GameManager* pManager;
GameWindow* pWindow;

void initSetting();
void timer(int _iSig);
