// main ������� �Դϴ�

#define _CRT_SECURE_NO_WARNINGS

//������� ����
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

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
int get_random_word();
void screen_s(int* story_y);
//screen_print.c
void first();
void screen();
//event_word.c

//combo.c

//choice_level.c

//ask_quit.c



//��ȣ��� ����
#define COLS 120
#define LINES 45
#define COLS_BOX 115
#define LINES_BOX 12
#define WORDNUM 6 //�ܾ��
#define WORDLEN 20 //�ܾ���ڼ�

//���� ����(�迭) ����
char wordBase[WORDNUM][WORDLEN]; //2���� �迭�� ���� 
int arrayNum; //���� ���� �迭�� ��


