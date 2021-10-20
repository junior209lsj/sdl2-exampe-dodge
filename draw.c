#include "draw.h"

void ClearStage(void) {
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
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