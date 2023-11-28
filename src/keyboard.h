#pragma once

#include <SDL3/SDL.h>

typedef struct keyboard_s
{
  SDL_bool escape;
  SDL_bool up, left, down, right;
  SDL_bool w, a, s, d;
} keyboard_t;

void
keyboard_keydown_handler(SDL_Keycode keycode);

void
keyboard_keyup_handler(SDL_Keycode keycode);
