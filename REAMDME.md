# 2021학년도 프로그래밍방법론및실습 프로젝트 예제: Dodger (총알피하기) 게임

## 개요

2021학년도 프로그래밍방법론및실습 프로젝트 예제인 총알 피하기 게임이다. SDL2 라이브러리를 이용하여 제작하였으며 SDL2의 기본적인 사용법과 코드 구조를 설명하기 위하여 간단히 제작된 게임이다. 

## 소스코드 구성

### 프로젝트 폴더 구조

```bash
.
├── REAMDME.md
├── doc
│   ├── html
│   └── latex
├── gfx
│   ├── Bullet.png
│   ├── GameOver.png
│   └── Player.png
├── src
│   ├── Doxyfile
│   ├── action.c
│   ├── action.h
│   ├── defs.h
│   ├── draw.c
│   ├── draw.h
│   ├── init.c
│   ├── init.h
│   ├── input.c
│   ├── input.h
│   ├── main.c
│   ├── main.h
│   ├── makefile
│   ├── utils.c
│   └── utils.h
└── ttf
    └── Roboto-Regular.ttf
```

프로젝트 폴더는 위와 같은 트리 구조로 이루어져 있으며 각 폴더 내 파일의 기능은 다음과 같다.

* doc: documentation 저장 폴더
* gfx: 그림 파일 저장 폴더
* src: 소스코드 저장 폴더

### 의존성 라이브러리

프로젝트를 빌드하기 위해 컴파일러 `gcc`, 자동 컴파일을 위한 `make`, 그리고 프로그램 제작을 위해 사용한 `SDL2`라이브러리가 필요하며 터미널에서 아래 스크립트를 이용하여 설치할 수 있다.

```bash
$ sudo apt install gcc make libsdl2*-dev xorg-dev
```

### 소스코드 빌드

소스코드 빌드는 `make`를 이용한다 `src`폴더에 들어간 후 `make` 명령을 사용하면 컴파일이 진행되고 프로젝트 폴더에 `dodger`라는 실행 파일이 생긴다. `dodger`를 실행하면 프로그램이 시작된다. 컴파일 도중 생성된 목적 파일은 `src` 폴더 내에서 `make clean` 명령어를 이용하여 제거할 수 있다.

```bash
$ proj_dir/src$ make
$ proj_dir/src$ ../dodger
```

### 소스코드 매뉴얼

`doc/html/index.html`을 실행하여 소스코드 매뉴얼을 확인할 수 있다. 파일별로 각 구조체 및 함수에 대한 정보를 열람 가능하다.

## 프로그램 구조

본 프로그램은 GUI 프로그램으로 `main()`함수는 무한 루프 안에서 다음 서브루틴을 반복한다. 프로그램은 사용자가 창에 있는 "창닫기 버튼"을 눌러야만 종료된다.

 1. 배경을 모두 지운다 (clear)
 1. 외부 입력(키보드)를 받는다 (input)
 1. 객체들의 다음 상태를 계산한다 (action)
 1. 바뀐 객체들을 화면에 렌더링한다. (draw) 
 1. 렌더링한 결과를 화면에 띄운다 (show)
 1. 정해진 시간 동안 대기한다 (delay)

 각 루틴을 수행하는 함수는 다음과 같다.

 * clear: `ClearWindow()`
 * input: `GetInput()`
 * action: 게임이 진행 중일 땐 `LogicGame()`, 게임오버된 상태에서는 `LogicGameOver()`
 * draw: 게임이 진행 중일 땐 `DrawGame()`, 게임오버된 상태에서는 `DrawGameOver()`
 * show: `ShowWindow()`
 * delay: `SDL_Delay()`

 ## 화면 초기화하기

`ClearWindow()` 함수는 화면을 지정된 색깔(흰색)으로 초기화하여 바로 전 루프에 그려진 내용을 모두 지운다. 