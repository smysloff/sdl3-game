#include "game.h"

extern game_t game;
extern character_t player;

int
main(int argc, char *argv[])
{
  game_init();
  while (game.loop)
  {
    game_input();
    game_update();
    game_render();
  }
  game_quit();

  (void) argc;
  (void) argv;

  return 0;
}
