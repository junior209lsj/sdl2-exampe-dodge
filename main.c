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
#define BULLET_SPEED 8
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

const unsigned char white[3] = {255, 255, 255};

App app;
Entity player;
Entity bullet[NUM_BULLETS];
Entity game_over;
Text score_board;
char score_text[BUFSIZE];
int score;

// Initialization
void InitSDL(void);
void InitTTF(void);
void QuitTTF(void);
void QuitSDL(int flag);

void InitMemorySet(void);
void InitScoreBoard(void);
void InitPlayer(void);
void InitBullet(void);
void InitGameOver(void);

// Clear and show
void ClearStage(void);
void ShowStage(void);

// Inputs
void GetInput(void);
void ResponseKeyUp(SDL_KeyboardEvent *event);
void ResponseKeyDown(SDL_KeyboardEvent *event);

// Logics
void LogicGame(void);
void LogicGameOver(void);
void ActPlayer(void);
void ActBullet(void);
void ActScoreBoard(void);
void ActFinalScoreBoard(void);
void ActCheckDeath(void);
void ActGameOver(void);

// Utils
int CheckCollisionWall(Entity *object);
int CheckCollisionObjects(Entity *object_a, Entity *object_b);
void RandSpawnBullet(Entity *object);
int RandInt(int min_val, int max_val);
double RandDouble(double min_val, double max_val);

// Drawing
void DrawGame(void);
void DrawGameOver(void);
void RenderEntity(Entity *object);
void RenderScoreBoard(Text *object);

int main(void) {
    int tmpcnt = 0;

    srand(time(NULL));

    InitMemorySet();
    InitSDL();
    InitTTF();
    InitGameOver();
    InitPlayer();
    InitBullet();
    InitScoreBoard();

    for (;;) {
        ClearStage();

        GetInput();

        if (player.health) {
            LogicGame();
            DrawGame();

            if (tmpcnt++ == FPS) {
                score++;
                tmpcnt = 0;
            }
        } else {
            LogicGameOver();
            DrawGameOver();
        }

        ShowStage();

        SDL_Delay(16);


    }

    return 0;
}

void InitMemorySet(void) {
    memset(&app, 0, sizeof(App));
    memset(&game_over, 0, sizeof(Entity));
    memset(&player, 0, sizeof(Entity));
    memset(&bullet, 0, NUM_BULLETS * sizeof(Entity));
    memset(&score_board, 0, sizeof(Text));

    return;
}

void InitSDL(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("[ERROR] in InitSDL(): %s", SDL_GetError());
        QuitSDL(1);
    }

    app.window = SDL_CreateWindow("Dodge!", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, 0);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    return;
}

void InitTTF(void) {
    if (TTF_Init() < 0) {
        printf("[ERROR] in InitTTF(): %s", SDL_GetError());
        QuitSDL(1);
    }

    app.font = TTF_OpenFont("./ttf/Roboto-Regular.ttf", 20);

    return;
}

void QuitTTF(void) {
    TTF_CloseFont(app.font);
    TTF_Quit();

    return;
}

void QuitSDL(int flag) {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    QuitTTF();
    SDL_Quit();
    exit(flag);

    return;
}

void InitScoreBoard(void) {
    score = 0;
    score_board.color.r = 0;
    score_board.color.g = 0;
    score_board.color.b = 0;
    score_board.color.a = 0;

    score_board.pos.x = 420;
    score_board.pos.y = 40;
    // score_board.pos.w = 0;
    // score_board.pos.h = 0;

    return;
}

void InitPlayer(void) {
    player.texture = IMG_LoadTexture(app.renderer, "./gfx/Player.png");
    player.pos.x = SCREEN_WIDTH / 2;
    player.pos.y = SCREEN_HEIGHT / 2;
    // player.pos.w = PLAYER_WIDTH;
    // player.pos.h = PLAYER_HEIGHT;
    player.health = 1;

    return;
}

void InitBullet(void) {
    for (int i = 0; i < NUM_BULLETS; i++) {
        bullet[i].texture = IMG_LoadTexture(app.renderer, "./gfx/Bullet.png");
        // bullet[i].pos.w = BULLET_WIDTH;
        // bullet[i].pos.h = BULLET_HEIGHT;
        RandSpawnBullet(&bullet[i]);
    }

    return;
}

void InitGameOver(void) {
    game_over.texture = IMG_LoadTexture(app.renderer, "./gfx/GameOver.png");
    game_over.pos.x = 0;
    game_over.pos.y = 0;
    game_over.pos.w = 0;
    game_over.pos.h = 0;
}

void ClearStage(void) {
    SDL_SetRenderDrawColor(app.renderer, white[0], white[1], white[2], 255);
    SDL_RenderClear(app.renderer);

    return;
}

void ShowStage(void) {
    SDL_RenderPresent(app.renderer);

    return;
}

void DrawGame(void) {

    RenderEntity(&player);
    for (int i = 0; i < NUM_BULLETS; i++) {
        RenderEntity(&(bullet[i]));
    }
    RenderScoreBoard(&score_board);

    return;
}

void DrawGameOver(void) {

    RenderEntity(&game_over);
    RenderScoreBoard(&score_board);

    return;
}

void RenderScoreBoard(Text *object) {

    SDL_QueryTexture(object->texture, NULL, NULL, &(object->pos.w),
                     &(object->pos.h));
    SDL_RenderCopy(app.renderer, object->texture, NULL, &(object->pos));

    return;
}

void RenderEntity(Entity *object) {

    SDL_QueryTexture(object->texture, NULL, NULL, &(object->pos.w),
                     &(object->pos.h));
    SDL_RenderCopy(app.renderer, object->texture, NULL, &(object->pos));

    return;
}

