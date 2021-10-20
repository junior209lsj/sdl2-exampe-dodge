/**
 @file      draw.h
 @brief     텍스쳐 렌더링을 수행하는 함수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#ifndef DRAW_H
#define DRAW_H

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
 @brief 배경을 흰색으로 지정하고 화면에 렌더링된 모든 요소 제거

 @return 리턴 값 없음
*/
void ClearWindow(void);

/**
 @brief 화면에 렌더링 결과 표시(보여주기)

 @return 리턴 값 없음
*/
void ShowWindow(void);

/**
 @brief 게임 진행 상태에서 주인공, 총알, 스코어보드 렌더링

 @return 리턴 값 없음
*/
void DrawGame(void);

/**
 @brief 게임 오버 상태에서 게임 오버 화면, 최종 스코어 렌더링

 @return 리턴 값 없음
*/
void DrawGameOver(void);

/**
 @brief Entity 구조체 렌더링

 @param object 렌더링 대상 Entity 구조체

 @return 리턴 값 없음
*/
void RenderEntity(Entity *object);

/**
 @brief Text 구조체 렌더링 (스코어보드)

 @param object 렌더링 대상 Text 구조체

 @return 리턴 값 없음
*/
void RenderScoreBoard(Text *object);

#endif