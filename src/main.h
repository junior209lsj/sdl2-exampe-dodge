/**
 @file      main.h
 @brief     각 모듈 헤더 파일 include 및 전역 변수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
 */
#ifndef MAIN_H
#define MAIN_H

#include "defs.h"

#include "init.h"
#include "input.h"
#include "action.h"
#include "draw.h"

/*사용하는 전역 변수*/
App app;                        /**< 프로그램 전체 단위로 관리하는 전역 객체 모음 */
Entity player;                  /**< 주인공의 속성을 설명하는 Entity형 구조체*/
Entity bullet[NUM_BULLETS];     /**< 총알의 속성을 설명하는 Entity형 구조체*/
Entity game_over;               /**< 게임오버 화면의 속성을 설명하는 Entity형 구조체*/
Text score_board;               /**< 우상단 스코어보드 문자열을 설명하는 Text형 구조체*/
char score_text[BUFSIZE];       /**< 스코어보드에 출력할 문자열*/
int score;                      /**< 게임 스코어*/

#endif