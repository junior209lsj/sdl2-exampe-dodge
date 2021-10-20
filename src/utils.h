/**
 @file      utils.h
 @brief     액션 수행에 필요한 부가적 계산을 수행하는 함수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#ifndef UTILS_H
#define UTILS_H

#include "defs.h"

/* main.h에 정의된 전역 변수 사용 */
extern App app;
extern Entity player;
extern Entity bullet[NUM_BULLETS];
extern Entity game_over;
extern Text score_board;
extern char score_text[BUFSIZE];
extern int score;

/**
 @brief 주인공 혹은 총알이 벽 밖으로 넘어갔는지 확인

 @param object 탐지 대상 Entity형 구조체

 @return 벽 밖으로 넘어가면 1, 벽 안에 있으면 0
*/
int CheckCollisionWall(Entity *object);

/**
 @brief 두 Entity 간 충돌 여부를 판단

 @param object_a 충돌 여부를 판단할 첫 번째 Entity 구조체
 @param object_b 충돌 여부를 판단할 두 번째 Entity 구조체

 @return 충돌했으면 1, 충돌하지 않았으면 0
*/
int CheckCollisionObjects(Entity *object_a, Entity *object_b);

/**
 @brief 좌상, 좌하, 우상, 우하단 중 랜덤한 위치에 총알 소환 후 
        주인공과의 각도 계산

 @param object 랜덤 소환할 총알 Entity

 @return 리턴 값 없음
*/
void RandSpawnBullet(Entity *object);

/**
 @brief [min_val, max_val) 사이의 무작위 정수를 리턴

 @param min_val 최솟값
 @param max_val 최댓값

 @return 생성된 무작위 정수
*/
int RandInt(int min_val, int max_val);

/**
 @brief [min_val, max_val) 사이의 무작위 실수를 리턴

 @param min_val 최솟값
 @param max_val 최댓값

 @return 생성된 무작위 실수
*/
double RandDouble(double min_val, double max_val);

#endif