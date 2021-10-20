#ifndef INIT_H
#define INIT_H

#include "defs.h"
#include "utils.h"

extern App app;
extern Entity player;
extern Entity bullet[NUM_BULLETS];
extern Entity game_over;
extern Text score_board;
extern char score_text[BUFSIZE];
extern int score;

void InitSDL(void);
void InitTTF(void);
void QuitSDL(int flag);
void QuitTTF(void);

void InitMemorySet(void);
void InitScoreBoard(void);
void InitPlayer(void);
void InitBullet(void);
void InitGameOver(void);

#endif