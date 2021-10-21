/*
Copyright (C) Seongjae Lee 2021

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

The author modified 2D Shoot'Em Up Tutorial by Parallel Realities (URL:
https://www.parallelrealities.co.uk/tutorials/) [21 Oct 2021]
*/

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

 배경 내용을 모두 지우고 흰색으로 칠한다. main() 내 무한 루프에서 가장 먼저
 호출한다.

 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Draw
*/
void ClearWindow(void);

/**
 @brief 화면에 렌더링 결과 표시(보여주기)

 \ref Action 과 \ref Draw 모듈에서 수행한 렌더링 결과를 화면에 표시한다.
 
 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Draw
*/
void ShowWindow(void);

/**
 @brief 게임 진행 상태에서 주인공, 총알, 스코어보드 렌더링

 게임 진행 상태시 main()에서 호출하는 함수이다. 게임 진행 상태에서 주인공( \ref
 player ), 총알 ( \ref bullet ), 스코어보드 ( \ref score_board )를 렌더링한다.

 @remark 전역변수 \ref player , \ref bullet , \ref score_board 에 접근한다.

 @return 리턴 값 없음
 @ingroup Draw
*/
void DrawGame(void);

/**
 @brief 게임 오버 상태에서 게임 오버 화면, 최종 스코어 렌더링

 게임 오버 상태시 main()에서 호출하는 함수이다. 게임 오버 상태에서 게임 오버
 화면 ( \ref game_over ), 스코어보드 ( \ref score_board )를 렌더링한다.

 @remark 전역변수 \ref game_over , \ref score_board 에 접근한다.

 @return 리턴 값 없음
 @ingroup Draw
*/
void DrawGameOver(void);

/**
 @brief Entity 구조체 렌더링

 Entity 를 렌더링한다. 대상 Entity 는 적절하게 초기화되어 \ref Entity.texture 와
 \ref Entity.pos 의 위치 (x, y)가 설정되어 있어야 한다.
 SDL_QueryTexture 함수에서는 texture의 정보를 바탕으로 너비와 높이를 자동으로
 계산하여 \ref App.pos 에 반영한다.

 @param[in] object 렌더링 대상 Entity 구조체

 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Draw
*/
void RenderEntity(Entity *object);

/**
 @brief Text 구조체 렌더링 (스코어보드)

 Text 를 렌더링한다. 대상 Text 는 적절하게 초기화되어 \ref Text.texture 와 \ref
 Text.pos 의 위치 (x, y)가 설정되어 있어야 한다.
 SDL_QueryTexture 함수에서는 texture의 정보를 바탕으로 너비와 높이를 자동으로
 계산하여 \ref App.pos 에 반영한다.

 @param[in] object 렌더링 대상 Text 구조체

 @remark 전역변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Draw
*/
void RenderScoreBoard(Text *object);

#endif