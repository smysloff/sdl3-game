#include "color.h"

const char   *WINDOW_TITLE       = "Simple Top-Down 2d Game";
const int     WINDOW_WIDTH       = 1280;
const int     WINDOW_HEIGHT      = 720;

const color_t COLOR_BGROUND      = { 0x00, 0x00, 0x00 };
const color_t COLOR_FGROUND      = { 0xFF, 0xFF, 0xFF };

const int     PLAYER_X           = 10;
const int     PLAYER_Y           = 10;
const int     PLAYER_W           = 20;
const int     PLAYER_H           = 20;
const int     PLAYER_HEALTH      = 100;
const int     PLAYER_SPEED       = 120;
const double  PLAYER_ANGLE       = 0;
const int     PLAYER_VIEW_LENGTH = 256;
const color_t PLAYER_COLOR       = { 0x00, 0x00, 0xFF };
