#ifndef GameTimeGauge_h
#define GameTimeGauge_h

#include "GameConfig.h"

#define PrintTimerGauge() 	for(int i=0;i<TIMER_GAUGE_WIDTH;i++) {cout << "_";}
#define PrintInitTimer() 	Location(2, 5+FRAME_HEIGHT); PrintTimerGauge(); cout << " 1:00"
#define UpdateTimer(t)		Location(2+TIMER_GAUGE_WIDTH, 5+FRAME_HEIGHT);  cout << " 0:" << setfill('0') << setw(2) << 60-t
#define UpdateTimerGauge(x)	Location(2+x, 5+FRAME_HEIGHT); BgColorWhite(" ")

class GameTimeGauge{

private:
	int miTime;
	int miTimeGauge;

public:
    GameTimeGauge();
    ~GameTimeGauge();

	void printInitTimer();
	void updateTimer();
	int  getTime();
};

#endif // GameTimeGauge_h
