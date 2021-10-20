/**
 @file      action.h
 @brief     키보드 입력, 현재 주인공 및 총알의 상태를 바탕으로 액션을 수행하는
            함수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#ifndef ACTION_H
#define ACTION_H

#include "init.h"
#include "defs.h"
#include "utils.h"

/* main.h에 정의된 전역 변수 사용 */
extern App app;
extern Entity player;
extern Entity bullet[NUM_BULLETS];
extern Entity game_over;
extern Text score_board;
extern char score_text[BUFSIZE];
extern int score;

/**
 @brief 게임 진행 중일 시 필요한 액션을 순차적으로 수행

 @return 리턴 값 없음
*/
void LogicGame(void);

/**
 @brief 게임오버된 상태에 필요한 액션을 순차적으로 수행

 @return 리턴 값 없음
 */
void LogicGameOver(void);

/**
 @brief 키보드 입력 상태에 따라 주인공의 액션을 수행. 누른 화살표 버튼에 따라
        움직이고, 화면 밖으로 나갈 수 없음.

 @return 리턴 값 없음
*/
void ActPlayer(void);

/**
 @brief 총알의 액션을 수행. 주인공이 있는 방향으로 랜덤하게 날아가고,
        화면 밖으로 나가면 리스폰됨.

 @return 리턴 값 없음
*/
void ActBullet(void);

/**
 @brief 스코어보드 문자열 생성 (전역변수 score에 따라 현재 점수 표시)

 @return 리턴 값 없음
*/
void ActScoreBoard(void);

/**
 @brief 게임 오버 시 최종 스코어 문자열 생성 (전역변수 score에 따라
        최종 점수 표시)

 @return 리턴 값 없음
*/
void ActFinalScoreBoard(void);

/**
 @brief 총알과 주인공의 충돌 여부를 계산하고 충돌 시 게임 오버시킴

 @return 리턴 값 없음
*/
void ActCheckDeath(void);

/**
 @brief 게임 오버 화면의 액션 수행. 아무 것도 수행하지 않다가, R키를 누르면 모든
 구조체 초기화

 @return 리턴 값 없음
*/
void ActGameOver(void);

#endif