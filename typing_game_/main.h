// main ������� �Դϴ�

#define _CRT_SECURE_NO_WARNINGS

//������� ����
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // strcmp �Լ��� ����� ��� ���� - strcmp�Լ��� ���ڿ� ���Լ�


//�Լ� ����
void first();
void gotoxy(int x, int y);
int game_run();
void ColorSet(int color_number);
void screen();
void story();
void screen_s(int*);
void read_file();
int get_random_word();


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


