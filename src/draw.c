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
 @file      draw.c
 @brief     텍스쳐 렌더링을 수행하는 함수 정의
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#include "draw.h"

void ClearWindow(void) {
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
    SDL_RenderClear(app.renderer);

    return;
}

void ShowWindow(void) {
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

void RenderEntity(Entity *object) {

    SDL_QueryTexture(object->texture, NULL, NULL, &(object->pos.w),
                     &(object->pos.h));
    SDL_RenderCopy(app.renderer, object->texture, NULL, &(object->pos));

    return;
}

void RenderScoreBoard(Text *object) {

    SDL_QueryTexture(object->texture, NULL, NULL, &(object->pos.w),
                     &(object->pos.h));
    SDL_RenderCopy(app.renderer, object->texture, NULL, &(object->pos));

    return;
}