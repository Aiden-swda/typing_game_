// main 헤더파일 입니다

#define _CRT_SECURE_NO_WARNINGS

//헤더파일 포함
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

//함수 선언(파일별 구분)
//main.c
int main();
//story.c
void story();
//internal_functions.c
void gotoxy(int x, int y);
void ColorSet(int color_number);
void texts(char text[]);
void read_file();
int get_random_word();
void screen_s(int* story_y);
//screen_print.c
void first();
void screen();
//event_word.c

//combo.c

//choice_level.c

//ask_quit.c



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


