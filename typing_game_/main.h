// main 헤더파일 입니다

#define _CRT_SECURE_NO_WARNINGS

//헤더파일 포함
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <conio.h>

//함수 선언(파일별 구분)
//main.c
int main();

//story.c
void story(int i);
void print_help();
void tmi(int i, int r);

//internal_functions.c
void gotoxy(int x, int y);
void ColorSet(int color_number);
void texts(char text[]);
void read_file();
int get_random_word(int* wordLength, int L);
void print_letter_in_box1(char* s);
void print_letter_in_box2(char* s);
int keyControl();
int ask_next_level();
void CursorView(char show);

//screen_print.c
int first_menu();
void screen();
int second_menu();
void emoticon();
void print_star();
void catchmeifyoucan();
void print_gameover();
void main_screen();
void print_full();
void print_injured();
void print_almost_die();
void ending_credit();
void start_game();

//game_run.c
int game_run();

//life_bar.c
void life_bar(int heart); 

//event_word.c
void event_word(int a, int heart);
//combo.c

//기호상수 선언
#define COLS 120
#define LINES 45
#define COLS_BOX 115
#define LINES_BOX 12
#define WORDNUM 1000 //단어개수
#define EASY 397
#define NORMAL 387
#define HARD 214
#define WORDLEN 15 //단어글자수
#define UP 0
#define DOWN 1
#define SUBMIT 2
#define SPACE_BAR 32
#define CREDIT 200
#define TIMELIMIT_EASY 7
#define TIMELIMIT_NORMAL 6
#define TIMELIMIT_HARD 5

//전역 변수(배열) 선언
char wordBase[WORDNUM][WORDLEN]; //2차원 배열을 생성 
int arrayNum; //랜덤 뽑은 배열의 행
int totalScore; //총 점수
int event; //이벤트 판별 변수

