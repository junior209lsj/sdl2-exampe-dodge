#ifndef MAIN_H
#define MAIN_H

#include "defs.h"

#include "init.h"
#include "input.h"
#include "action.h"
#include "draw.h"

App app;
Entity player;
Entity bullet[NUM_BULLETS];
Entity game_over;
Text score_board;
char score_text[BUFSIZE];
int score;

#endif