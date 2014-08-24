#ifndef GameManager_h
#define GameManager_h

#include "GameConfig.h"
#include "GameFrame.h"
#include "GameScore.h"
#include "GameFever.h"
#include "GameTimeGauge.h"
#include "GamePuzzleManager.h"

#define PrintGameOver() 	Location(2, 5+FRAME_HEIGHT); BgColorWhite("  GAME OVER  "); PrintGameContinue()
#define PrintGameContinue()	Location(2, 6+FRAME_HEIGHT); cout << "  continue? (y/n)"
#define ClearGameContinue()	Location(2, 6+FRAME_HEIGHT); cout << "\033[K"

class GameManager{

enum{
	kGameStateNoSet = 0,
	kGameStateStandby,
	kGameStateRemove,
	kGameStateMove,
	kGameStateGameOver,
	kGameStateCount
};

private:
	int miX;
	int miY;
	int miGameState;
	GameScore* mpScore;
	GameFever* mpFever;
	GameTimeGauge* mpTimeGauge;
	GamePuzzleManager* mpPuzzleManager;
	bool mbSelected;

public:
    GameManager();
    ~GameManager();

	void createGameWindow();
	void moveCursor(int _moveX, int _moveY);
	void selectedCursor();
	int  getIndex(int _iX, int _iY);
	void checkComboAndUpdateTimer();
	bool isGameOver();
	void setGameStateGameOver();
	bool isGameStateGameOver();
};

#endif // GameManager_h
