#ifndef ACTION_H
#define ACTION_H

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

void LogicGame(void);
void LogicGameOver(void);
void ActPlayer(void);
void ActBullet(void);
void ActScoreBoard(void);
void ActFinalScoreBoard(void);
void ActCheckDeath(void);
void ActGameOver(void);

#endif