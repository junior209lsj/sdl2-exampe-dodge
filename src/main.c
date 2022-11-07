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
 @file      main.c
 @brief     dodger 게임 main 함수를 정의한 소스 파일
 @author    이성재 (seongjae.lee.1118@gmail.com)
 */
#include "main.h"

int main(void) {
    int tmpcnt = 0;

    srand(time(NULL));

    /* 1. 초기화 */
    InitMemorySet();
    InitSDL();
    InitTTF();
    InitGameOver();
    InitPlayer();
    InitBullet();
    InitScoreBoard();
    InitSound();
    LoadSound();

    /* BGM은 계속 재생되므로 루프 밖에서 재생 */
    PlayBGM();

    /* 2. 프로그램 무한 루프 */
    for (;;) {
        /* (1) 빈 화면 만들기 */
        ClearWindow();

        /* (2) 키보드 입력 받기*/
        GetInput();

        /* (3) 메인 로직 수행 후 객체들 화면에 그리기 */
        if (player.health) {
            /* 게임 진행 중일 시 */
            ActGame();
            DrawGame();

            if (tmpcnt++ == FPS) {
                score++;
                tmpcnt = 0;
            }
        } else {
            /* 게임 오버일 시 (게임 오버 화면 출력) */
            ActGameOver();
            DrawGameOver();
        }

        /* (4) 화면 보여주기 */
        ShowWindow();

        /* 일정 시간 대기 (60FPS 기준 한 프레임에 16ms) */
        SDL_Delay(16);
    }

    return 0;
}