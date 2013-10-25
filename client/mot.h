#ifndef _MOT_H_
#define _MOT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define CFG_FNAME    "config.lua"

#define DEF_WIDTH    	800
#define DEF_HEIGHT   	600
#define DEF_FULLSCREEN	0
#define DEF_HWACCEL     1

SDL_Renderer *renderer;

typedef struct
{
   int win_width;
   int win_height;
   Uint32 win_flags;
   Uint32 renderflags;
   char *luamain;
   char *defaultsrv;
} CLC_CONFIG;

typedef struct
{
   SDL_Texture *texture;
   SDL_Rect rect;
} PICTURE;

void draw_maze(int x, int y);
void parsecfg(lua_State *L, CLC_CONFIG *config);

#endif
