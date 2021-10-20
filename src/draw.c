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