//ü�¹� ����
#include "main.h"

void life_bar(int heart) // ������� ���� ü�¹�
{
	switch (heart)
	{
	case 0:
		gotoxy(96, 4);
		ColorSet(4);
		printf("������");
		ColorSet(7);
		story(18);
		break;
	case 1:
		gotoxy(96, 4);
		ColorSet(4);
		printf("������");
		ColorSet(7);
		story(17);
		print_almost_die();
		break;
	case 2:
		gotoxy(96, 4);
		ColorSet(12);
		printf("������");
		ColorSet(7);
		print_injured();
		break;
	case 3:
		gotoxy(96, 4);
		ColorSet(12);
		printf("������");
		ColorSet(7);
		print_injured();
		break;
	case 4:
		gotoxy(96, 4);
		ColorSet(12);
		printf("������");
		ColorSet(7);
		print_full();
		break;
	case 5:
		gotoxy(96, 4);
		ColorSet(12);
		printf("������");
		print_full();
		break;
	}
}