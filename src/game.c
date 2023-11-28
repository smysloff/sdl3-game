#include "game.h"

extern const char *WINDOW_TITLE;
extern const int   WINDOW_WIDTH;
extern const int   WINDOW_HEIGHT;

extern color_t COLOR_BGROUND;
extern color_t COLOR_FGROUND;

game_t game;
extern keyboard_t  keyboard;
extern controls_t  controls;
extern character_t player;

static float
get_deltatime(void);

static void
mouse_motion_handler(SDL_MouseMotionEvent motion);

void
game_init(void)
{
  if (SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_LogInfo(SDL_LOG_CATEGORY_ERROR,
      "SDL_Init(). %s.", SDL_GetError());
    game_quit();
    exit(1);
  }

  game.window = SDL_CreateWindow(
    WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!game.window)
  {
    SDL_LogInfo(SDL_LOG_CATEGORY_ERROR,
      "SDL_CreateWindow(). %s.", SDL_GetError());
    game_quit();
    exit(1);
  }

  game.renderer = SDL_CreateRenderer(game.window, NULL,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!game.renderer)
  {
    SDL_LogInfo(SDL_LOG_CATEGORY_ERROR,
      "SDL_CreateRenderer(). %s.", SDL_GetError());
    game_quit();
    exit(1);
  }

  // 0 - nearest pixel, 1 - linear, 2 - anisotropic filtering
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
 
  game.loop = SDL_TRUE;

  player_init();
}

void
game_quit(void)
{
  if (game.renderer)
    SDL_DestroyRenderer(game.renderer);
  if (game.window)
    SDL_DestroyWindow(game.window);
  if (SDL_WasInit(SDL_INIT_VIDEO))
    SDL_Quit();
}

void
mouse_button_down_handler(SDL_MouseButtonEvent event)
{
  if (event.button == SDL_BUTTON_LEFT)
  {
    bullets_fire(
      player.x + (int) (player.w / 2),
      player.y + (int) (player.h / 2),
      player.angle
    );
  }
}

void
mouse_button_up_handler(SDL_MouseButtonEvent event)
{
  (void) event;
}


void
game_input(void)
{
  while (SDL_PollEvent(&game.event))
  {
    switch (game.event.type)
    {
      case SDL_EVENT_QUIT: game.loop = SDL_FALSE;
	break;
      case SDL_EVENT_KEY_DOWN:
	keyboard_keydown_handler(game.event.key.keysym.sym);
	break;
      case SDL_EVENT_KEY_UP:
	keyboard_keyup_handler(game.event.key.keysym.sym);
	break;
      case SDL_EVENT_MOUSE_MOTION:
	mouse_motion_handler(game.event.motion);
	break;
      case SDL_EVENT_MOUSE_BUTTON_DOWN:
	mouse_button_down_handler(game.event.button);
	break;
      case SDL_EVENT_MOUSE_BUTTON_UP:
	mouse_button_up_handler(game.event.button);
	break;
    }
  }

  controls.exit  = keyboard.escape;
  controls.up    = keyboard.w || keyboard.up;
  controls.left  = keyboard.a || keyboard.left;
  controls.down  = keyboard.s || keyboard.down;
  controls.right = keyboard.d || keyboard.right;
}

void
game_update(void)
{
  if (keyboard.escape) game.loop = SDL_FALSE;

  float deltatime = get_deltatime();
  player_update(deltatime);
  bullets_update(deltatime);
}

static void
render_clear(void)
{
  SDL_SetRenderDrawColor(game.renderer,
    COLOR_BGROUND.r, COLOR_BGROUND.g, COLOR_BGROUND.b,
      SDL_ALPHA_OPAQUE);
  SDL_RenderClear(game.renderer);
}

static void
render_present(void)
{
  SDL_RenderPresent(game.renderer);
}

void
game_render(void)
{
  render_clear();
  bullets_render();
  player_render();
  render_present();
}

static float
get_deltatime(void)
{
  Uint64 ticks = SDL_GetTicks();
  float deltatime = (ticks - game.lasttime) / 1000.;
  game.lasttime = ticks;
  return deltatime;
}

static void
mouse_motion_handler(SDL_MouseMotionEvent motion)
{
  player.angle = atan2(motion.y - (int) player.y, motion.x - (int) player.x);
}
