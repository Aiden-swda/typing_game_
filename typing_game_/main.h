// main ������� �Դϴ�

//#define _CRT_SECURE_NO_WARNINGS

//������� ����
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include<conio.h>


//�Լ� ����(���Ϻ� ����)
//main.c
int main();

//story.c
void story();

//internal_functions.c
void gotoxy(int x, int y);
void ColorSet(int color_number);
void texts(char text[]);
void read_file();
int get_random_word(int* wordLength);
void screen_s(int* story_y);
int input_menu();

//screen_print.c
void first();
void screen();
void print_letter(char* s);

//game_run.c
int game_run();
double get_input_check(int *score, int *check);

//void check_answer(int check, int *score, int *heart);
//life_bar.c
void life_bar(int heart); 
//event_word.c

//combo.c

//choice_level.c

//ask_quit.c

//LDM_test_2.c
int test();

//LDM_test_3.c
void show_word();


//��ȣ��� ����
#define COLS 120
#define LINES 45
#define COLS_BOX 115
#define LINES_BOX 12
#define WORDNUM 1000 //�ܾ��
#define WORDLEN 15 //�ܾ���ڼ�

//���� ����(�迭) ����
char wordBase[WORDNUM][WORDLEN]; //2���� �迭�� ���� 
int arrayNum; //���� ���� �迭�� ��
int totalScore; //�� ����


