// main 헤더파일 입니다

#define _CRT_SECURE_NO_WARNINGS

//헤더파일 포함
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // strcmp 함수가 선언된 헤더 파일 - strcmp함수는 문자열 비교함수


//함수 선언
void first();
void gotoxy(int x, int y);
int game_run();
void ColorSet(int color_number);
void screen();
void story();
void screen_s(int*);
void read_file();
int get_random_word();


//기호상수 선언
#define COLS 120
#define LINES 45
#define COLS_BOX 115
#define LINES_BOX 12
#define WORDNUM 6 //단어개수
#define WORDLEN 20 //단어글자수

//전역 변수(배열) 선언
char wordBase[WORDNUM][WORDLEN]; //2차원 배열을 생성 
int arrayNum; //랜덤 뽑은 배열의 행


