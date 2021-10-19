#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int key_up;
    int key_down;
    int key_left;
    int key_right;
} App;

typedef struct {
    int x;
    int y;
    SDL_Texture *texture;
} Entity;

const unsigned char white[3] = {255, 255, 255};
const unsigned char black[3] = {255, 255, 255};
const unsigned char red[3] = {255, 0, 0};
const unsigned char green[3] = {0, 255, 0};
const unsigned char blue[3] = {0, 0, 255};

App app;
Entity player;

void InitSDL(void);
void ExitSDL(int flag);
void InitPlayer(void);
void ClearStage(void);
void ShowStage(void);
void CalculatePos(void);
void Draw(void);
void GetInput(void);
void ResponseKeyUp(SDL_KeyboardEvent *event);
void ResponseKeyDown(SDL_KeyboardEvent *event);

int main(void) {
    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    InitSDL();
    InitPlayer();

    for (;;) {
        ClearStage();
        GetInput();
        CalculatePos();
        Draw();
        ShowStage();
        SDL_Delay(16);
    }

    return 0;
}

void InitSDL(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("[ERROR] in InitSDL(): %s", SDL_GetError());
        ExitSDL(1);
    }

    app.window = SDL_CreateWindow("Avoid!", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, 0);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    return;
}

void ExitSDL(int flag) {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
    exit(flag);

    return;
}

void InitPlayer(void) {
    player.texture = IMG_LoadTexture(app.renderer, "./gfx/Player.png");
    player.x = 320;
    player.y = 240;
}

void ClearStage(void) {
    SDL_SetRenderDrawColor(app.renderer, white[0], white[1], white[2], 255);
    SDL_RenderClear(app.renderer);

    return;
}

void ShowStage(void) { SDL_RenderPresent(app.renderer); }

void Draw(void) {
    SDL_Rect dest;

    dest.x = player.x;
    dest.y = player.y;
    SDL_QueryTexture(player.texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app.renderer, player.texture, NULL, &dest);

    return;
}

void CalculatePos(void) {
    if (app.key_up) {
        player.y -= 4;
    }
    if (app.key_down) {
        player.y += 4;
    }
    if (app.key_left) {
        player.x -= 4;
    }
    if (app.key_right) {
        player.x += 4;
    }

    return;
}

void GetInput(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                ExitSDL(0);
                break;
            case SDL_KEYUP:
                ResponseKeyUp(&event.key);
                break;
            case SDL_KEYDOWN:
                ResponseKeyDown(&event.key);
                break;
            default:
                break;
        }
    }

    return;
}

void ResponseKeyUp(SDL_KeyboardEvent *event) {
    if (event->repeat == 0) {
        SDL_Scancode key_input = event->keysym.scancode;
        switch (key_input) {
            case SDL_SCANCODE_UP:
                app.key_up = 0;
                break;
            case SDL_SCANCODE_DOWN:
                app.key_down = 0;
                break;
            case SDL_SCANCODE_LEFT:
                app.key_left = 0;
                break;
            case SDL_SCANCODE_RIGHT:
                app.key_right = 0;
                break;
        }
    }

    return;
}

void ResponseKeyDown(SDL_KeyboardEvent *event) {
    if (event->repeat == 0) {
        SDL_Scancode key_input = event->keysym.scancode;
        switch (key_input) {
            case SDL_SCANCODE_UP:
                app.key_up = 1;
                break;
            case SDL_SCANCODE_DOWN:
                app.key_down = 1;
                break;
            case SDL_SCANCODE_LEFT:
                app.key_left = 1;
                break;
            case SDL_SCANCODE_RIGHT:
                app.key_right = 1;
                break;
        }
    }

    return;
}