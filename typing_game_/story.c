//스토리는 여기에 구현하기
// 스토리 출력 방식 예시 (내가 더 최적화를 해볼게 아직 미완)
// 실행방식 : 텍스트창 내부로 (x,y)좌표 설정 -> 배열에 텍스트 저장 -> texts함수로 출력조절 -> screen_s함수로 좌표변경 or 텍스트창 초기화

#include "main.h"

void story() 

{
	int story_x = 2;
	int story_y = LINES - 14;

	gotoxy(story_x, story_y);
	char story1[] = "[system : 게임이 시작됩니다.]";  // 배열로 출력할 텍스트 선언
	texts(story1); // texts함수로 텍스트 출력 천천히하기
	Sleep(1000);
	screen_s1(&story_y);  // screen_s함수로 story_y값 전달 후 조건에 따라 story_y값 변경

	return 0;
}
void print_help() // 도움말 출력
{
	gotoxy(7, 7);
	printf("■ 화면에 표시되는 영어단어를 시간 내에 정확히 입력하세요.");
	ColorSet(12);
	printf(" 빠르게 입력할 수록");
	ColorSet(7);
	printf(" 더 많은 점수를 얻습니다.");
	gotoxy(7, 10);
	printf("□ 단어를 제한시간 내에 맞추지 못하거나 틀리면 체력이 소진되며, 체력이 모두 소진될 시 ");
	ColorSet(14);
	printf("게임오버");
	ColorSet(7);
	printf("됩니다.");
	gotoxy(7, 13);
	printf("■ 단어를 연속하여 맞추면 ");
	ColorSet(10);
	printf("Combo");
	ColorSet(7);
	printf("가 쌓이고 ");
	ColorSet(10);
	printf("추가 점수");
	ColorSet(7);
	printf("를 획득하실 수 있습니다.");
	gotoxy(7, 16);
	printf("□ 체력이 떨어지면 색이 있는 ");
	ColorSet(11);
	printf("이벤트 단어");
	ColorSet(7);
	printf("가 생성됩니다. 맞출 시 ");
	ColorSet(11);
	printf("체력");
	ColorSet(7);
	printf("을 회복합니다.");
	gotoxy(7, 19);
	printf("■ 일정 점수를 넘길 시엔 ");
	ColorSet(13);
	printf("클리어");
	ColorSet(7);
	printf("가 되어 자동으로 다음 난이도로 이동합니다. 행운을 빕니다!");
	gotoxy(29, 25);
	printf("[ 메인화면으로 돌아가려면 스페이스바를 누르세요 ]");
	while (1) // 스페이스바 누르면 종료
	{
		char n = _getch();
		if (n == SPACE_BAR)
			break;
	}
}