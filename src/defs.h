/**
 @file      defs.h
 @brief     데이터타입 및 상수 정의
 @author    이성재 (seongjae.lee.1118@gmail.com)
*/

/** 
 @defgroup GlobalVariables

 프로그램에서 사용하는 전역변수에 대해 설명한다.

 @defgroup Init

 Init 모듈은 main()에서 무한 루프가 실행되기 전에 전역 변수들과 SDL 요소들의
 초기화를 수행하는 함수들이 정의되어 있다.

 @defgroup  Input

 Input 모듈은 키보드 입력에 반응하여 \ref app 에 저장된 입력 상태를 저장하는
 변수를 바꾸는 역할을 수행한다.

 @defgroup  Action

 Action 모듈은 키보드 입력 상태, \ref player 와 \ref bullet 의 현재 위치, 그리고
 현재 점수에 따라 Entity 구조체들의 상태를 변화시킨다.

 @defgroup  Draw

 Draw 모듈은 \ref Action 이 수행된 이후 상태가 변경된 \ref player , \ref bullet
 , \ref score_board 를 화면에 렌더링시켜주는 역할을 수행하는 함수들이 정의되어
 있다.

 그리고 \ref ClearWindow 와 \ref ShowWindow 는 각각 main() 내 무한 루프 처음과
 끝에서 화면을 초기화하고 표시해주는 역할을 수행한다.

 @defgroup Utils

 Utils 모듈은 자주 사용하는 계산을 함수 형태로 구현한 모듈이다.


*/

#ifndef DEFS_H
#define DEFS_H

#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

/*상수 매크로 정의*/
#define FPS 60              /**< 게임 FPS*/
#define BUFSIZE 1024        /**< 문자열 버퍼 크기*/

#define SCREEN_WIDTH 640    /**< 화면 너비(픽셀)*/
#define SCREEN_HEIGHT 480   /**< 화면 높이(픽셀)*/

#define PLAYER_WIDTH 24     /**< 플레이어 객체 너비(픽셀)*/
#define PLAYER_HEIGHT 24    /**< 플레이어 객체 높이(픽셀)*/
#define PLAYER_SPEED 4      /**< 플레이어 객체 속도(단위시간당 이동량)*/

#define BULLET_WIDTH 8      /**< 총알 객체 너비(픽셀)*/
#define BULLET_HEIGHT 8     /**< 총알 객체 높이(픽셀)*/
#define BULLET_SPEED 6      /**< 총알 객체 속도(단위시간당 이동량)*/
#define NUM_BULLETS 16      /**< 총알 전체 갯수*/

#define FONTSIZE 20 /**< 출력할 문자열 폰트 크기*/

/*구조체 정의*/
/**
 @brief  App: 프로그램 전체적으로 관리해야 하는 요소를 모아 놓은 구조체
*/
typedef struct {
    SDL_Renderer *renderer; /**< 렌더링 관리를 위한 구조체*/
    SDL_Window *window;     /**< 창 관리를 위한 구조체*/
    TTF_Font *font;         /**< 폰트 관리를 위한 구조체*/
    int key_up;             /**< 위 방향키가 눌린 상태를 저장하는 변수*/
    int key_down;           /**< 아래 방향키가 눌린 상태를 저장하는 변수*/
    int key_left;           /**< 왼쪽 방향키가 눌린 상태를 저장하는 변수*/
    int key_right;          /**< 오른쪽 방향키가 눌린 상태를 저장하는 변수*/
    int key_r;              /**< R키가 눌린 상태를 저장하는 변수*/
} App;

/**
 @brief  Entity: 게임 내에서 움직이는 물체를 구현하기 위한 구조체(주인공, 총알)
*/
typedef struct {
    SDL_Rect pos;           /**< 직사각형 객체의 상태를 나타내기 위한 구조체
                                여기에 객체의 좌표, 위치 저장*/
    double theta;           /**< 총알-주인공 간 각도를 저장하는 변수*/
    int health;             /**< 주인공의 체력 상태를 나타내는 변수 (생존 1, 사망 0)*/
    SDL_Texture *texture;   /**< 텍스쳐를 담고 있는 구조체 (그림파일을 열어
                                 텍스쳐에 저장)*/
} Entity;

/**
 @brief  Text: 게임 내에 문자열을 표시할 경우 문자열을 나타내는 구조체(스코어보드)
*/
typedef struct {
    SDL_Rect pos;           /**< 직사각형 객체의 상태를 나타내기 위한 구조체
                                여기에 객체의 좌표, 위치 저장*/
    SDL_Color color;        /**< 글씨 색깔을 저장하는 구조체*/
    SDL_Surface *surface;   /**< 폰트 렌더링을 위해 필요한 구조체*/
    SDL_Texture *texture;   /**< 텍스쳐를 담고 있는 구조체 (문자열을 surface로 만들고,
                                그 후 texture에 저장)*/
} Text;

#endif