#include <stddef.h>
#include "../../common/mot_maze.h"
#include "../mot.h"

#define TILE_WIDTH      16
#define TILE_HEIGHT     16

static void
draw_mazetile(MCELL tile, int x, int y)
{
   if (tile & N_WALL)
   {
      SDL_RenderDrawLine(
            renderer,
            x + TILE_WIDTH/2,
            y,
            x + TILE_WIDTH/2,
            y + TILE_HEIGHT/2
      );
   }
   if (tile & S_WALL)
   {
      SDL_RenderDrawLine(
            renderer,
            x + TILE_WIDTH/2,
            y + TILE_HEIGHT/2,
            x + TILE_WIDTH/2,
            y + TILE_HEIGHT
      );
   }
   if (tile & E_WALL)
   {
      SDL_RenderDrawLine(
            renderer,
            x + TILE_WIDTH/2,
            y + TILE_HEIGHT/2,
            x + TILE_WIDTH,
            y + TILE_HEIGHT/2
      );
   }
   if (tile & W_WALL)
   {
      SDL_RenderDrawLine(
            renderer,
            x,
            y + TILE_HEIGHT/2,
            x + TILE_WIDTH/2,
            y + TILE_HEIGHT/2
      );
   }

}

void
draw_maze(int x, int y)
{
   unsigned int i;

   MAZE.X = x;
   MAZE.Y = y;

   for (i = 0; i < MAZE.size; i++)
   {
      draw_mazetile(
            *(MAZE.data + i),
            MAZE.X + (i % MAZE.w) * TILE_WIDTH,
            MAZE.Y + (i / MAZE.w) * TILE_HEIGHT
      );
   }

   return 0;
}
