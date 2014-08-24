#include "GameTimeGauge.h"

GameTimeGauge::GameTimeGauge()
{
	miTime = TIMER_INIT_VAL;
	miTimeGauge = TIMER_INIT_VAL;
}

GameTimeGauge::~GameTimeGauge()
{
}

void GameTimeGauge::printInitTimer()
{
	PrintInitTimer();
}

void GameTimeGauge::updateTimer()
{
	miTime++;
	UpdateTimer(miTime);

	if(miTime == 1 || miTime % 5 == 0){
		UpdateTimerGauge(miTimeGauge++);
	}
}

int GameTimeGauge::getTime()
{
	return miTime;
}