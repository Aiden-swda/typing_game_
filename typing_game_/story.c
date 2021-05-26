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