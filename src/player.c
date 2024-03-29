#include "character.h"

extern const int     PLAYER_X;
extern const int     PLAYER_Y;
extern const int     PLAYER_W;
extern const int     PLAYER_H;
extern const int     PLAYER_HEALTH;
extern const int     PLAYER_SPEED;
extern const double  PLAYER_ANGLE;
extern const int     PLAYER_VIEW_LENGTH;
extern const color_t PLAYER_COLOR;
extern const color_t COLOR_GREEN;

character_t player;
extern game_t game;
extern controls_t controls;

void
player_init(void)
{
  player.x = player.wx = (float) PLAYER_X;
  player.y = player.wy = (float) PLAYER_Y;

  player.w = PLAYER_W;
  player.h = PLAYER_H;
  
  player.health = PLAYER_HEALTH;
  player.speed  = PLAYER_SPEED;
  player.angle  = PLAYER_ANGLE;

  player.isPlayable = SDL_TRUE;
  player.isPlayer   = SDL_TRUE;

  player.color = PLAYER_COLOR;
}

void
player_update(float deltatime)
{
  float speed = player.speed * deltatime;
  if (controls.up)    player.y -= speed;
  if (controls.left)  player.x -= speed;
  if (controls.down)  player.y += speed;
  if (controls.right) player.x += speed;
}

static void
click_render(void)
{
  float x, y;
  float cx, cy;

  cx = player.x + player.w / 2.;
  cy = player.y + player.h / 2.;

  SDL_GetMouseState(&x, &y);

  SDL_SetRenderDrawColor(game.renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
  SDL_RenderLine(game.renderer, cx, cy, x, y);
}

static void
view_render(void)
{
  const int length = PLAYER_VIEW_LENGTH;

  float cx = player.x + player.w / 2.;
  float cy = player.y + player.h / 2.;
  float x  = cx + length * cos(player.angle);
  float y  = cy + length * sin(player.angle);

  SDL_SetRenderDrawColor(game.renderer,
    COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b,
      SDL_ALPHA_OPAQUE);

  SDL_RenderLine(game.renderer, cx, cy, x, y);
}

void
player_render(void)
{
  click_render();
  view_render();
  character_render(&player);
}
