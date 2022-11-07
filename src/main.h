/**
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
 @file      main.h
 @brief     각 모듈 헤더 파일 include 및 전역 변수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
 */

/**
 @mainpage Dodger!

서울시립대 기계정보공학과 프로그래밍방법론및실습 프로젝트 예제인 총알 피하기 게임이다. SDL2
라이브러리를 이용하여 제작하였으며 SDL2의 기본적인 사용법과 코드 구조를 설명하기
위하여 간단히 제작된 게임이다.

 @section main-loop 메인루프 구조

 본 프로그램은 GUI 프로그램으로 `main()`함수는 무한 루프 안에서 다음 서브루틴을 반복한다. 프로그램은 사용자가 창에 있는 "창닫기 버튼"을 눌러야만 종료된다.

 1. 배경을 모두 지운다 (clear)
 2. 외부 입력(키보드)를 받는다 (input)
 3. 객체들의 다음 상태를 계산한다 (action)
 4. 바뀐 객체들을 화면에 렌더링한다. (draw) 
 5. 렌더링한 결과를 화면에 띄운다 (show)
 6. 정해진 시간 동안 대기한다 (delay)

 @section modules 모듈 설명

 본 매뉴얼에는 메인 함수 무한루프에 들어가는 각 서브루틴별로 사용되는 함수를
분리하여 \ref Modules 절에서 설명한다.

 - \ref Init : 무한루프 진입 전 초기화
 - \ref Input : 키보드 입력에 대한 응답
 - \ref Action : 주인공과 총알, 그리고 점수판의 변화를 계산하고 변경
 - \ref Draw : 실제 오브젝트들을 화면에 보여주기 위한 기능
 - \ref Utils : 많이 사용하는 기능을 함수로 구현
 - \ref Sound : 배경음 및 효과음 기능을 구현

 @section globals 전역변수 사용

 본 프로그램은 간단한 프로그램의 구현을 위해 키 입력과 SDL 창 관련 객체 ( \ref
app ) 주인공 ( \ref player ), 총알 ( \ref bullet ), 점수판 ( \ref score_board ),
점수판에 표시할 텍스트 ( \ref score_text ), 점수 ( \ref score )를 전역변수로
지정하여 사용한다. 각 전역변수 내용에 대한 설명은 \ref GlobalVariables 에서 볼
수 있다.
*/

#ifndef MAIN_H
#define MAIN_H

#include "defs.h"

#include "init.h"
#include "input.h"
#include "action.h"
#include "draw.h"
#include "sound.h"

/*사용하는 전역 변수*/
/// @ingroup GlobalVariables
App app;                        /**< 프로그램 전체 단위로 관리하는 전역 객체 모음 */
/// @ingroup GlobalVariables
Entity player;                  /**< 주인공의 속성을 설명하는 Entity형 구조체*/
/// @ingroup GlobalVariables
Entity bullet[NUM_BULLETS];     /**< 총알의 속성을 설명하는 Entity형 구조체*/
/// @ingroup GlobalVariables
Entity game_over;               /**< 게임오버 화면의 속성을 설명하는 Entity형 구조체*/
/// @ingroup GlobalVariables
Text score_board;               /**< 우상단 스코어보드 문자열을 설명하는 Text형 구조체*/
/// @ingroup GlobalVariables
char score_text[BUFSIZE];       /**< 스코어보드에 출력할 문자열*/
/// @ingroup GlobalVariables
int score;                      /**< 게임 스코어*/
/// @ingroup GlobalVariables
Mix_Music *bgm;                 /**< 배경음악*/
/// @ingroup GlobalVariables
Mix_Chunk *death_effect;         /**< 주인공 사망시 효과음*/

#endif