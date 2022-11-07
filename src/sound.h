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

void InitBGM(void);
void PlayBGM(void);

#endif