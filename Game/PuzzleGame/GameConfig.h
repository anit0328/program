#ifndef GameConfig_h
#define GameConfig_h

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

#define FRAME_HEIGHT (8)
#define FRAME_WIDTH (8)

#define SCORE_INIT_X (2)
#define SCORE_INIT_Y (2)
#define SCORE_INIT_VAL (0)

#define FEVER_INIT_X (14)
#define FEVER_INIT_Y (2)
#define FEVER_INIT_VAL (0)

#define FRAME_INIT_X (1)
#define FRAME_INIT_Y (3)
#define FRAME_BORDER_WIDTH (1)

#define PUZZLE_AREA_INIT_X (3)
#define PUZZLE_AREA_INIT_Y (4)
#define PUZZLE_TIPE_MAX (6)

#define GAME_START_INIT_X (FRAME_INIT_X + 4*2)
#define GAME_START_INIT_Y (FRAME_INIT_Y + 4)

#define TIMER_GAUGE_INIT_HEIGHT (FRAME_INIT_X + FRAME_HEIGHT + FRAME_BORDER_WIDTH*2)
#define TIMER_GAUGE_WIDTH (13)
#define TIMER_INIT_VAL (0)
#define TIMER_VAL_MAX (60)

#endif // GameConsig_h