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

 SDL 초기화 과정을 수행한다. 또한 .png와 .jpg 파일을 사용하기 위한 작업도 수행한다.

 @exception 초기화 실패 시 에러를 콘솔에 출력한다.
 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void InitSDL(void);

/**
 @brief TTF폰트 사용을 위한 초기화 과정 수행

 TTF폰트 초기화 과정을 수행한다.

 @exception 초기화 실패 시 에러를 콘솔에 출력하고 프로그램을 종료한다.
 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void InitTTF(void);

/**
 @brief 프로그램 종료에 필요한 루틴을 수행하고 프로그램 종료

 프로그램 종료 전 전역변수 \ref app 의 \ref App.renderer 와 \ref App.window 를
 닫고 프로그램을 종료한다.

 @param[in] flag 메인 함수에 넘겨줄 프로그램 리턴값

 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void QuitSDL(int flag);

/**
 @brief 연 폰트 파일을 닫고 TTF 엔진 종료

 \ref app 의 \ref App.font 를 닫고 TTF 엔진을 종료한다.

 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void QuitTTF(void);

/**
 @brief 전역 변수 메모리 내용 초기화

 모든 전역 변수의 메모리 내용을 0으로 초기화한다.

 @remark 초기화 대상: \ref app , \ref game_over \ref player , \ref bullet , \ref
 score_board .

 @return 리턴 값 없음
 @ingroup Init
*/
void InitMemorySet(void);

/**
 @brief 스코어보드 초기화

 \ref score_board 의 글씨 색상과 위치를 초기화한다. 글씨 색상은 검정색, 위치는
 (420, 40) 으로 설정한다.
 각 객체의 너비와 높이는 텍스쳐 정보를 바탕으로 \ref Draw 모듈의 함수에서 일괄
 계산하여 반영하므로 별도로 설정하지 않는다.

 @remark 전역변수 \ref score_board 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void InitScoreBoard(void);

/**
 @brief 플레이어 초기화

 \ref player 의 텍스쳐를 불러오고 위치를 초기화하고 체력을 1로 초기화한다.
 텍스쳐는 gfx/Player.png를 사용하고 위치는 화면의 중앙점으로 한다.
 각 객체의 너비와 높이는 텍스쳐 정보를 바탕으로 \ref Draw 모듈의 함수에서 일괄
 계산하여 반영하므로 별도로 설정하지 않는다.

 @remark 전역변수 \ref app 과 \ref player 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void InitPlayer(void);

/**
 @brief 총알 초기화

 \ref bullet 의 텍스쳐를 불러오고 랜덤한 장소로 위치를 설정하고 \ref player 와의
 각도를 계산한다. 텍스쳐는 gfx/Bullet.png를 사용한다.
 각 객체의 너비와 높이는 텍스쳐 정보를 바탕으로 \ref Draw 모듈의 함수에서 일괄
 계산하여 반영하므로 별도로 설정하지 않는다.

 @remark 전역변수 \ref bullet , \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void InitBullet(void);

/**
 @brief 게임오버 화면 초기화 (텍스쳐, 위치)

 \ref game_over 의 텍스쳐를 불러온다. \ref game_over 의 텍스쳐는 화면 전체
 크기와 동일하므로 위치는 (0, 0)으로 설정한다.
 각 객체의 너비와 높이는 텍스쳐 정보를 바탕으로 \ref Draw 모듈의 함수에서 일괄
 계산하여 반영하므로 별도로 설정하지 않는다.

 @remark 전역변수 \ref game_over , \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Init
*/
void InitGameOver(void);

#endif