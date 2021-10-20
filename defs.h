#ifndef DEFS_H
#define DEFS_H

#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#define FPS 60
#define BUFSIZE 1024

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define PLAYER_WIDTH 24
#define PLAYER_HEIGHT 24
#define PLAYER_SPEED 4

#define BULLET_WIDTH 8
#define BULLET_HEIGHT 8
#define BULLET_SPEED 6
#define NUM_BULLETS 16

#define FONTSIZE 20

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    TTF_Font *font;
    int key_up;
    int key_down;
    int key_left;
    int key_right;
    int key_r;
} App;

typedef struct {
    SDL_Rect pos;
    double theta;
    int health;
    SDL_Texture *texture;
} Entity;

typedef struct {
    SDL_Rect pos;
    SDL_Color color;
    SDL_Surface *surface;
    SDL_Texture *texture;
} Text;

#endif