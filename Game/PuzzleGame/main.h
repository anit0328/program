#include <sys/time.h>

#include "GameConfig.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "GamePuzzle.h"

struct itimerval timer_val;
struct sigaction act;
//int frameCnt = 0;

void initSetting();
void timer(int);
