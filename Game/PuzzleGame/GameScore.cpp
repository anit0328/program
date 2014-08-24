#include "GameScore.h"

GameScore::GameScore()
{
	miScore = SCORE_INIT_VAL;
}

GameScore::~GameScore()
{
}

void GameScore::printScore()
{
	// スコア表示
	PrintScore(miScore);
}

void GameScore::addScore(int _iScore)
{
	miScore += _iScore;
}
