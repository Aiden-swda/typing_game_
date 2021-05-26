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
	screen_s(&story_y);  // screen_s함수로 story_y값 전달 후 조건에 따라 story_y값 변경

	return 0;
}
void print_help() // 도움말 출력
{
	gotoxy(15, 13);
	texts("1. 화면에 나오는 영어단어를 똑같이 따라 입력해주세요. ");
	ColorSet(12);
	texts("빨리 입력");
	ColorSet(7);
	texts("할 수록 더 많은 점수를 얻습니다.");
	gotoxy(15, 14);
	texts("2. 체력이 다 떨어지면 점수와 상관없이 ");
	ColorSet(14);
	texts("게임오버");
	ColorSet(7);
	texts("입니다. 정확히 입력합시다!!");
	gotoxy(15, 15);
	texts("3. 콤보를 쌓으면 ");
	ColorSet(10);
	texts("추가 점수");
	ColorSet(7);
	texts("를 획득하실 수 있습니다. 고득점을 노려보세요!");
	gotoxy(15, 16);
	texts("4. 체력이 떨어지면 일정확률로 ");
	ColorSet(11);
	texts("이벤트 단어");
	ColorSet(7);
	texts("가 출몰합니다. 맞혀서 체력을 회복합시다~");
	gotoxy(15, 17);
	texts("5. 쉬움이나 보통 난이도를 ");
	ColorSet(13);
	texts("클리어");
	ColorSet(7);
	texts("시 자동으로 다음 난이도로 넘어갑니다. 성장한 실력을 보여주세요!");
	gotoxy(15, 19);
	texts("메인화면으로 돌아가고 싶다면 아무 숫자나 입력하세요.");
	int n;
	scanf("%d", &n);
}