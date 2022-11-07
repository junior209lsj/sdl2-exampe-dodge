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
 @file      sound.h
 @brief     배경음, 효과음 관련 함수 선언
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/

#ifndef SOUND_H
#define SOUND_H

#include "defs.h"

extern Mix_Music *bgm;
extern Mix_Chunk *death_effect;

/**
 @brief SDL Mixer 모듈 초기화

 사운드 재생에 필요한 초기화 작업 진행.

 @return 리턴 값 없음
 @ingroup Sound
*/
void InitSound(void);


/**
 @brief 사운드 파일 불러오기

 배경음 및 효과음 파일을 불러와서 전역 변수 \ref bgm , \ref death_effect 에 할당

 @return 리턴 값 없음
 @ingroup Sound
*/
void LoadSound(void);

/**
 @brief BGM 재생

 BGM 재생(무한 반복)

 @return 리턴 값 없음
 @ingroup Sound
*/
void PlayBGM(void);

/**
 @brief 사망시 효과음 재생

 사망시 효과음 재생(1회 반복)

 @return 리턴 값 없음
 @ingroup Sound
*/
void PlayDeathEffect(void);

#endif