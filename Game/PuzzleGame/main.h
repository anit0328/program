#include <sys/time.h>

#include "GameConfig.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "GamePuzzle.h"

struct itimerval timer_val;
struct sigaction act;

void initSetting();
void timer(int _iSig;
