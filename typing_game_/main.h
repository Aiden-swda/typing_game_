// main ������� �Դϴ�

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // strcmp �Լ��� ����� ��� ���� - strcmp�Լ��� ���ڿ� ���Լ�

void first();
void gotoxy(int x, int y);
int game_test();
void ColorSet(int color_number);
void screen();
void story();
void screen_s(int*);

#define COLS 120
#define LINES 45
#define COLS_BOX 115
#define LINES_BOX 12
