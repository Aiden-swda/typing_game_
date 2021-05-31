//체력바 구현

void life_bar(int heart) // 목숨값에 따른 체력바
{
	switch (heart)
	{
	case 0:
		gotoxy(110, 3);
		printf("□□□□□\n");
		break;
	case 1:
		gotoxy(110, 3);
		printf("□□□□■\n");
		break;
	case 2:
		gotoxy(110, 3);
		printf("□□□■■\n");
		break;
	case 3:
		gotoxy(110, 3);
		printf("□□■■■\n");
		break;
	case 4:
		gotoxy(110, 3);
		printf("□■■■■\n");
		break;
	case 5:
		gotoxy(110, 3);
		printf("■■■■■\n");
		break;
	}
}