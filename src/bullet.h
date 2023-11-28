#pragma once

#include <SDL3/SDL.h>
#include <stddef.h>
#include "game.h"

typedef struct bullet_s
{
  int x, y;
  int speed;
  int damage;
  double angle;
  SDL_bool fired;
} bullet_t;

void
bullets_fire(int x, int y, double angle);

void
bullets_update(float deltatime);

void
bullets_render(void);
