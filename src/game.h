#pragma once

#include <stdlib.h>
#include <math.h>
#include <SDL3/SDL.h>
#include "keyboard.h"
#include "controls.h"
#include "color.h"
#include "character.h"
#include "player.h"
#include "bullet.h"

typedef struct game_s
{
  SDL_Window   *window;
  SDL_Renderer *renderer;
  SDL_Event    event;
  SDL_bool     loop;
  Uint64       lasttime;
} game_t;

void
game_init(void);

void
game_quit(void);

void
game_input(void);

void
game_update(void);

void
game_render(void);
