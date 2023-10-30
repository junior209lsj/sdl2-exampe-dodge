/*
Copyright (C) Seongjae Lee 2021

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

The author modified 2D Shoot'Em Up Tutorial by Parallel Realities (URL:
https://www.parallelrealities.co.uk/tutorials/) [21 Oct 2021]
*/

/**
 @file      init.c
 @brief     무한 루프 진입 전 객체 및 SDL 요소 초기화를 위한 함수 정의
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#include "init.h"

void InitSDL(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("[ERROR] in InitSDL(): %s", SDL_GetError());
        exit(1);
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
        exit(1);
    }

    app.font = TTF_OpenFont("./ttf/LiberationSans-Regular.ttf", 20);

    return;
}

void QuitSDL(int flag) {
    Mix_FreeChunk(death_effect);
    Mix_FreeMusic(bgm);
    SDL_DestroyTexture(player.texture);
    for (int i = 0; i < NUM_BULLETS; i++) {
        SDL_DestroyTexture(bullet[i].texture);
    }
    SDL_FreeSurface(score_board.surface);
    SDL_DestroyTexture(game_over.texture);
    SDL_DestroyTexture(score_board.texture);
    
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_CloseAudio();

    QuitTTF();
    IMG_Quit();
    SDL_Quit();
    exit(flag);

    return;
}

void QuitTTF(void) {
    TTF_CloseFont(app.font);
    TTF_Quit();

    return;
}

void InitMemorySet(void) {
    memset(&app, 0, sizeof(App));
    memset(&game_over, 0, sizeof(Entity));
    memset(&player, 0, sizeof(Entity));
    memset(&bullet, 0, NUM_BULLETS * sizeof(Entity));
    memset(&score_board, 0, sizeof(Text));

    return;
}

void InitScoreBoard(void) {
    score = 0;
    /* Black */
    score_board.color.r = 0;
    score_board.color.g = 0;
    score_board.color.b = 0;
    score_board.color.a = 255;

    score_board.pos.x = 420;
    score_board.pos.y = 40;

    return;
}

void InitPlayer(void) {
    player.texture = IMG_LoadTexture(app.renderer, "./gfx/Player.png");
    player.pos.x = SCREEN_WIDTH / 2;
    player.pos.y = SCREEN_HEIGHT / 2;
    player.health = 1;
    SDL_QueryTexture(player.texture, NULL, NULL, &(player.pos.w),
                     &(player.pos.h));

    return;
}

void InitBullet(void) {
    for (int i = 0; i < NUM_BULLETS; i++) {
        bullet[i].texture = IMG_LoadTexture(app.renderer, "./gfx/Bullet.png");
        SDL_QueryTexture(bullet[i].texture, NULL, NULL, &(bullet[i].pos.w),
                        &(bullet[i].pos.h));
        RandSpawnBullet(&bullet[i]);
    }

    return;
}

void InitGameOver(void) {
    game_over.texture = IMG_LoadTexture(app.renderer, "./gfx/GameOver.png");
    SDL_QueryTexture(game_over.texture, NULL, NULL, &(game_over.pos.w),
                     &(game_over.pos.h));
    game_over.pos.x = 0;
    game_over.pos.y = 0;
}