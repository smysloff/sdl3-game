#include "character.h"

extern game_t game;

void
character_render(character_t *character)
{
  SDL_SetRenderDrawColor(game.renderer,
    character->color.r, character->color.g, character->color.b,
      SDL_ALPHA_OPAQUE);

  SDL_FRect rect = {
    character->x, character->y,
    character->w, character->h
  };
  SDL_RenderFillRect(game.renderer, &rect);
}
