#pragma once

#include <SDL3/SDL.h>

typedef struct controls_s
{
  SDL_bool exit;
  SDL_bool up, left, down, right;
} controls_t;
