#pragma once

#include <SDL3/SDL.h>
#include <stddef.h>
#include "game.h"

typedef struct bullet_s
{
  float x, y;
  int speed;
  int damage;
  double angle;
  SDL_bool fired;
} bullet_t;

void
bullets_fire(float x, float y, double angle);

void
bullets_update(float deltatime);

void
bullets_render(void);