void LogicGame(void) {
    ActPlayer();
    ActBullet();
    ActScoreBoard();
    ActCheckDeath();

    return;
}

void LogicGameOver(void) {
    ActFinalScoreBoard();
    ActGameOver();

    return;
}

void ActGameOver(void) {
    if (app.key_r) {
        InitPlayer();
        InitBullet();
        InitScoreBoard();
    }

    return;
}

void ActPlayer(void) {
    if (app.key_up) {
        player.pos.y -= PLAYER_SPEED;
        if (CheckCollisionWall(&player)) {
            player.pos.y += PLAYER_SPEED;
        }
    }
    if (app.key_down) {
        player.pos.y += PLAYER_SPEED;
        if (CheckCollisionWall(&player)) {
            player.pos.y -= PLAYER_SPEED;
        }
    }
    if (app.key_left) {
        player.pos.x -= PLAYER_SPEED;
        if (CheckCollisionWall(&player)) {
            player.pos.x += PLAYER_SPEED;
        }
    }
    if (app.key_right) {
        player.pos.x += PLAYER_SPEED;
        if (CheckCollisionWall(&player)) {
            player.pos.x -= PLAYER_SPEED;
        }
    }

    return;
}

void ActBullet(void) {

    for (int i = 0; i < NUM_BULLETS; i++) {

        bullet[i].pos.x += (int)(BULLET_SPEED * cos(bullet[i].theta));
        bullet[i].pos.y += (int)(BULLET_SPEED * sin(bullet[i].theta));
        if (CheckCollisionWall(&bullet[i])) {
            RandSpawnBullet(&bullet[i]);
        }
    }

    return;
}

void ActScoreBoard(void) {

    char tmp[36];
    strcpy(score_text, "Your Score: ");
    SDL_itoa(score, tmp, 10);
    strcat(score_text, tmp);
    score_board.surface =
        TTF_RenderText_Solid(app.font, score_text, score_board.color);
    score_board.texture =
        SDL_CreateTextureFromSurface(app.renderer, score_board.surface);

    return;
}

void ActFinalScoreBoard(void) {

    score_board.pos.x = 300;
    score_board.pos.y = 240;
    score_board.pos.w = 0;
    score_board.pos.h = 0;

    char tmp[36];
    strcpy(score_text, "Your Final Score: ");
    SDL_itoa(score, tmp, 10);
    strcat(score_text, tmp);
    score_board.surface =
        TTF_RenderText_Solid(app.font, score_text, score_board.color);
    score_board.texture =
        SDL_CreateTextureFromSurface(app.renderer, score_board.surface);

    return;
}

void ActCheckDeath(void) {
    for (int i = 0; i < NUM_BULLETS; i++) {
        if (CheckCollisionObjects(&player, &bullet[i])) {
            player.health = 0;
            break;
        }
    }

    return;
}

int CheckCollisionWall(Entity *object) {

    if (object->pos.x < 0 || object->pos.x + object->pos.w > SCREEN_WIDTH ||
        object->pos.y < 0 || object->pos.y + object->pos.h > SCREEN_HEIGHT) {
        return 1;
    } else {
        return 0;
    }
}

int CheckCollisionObjects(Entity *object_a, Entity *object_b) {

    if (SDL_HasIntersection(&(object_a->pos), &(object_b->pos))) {
        return 1;
    } else {
        return 0;
    }
}

void RandSpawnBullet(Entity *object) {
    int side = RandInt(0, 4);
    int lhs_width = SCREEN_WIDTH / 8;
    int rhs_width = 7 * (SCREEN_WIDTH / 8);
    int lhs_height = SCREEN_HEIGHT / 8;
    int rhs_height = 7 * (SCREEN_HEIGHT / 8);
    switch (side) {
        case 0:
            object->pos.x = RandInt(0, lhs_width - BULLET_WIDTH);
            object->pos.y = RandInt(0, lhs_height - BULLET_HEIGHT);
            break;
        case 1:
            object->pos.x = RandInt(rhs_width, SCREEN_WIDTH - BULLET_WIDTH);
            object->pos.y = RandInt(0, lhs_height - BULLET_HEIGHT);
            break;
        case 2:
            object->pos.x = RandInt(0, lhs_width - BULLET_WIDTH);
            object->pos.y = RandInt(rhs_height, SCREEN_HEIGHT - BULLET_HEIGHT);
            break;
        case 3:
            object->pos.x = RandInt(rhs_width, SCREEN_WIDTH - BULLET_WIDTH);
            object->pos.y = RandInt(rhs_height, SCREEN_HEIGHT - BULLET_HEIGHT);
            break;
        default:
            break;
    }
    double direction_x = player.pos.x - object->pos.x;
    double direction_y = player.pos.y - object->pos.y;
    double direction = acos(direction_x / sqrt(direction_x * direction_x +
                                               direction_y * direction_y));
    object->theta =
        RandDouble(direction - (M_PI / 10.0), (direction + (M_PI / 10.0)));
    
    return;
}

int RandInt(int min_val, int max_val) {
    if (min_val >= max_val) {
        return 0;
    } else {
        int ranval;
        ranval = rand() % (max_val - min_val);
        ranval += min_val;

        return ranval;
    }
}

double RandDouble(double min_val, double max_val) {

    if (min_val >= max_val) {
        return 0.0;
    } else {
        double ranval;
        ranval = (double)rand() / (double)RAND_MAX;
        ranval = ranval * (max_val - min_val) + min_val;

        return ranval;
    }
}

void GetInput(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                QuitSDL(0);
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
            case SDL_SCANCODE_R:
                app.key_r = 0;
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
            case SDL_SCANCODE_R:
                app.key_r = 1;
                break;
        }
    }

    return;
}