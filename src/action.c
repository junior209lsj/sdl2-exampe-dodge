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
 @file      action.c
 @brief     키보드 입력, 현재 주인공 및 총알의 상태를 바탕으로 액션을 수행
            (상태를 변경)하는 함수 정의
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#include "action.h"

void ActGame(void) {
    ActPlayer();
    ActBullet();
    ActScoreBoard();
    ActCheckDeath();

    return;
}

void ActGameOver(void) {
    ActFinalScoreBoard();
    ActGameOverScreen();

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

void ActGameOverScreen(void) {
    if (app.key_r) {
        InitPlayer();
        InitBullet();
        InitScoreBoard();
        InitGameOver();
    }

    return;
}
