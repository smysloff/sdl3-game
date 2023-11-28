#pragma once

#include <SDL3/SDL.h>
#include "game.h"

typedef struct character_s
{
  float    x, y;       // current position
  float    wx, wy;     // waypoint position
  int      h, w;       // size
  int      health;
  int      speed;      // pixels per 1 second
  double   angle;      // in radians
  color_t  color;      // r, g, b
  SDL_bool isPlayable; // is it possible to player controls this character
  SDL_bool isPlayer;   // is player are controlling this character
} character_t;

void
character_render(character_t *character);
