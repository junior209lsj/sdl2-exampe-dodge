#ifndef DRAW_H
#define DRAW_H

#include "defs.h"
#include "utils.h"

extern App app;
extern Entity player;
extern Entity bullet[NUM_BULLETS];
extern Entity game_over;
extern Text score_board;
extern char score_text[BUFSIZE];
extern int score;

void ClearStage(void);
void ShowStage(void);

void DrawGame(void);
void DrawGameOver(void);
void RenderEntity(Entity *object);
void RenderScoreBoard(Text *object);

#endif