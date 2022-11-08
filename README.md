# 서울시립대학교 기계정보공학과 프로그래밍방법론및실습 프로젝트 예제: Dodger (총알피하기) 게임

## 개요

서울시립대학교 기계정보공학과 프로젝트 예제인 총알 피하기 게임이다. SDL2 라이브러리를 이용하여 제작하였으며 SDL2의 기본적인 사용법과 코드 구조를 설명하기 위하여 간단히 제작된 게임이다. 

## 소스코드 구성

### 프로젝트 폴더 구조

```bash
.
├── REAMDME.md # README
├── LICENSE
├── doc
│   ├── html
├── gfx
│   ├── Bullet.png
│   ├── GameOver.png
│   └── Player.png
├── sound
│   ├── bgm.mp3
│   └── dead.wav
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
│   ├── sound.c
│   └── sound.h
└── ttf
    └── LiberationSans-Regular.ttf
```

프로젝트 폴더는 위와 같은 트리 구조로 이루어져 있으며 각 폴더 내 파일의 기능은 다음과 같다.

* `doc`: documentation 저장 폴더
* `gfx`: 그림 파일 저장 폴더
* `src`: 소스코드 저장 폴더
* `sound`: 음악 파일 저장 폴더
* `ttf`: 폰트 파일 저장 

### 소스파일 개요

src폴더 내에 있는 소스파일은 각각 다음과 같은 내용이 정의/선언되어 있다.

* `action.c`: 키보드 입력, 현재 주인공 및 총알의 상태를 바탕으로 액션을 수행(상태를 변경)하는 함수 정의
* `action.h`: 키보드 입력, 현재 주인공 및 총알의 상태를 바탕으로 액션을 수행(상태를 변경)하는 함수 선언
* `defs.h`: 데이터타입 및 상수 정의
* `draw.c`: 텍스쳐 렌더링을 수행하는 함수 정의
* `draw.h`: 텍스쳐 렌더링을 수행하는 함수 선언
* `init.c`: 무한 루프 진입 전 객체 및 SDL 요소 초기화를 위한 함수 정의
* `init.h`: 무한 루프 진입 전 객체 및 SDL 요소 초기화를 위한 함수 선언
* `input.c`: 키보드 입력 발생 시 처리하는 함수 정의
* `input.h`: 키보드 입력 발생 시 처리하는 함수 선언
* `main.c`: dodger 게임 main 함수를 정의한 소스 파일
* `main.h`: 각 모듈 헤더 파일 include 및 전역 변수 선언
* `makefile`: `make`명령을 실행하기 위한 컴파일 규칙
* `utils.c`: 액션 수행에 필요한 부가적 계산을 수행하는 함수 정의
* `utils.h`: 액션 수행에 필요한 부가적 계산을 수행하는 함수 선언
* `sound.c`: 배경음, 효과음 관련 기능을 수행하는 함수 정의
* `sound.h`: 배경음, 효과음 관련 기능을 수행하는 함수 선언

### 의존성 라이브러리

프로젝트를 빌드하기 위해 컴파일러 `gcc`, 자동 컴파일을 위한 `make`, 그리고 프로그램 제작을 위해 사용한 `SDL2`라이브러리가 필요하며 터미널에서 아래 스크립트를 이용하여 설치할 수 있다.

```bash
$ sudo apt install gcc make libsdl2*-dev xorg-dev
```

### 소스코드 빌드

소스코드 빌드는 `make`를 이용한다 `src`폴더에 들어간 후 `make` 명령을 사용하면 컴파일이 진행되고 프로젝트 폴더에 `dodger`라는 실행 파일이 생긴다. `dodger`를 실행하면 프로그램이 시작된다. 컴파일 도중 생성된 목적 파일은 `src` 폴더 내에서 `make clean` 명령어를 이용하여 제거할 수 있다.

꼭 프로젝트 폴더에서 현재 위치의 `./dodger`를 실행해야 한다.

```bash
$ proj_dir/src$ make
$ proj_dir/src$ cd ..
$ proj_dir$ ./dodger
```

### 소스코드 매뉴얼

`doc/html/index.html`을 실행하여 소스코드 매뉴얼을 확인할 수 있다. 

## 프로그램 구조

본 프로그램은 GUI 프로그램으로 `main()`함수는 무한 루프 안에서 다음 서브루틴을 반복한다. 프로그램은 사용자가 창에 있는 "창닫기 버튼"을 눌러야만 종료된다.

 1. 배경을 모두 지운다 (clear)
 1. 외부 입력(키보드)를 받는다 (input)
 1. 객체들의 다음 상태를 계산한다 (action)
 1. 바뀐 객체들을 화면에 렌더링한다. (draw) 
 1. 렌더링한 결과를 화면에 띄운다 (show)
 1. 정해진 시간 동안 대기한다 (delay)

 ```C
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
 ```

 각 루틴을 수행하는 함수는 다음과 같다.

 * clear: `ClearWindow()`
 * input: `GetInput()`
 * action: 게임이 진행 중일 땐 `ActGame()`, 게임오버된 상태에서는 `ActGameOver()`
 * draw: 게임이 진행 중일 땐 `DrawGame()`, 게임오버된 상태에서는 `DrawGameOver()`
 * show: `ShowWindow()`
 * delay: `SDL_Delay()`
