#include "action.h"

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

void ActGameOver(void) {
    if (app.key_r) {
        InitPlayer();
        InitBullet();
        InitScoreBoard();
    }

    return;
}
