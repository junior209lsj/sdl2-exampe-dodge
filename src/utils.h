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

 Entity 객체가 벽 밖으로 넘어갔는지 판정한다.

 @param[in] object 탐지 대상 Entity형 구조체

 @return 벽 밖으로 넘어가면 1, 벽 안에 있으면 0
 @ingroup Utils
*/
int CheckCollisionWall(Entity *object);

/**
 @brief 두 Entity 간 충돌 여부를 판단

 두 Entity 간 충돌 여부를 판단한다. \ref Entity.pos 는 SDL2 라이브러리에서
 정의한 SDL_Rect 구조체이다. 이 구조체는 멤버 변수로 (x, y)좌표와 (w, h)
 너비/높이 쌍을 가진다. (x, y)는 초기화 과정 또는 \ref Action 모듈에서 루프마다
 계산되며 (w, h)는 \ref Draw 모듈에서 텍스쳐 정보를 바탕으로 계산된다. SDL2에서
 제공하는 SDL_HasIntersection 함수를 이용하여 두 개의 SDL_Rect 구조체에 교집합이
 있는지 판별하는 방법으로 충돌을 계산한다.

 @param[in] object_a 충돌 여부를 판단할 첫 번째 Entity 구조체
 @param[in] object_b 충돌 여부를 판단할 두 번째 Entity 구조체

 @return 충돌했으면 1, 충돌하지 않았으면 0
 @ingroup Utils
*/
int CheckCollisionObjects(Entity *object_a, Entity *object_b);

/**
 @brief 좌상, 좌하, 우상, 우하단 중 랜덤한 위치에 총알 소환 후
        주인공과의 각도 계산

 랜덤한 위치에 총알을 소환한다. 화면 너비를 \f$ W \f$, 화면 높이를 \f$ H \f$
 라고 했을 때, 총알은 지점 1: \f$ ( 0 \le x \le \frac{1}{8} W , 0 \le y \le
 \frac{1}{8} H) \f$, 지점 2: \f$ ( \frac{7}{8} W \le x \le W , 0 \le y \le
 \frac{1}{8} H) \f$, 지점 3: \f$ ( 0 \le x \le \frac{1}{8} W , \frac{7}{8} H \le
 y \le H) \f$, 지점 4: \f$ ( \frac{7}{8} W \le x \le W , \frac{7}{8} H \le y \le
 H) \f$ 중 한 군데에 랜덤 소환된다.

 총알은 소환된 이후 주인공과의 각도를 계산한다. 그리고 \ref Entity.theta 에
 주인공과 총알 사이의 각도 \f$ \pm 18^{\circ} \f$ 을 저장한다. \ref
 Action 모듈에서는 그 방향으로 계속 총알을 움직인다.

 @param[in] object 랜덤 소환할 총알 Entity

 @remark 전역변수 \ref player 에 접근한다.

 @return 리턴 값 없음
 @ingroup Utils
*/
void RandSpawnBullet(Entity *object);

/**
 @brief [min_val, max_val) 사이의 무작위 정수를 리턴

 @param[in] min_val 최솟값
 @param[in] max_val 최댓값

 @return 생성된 무작위 정수
 @ingroup Utils
*/
int RandInt(int min_val, int max_val);

/**
 @brief [min_val, max_val) 사이의 무작위 실수를 리턴

 @param[in] min_val 최솟값
 @param[in] max_val 최댓값

 @return 생성된 무작위 실수
 @ingroup Utils
*/
double RandDouble(double min_val, double max_val);

#endif