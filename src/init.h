/**
 @file      init.h
 @brief     무한 루프 진입 전 객체 및 SDL 요소 초기화를 위한 함수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/
#ifndef INIT_H
#define INIT_H

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
 @brief 프로그램 수행에 필요한 초기화 과정 수행

 @return 리턴 값 없음
*/
void InitSDL(void);

/**
 @brief TTF폰트 사용을 위한 초기화 과정 수행

 @return 리턴 값 없음
*/
void InitTTF(void);

/**
 @brief 프로그램 종료에 필요한 루틴을 수행하고 프로그램 종료

 @param flag 메인 함수에 넘겨줄 프로그램 리턴값

 @return 리턴 값 없음
*/
void QuitSDL(int flag);

/**
 @brief 연 폰트 파일을 닫고 TTF 엔진 종료

 @return 리턴 값 없음
*/
void QuitTTF(void);

/**
 @brief 모든 전역 변수의 메모리 내용 0으로 초기화

 @return 리턴 값 없음
*/
void InitMemorySet(void);

/**
 @brief 스코어보드 초기화(글씨 색깔, 위치)

 @return 리턴 값 없음
*/
void InitScoreBoard(void);

/**
 @brief 플레이어 초기화 (텍스쳐 불러오기, 위치 설정, 체력 1로 설정)

 @return 리턴 값 없음
*/
void InitPlayer(void);

/**
 @brief 총알 초기화 (텍스쳐 불러오기, 랜덤 위치에 소환,
        총알-주인공 간 각도계산)

 @return 리턴 값 없음
*/
void InitBullet(void);

/**
 @brief 게임오버 화면 초기화 (텍스쳐, 위치)

 @return 리턴 값 없음
*/
void InitGameOver(void);

#endif