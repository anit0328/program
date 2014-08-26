#ifndef GameScore_h
#define GameScore_h

#include "GameConfig.h"

#define PrintMillion(n)		cout << setfill('0') << setw(3) << n/1000000 << ","
#define PrintThousand(n)	cout << setfill('0') << setw(3) << n%1000000/1000 << ","
#define PrintScore(n) 		Location(SCORE_INIT_X, SCORE_INIT_Y); PrintMillion(n); \
							PrintThousand(n); cout << setfill('0') << setw(3) << n%1000

class GameScore{

private:
	int miScore;

public:
    GameScore();
    ~GameScore();

    void printScore();
	void addScore(int);
};

#endif // GameScore_h
