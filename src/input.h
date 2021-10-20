/**
 @file      input.h
 @brief     키보드 입력 발생 시 처리하는 함수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
 */
#ifndef INPUT_H
#define INPUT_H

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
 @brief 외부 입력을 받아 적절한 동작을 취하도록 한다.
 
 @return 리턴 값 없음
*/
void GetInput(void);

/**
 @brief 키보드를 뗐을 때 상태를 기록한다.
 
 @return 리턴 값 없음
*/
void ResponseKeyUp(SDL_KeyboardEvent *event);

/**
 @brief 키보드를 눌렀을 때 상태를 기록한다.
 
 @return 리턴 값 없음
*/
void ResponseKeyDown(SDL_KeyboardEvent *event);

#endif