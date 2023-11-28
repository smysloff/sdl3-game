#include "bullet.h"

const size_t MAX_BULLETS   = 6;
const int    BULLET_DAMAGE = 50;
const int    BULLET_SPEED  = 2048;

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern game_t game;

bullet_t bullets[6];

void
bullets_fire(int x, int y, double angle)
{
   for (size_t i = 0; i < MAX_BULLETS; ++i)
   {
      if (!bullets[i].fired) {
	bullets[i].x      = x;
	bullets[i].y      = y;
	bullets[i].speed  = BULLET_SPEED;
	bullets[i].damage = BULLET_DAMAGE;
	bullets[i].angle  = angle;
	bullets[i].fired  = SDL_TRUE;
      }
   }
}

void
bullets_update(float deltatime)
{
  for (size_t i = 0; i < MAX_BULLETS; ++i)
  {
    if (!bullets[i].fired) continue;

    bullets[i].x = (int) bullets[i].x
      + deltatime * BULLET_SPEED * cos(bullets[i].angle);
    bullets[i].y = (int) bullets[i].y
      + deltatime * BULLET_SPEED * sin(bullets[i].angle);

    if (
      bullets[i].x < 0 || bullets[i].x > WINDOW_WIDTH
      || bullets[i].y < 0 || bullets[i].y > WINDOW_HEIGHT
    ) {
      bullets[i].fired = SDL_FALSE;
    }
  }
}

void
bullets_render(void)
{
  SDL_SetRenderDrawColor(game.renderer,
    0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);

  for (size_t i = 0; i < MAX_BULLETS; ++i)
  {
    if (!bullets[i].fired) continue;

    SDL_FRect rect = { bullets[i].x - 1, bullets[i].y - 1, 3, 3 };
    SDL_RenderFillRect(game.renderer, &rect);
  }
}
