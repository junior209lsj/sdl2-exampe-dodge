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
 @file      action.h
 @brief     키보드 입력, 현재 주인공 및 총알의 상태를 바탕으로 액션을 수행
            (상태를 변경)하는 함수 선언
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

 게임이 진행 중인 경우에 수행하는 액션을 모두 모아 순차적으로 실행하는 함수이다.
 main()함수에서 호출한다.

 @return 리턴 값 없음
 @ingroup Action
*/
void LogicGame(void);

/**
 @brief 게임오버된 상태에 필요한 액션을 순차적으로 수행

 게임오버된 경우에 수행하는 액션을 모두 모아 순차적으로 실행하는 함수이다.
 main()함수에서 호출한다.

 @return 리턴 값 없음
 @ingroup Action
 */
void LogicGameOver(void);

/**
 @brief 키보드 입력 상태에 따라 주인공의 액션을 수행. 누른 화살표 버튼에 따라
        움직이고, 화면 밖으로 나갈 수 없음.

 - 위 방향키가 눌린 상태인 경우 위 방향으로 \ref PLAYER_SPEED 만큼 이동한다.
 - 아래 방향키가 눌린 상태인 경우 아래 방향으로 \ref PLAYER_SPEED 만큼 이동한다.
 - 왼쪽 방향키가 눌린 상태인 경우 왼쪽 방향으로 \ref PLAYER_SPEED 만큼 이동한다.
 - 오른쪽 방향키가 눌린 상태인 경우 오른쪽 방향으로 \ref PLAYER_SPEED 만큼 이동한다.

 @remark 전역 변수 \ref app 과 \ref player 에 접근한다.

 @return 리턴 값 없음
 @ingroup Action
*/
void ActPlayer(void);

/**
 @brief 총알의 액션을 수행. 주인공이 있는 방향으로 랜덤하게 날아가고,
        화면 밖으로 나가면 리스폰됨.

 총알은 정해진 방향으로 \ref BULLET_SPEED 만큼 이동한다.
 총알의 이동 방향은 \ref RandSpawnBullet 함수에서 주인공과 총알의 방향  \f$ \pm
 18^{\circ} \f$ 사이로 랜덤하게 결정돠어 \ref Entity.theta 에 저장되어 있다.

 @remark 전역 변수 \ref bullet 에 접근한다.

 @return 리턴 값 없음
 @ingroup Action
*/
void ActBullet(void);

/**
 @brief 스코어보드 문자열 생성 (전역변수 score에 따라 현재 점수 표시)

 "Your Score: [현재 점수]"의 문자열을 만들고 \ref score_board 의 texture에 저장한다.

 @remark 전역 변수 \ref score_board, \ref app, \ref score_text, \ref score 에 접근한다.

 @return 리턴 값 없음
 @ingroup Action
*/
void ActScoreBoard(void);

/**
 @brief 게임 오버 시 최종 스코어 문자열 생성 (전역변수 score에 따라
        최종 점수 표시)

 게임 오버 시 결과창에 띄울 문자열 "Your Final Score: [최종 점수]"을 만들고
 \ref score_board 의 texture에 저장한다.

 @remark 전역 변수 \ref score_board, \ref app, \ref score_text, \ref score 에 접근한다.

 @return 리턴 값 없음
 @ingroup Action
*/
void ActFinalScoreBoard(void);

/**
 @brief 총알과 주인공의 충돌 여부를 계산하고 충돌 시 게임 오버시킴

 모든 총알과 주인공이 충돌했는지 여부를 계산하여 충돌이 발생 시 \ref player의
 health를 0으로 만들어 게임 오버 조건을 만족시킨다. 충돌 여부는 \ref
 CheckCollisionObjects 함수에서 계산한다.

 @remark 전역 변수 \ref bullet , \ref player 에 접근한다.

 @return 리턴 값 없음
 @ingroup Action
*/
void ActCheckDeath(void);

/**
 @brief 게임 오버 화면의 액션 수행. 아무 것도 수행하지 않다가, R키를 누르면 모든
 구조체 초기화

 R키가 눌렸을 시 주인공, 총알, 스코어보드, 게임오버  \ref Entity 를
 초기화시킨다. 이 과정에서 \ref player 의 health가 1로 복구되어 게임이
 재시작된다.

 @remark 전역 변수 \ref app 에 접근한다.

 @return 리턴 값 없음
 @ingroup Action
*/
void ActGameOver(void);

#endif