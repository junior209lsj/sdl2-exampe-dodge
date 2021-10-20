#ifndef INPUT_H
#define INPUT_H

#include "init.h"
#include "defs.h"
#include "utils.h"

extern App app;
extern Entity player;
extern Entity bullet[NUM_BULLETS];
extern Entity game_over;
extern Text score_board;
extern char score_text[BUFSIZE];
extern int score;

void GetInput(void);
void ResponseKeyUp(SDL_KeyboardEvent *event);
void ResponseKeyDown(SDL_KeyboardEvent *event);

#endif