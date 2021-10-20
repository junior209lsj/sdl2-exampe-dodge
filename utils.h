#ifndef UTILS_H
#define UTILS_H

#include "defs.h"

extern App app;
extern Entity player;
extern Entity bullet[NUM_BULLETS];
extern Entity game_over;
extern Text score_board;
extern char score_text[BUFSIZE];
extern int score;

int CheckCollisionWall(Entity *object);
int CheckCollisionObjects(Entity *object_a, Entity *object_b);
void RandSpawnBullet(Entity *object);
int RandInt(int min_val, int max_val);
double RandDouble(double min_val, double max_val);

#endif