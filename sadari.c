// 과제 조건 1. 다리 15개 이상 2. 세로선 사이 최소 3개 가로선 필요 3. 몰리면 X
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DARI_NUM 18 // 놓을 다리 개수 (사다리 한 번 만들 때)
#define Y_NUM 16 // 다리 생성 가능 위치의 Y축 길이 (X축은 사람 수 - 1) 
#define PEOPLE 5 // 사람 수 
#define NUM_MAX 5 // (int)((DARI_NUM - 3) % (PEOPLE - 2)) // 사이사이 4칸 중 한 칸 빼고 다 최대 가로선이 걸리더라도, 남은 한 칸에게 최소 3개 가로선 보장
#define SERIES_MAX 2 // 다리가 같은 줄에 다닥다닥 붙어 있는 일 방지, 연속으로 오는 것 불가능
#define SERIES_MAX_2 3 // 경향이 몰려 있는 것 방지

void mkdari(int **arr); // 랜덤으로 다리 생성하는 함수
void printdari(int **arr); // 사다리 출력하는 함수
void result(int **arr); // 사다리 결과 계산하고 출력, 저장하는 함수
void clean(int **arr); // 위의 세 개 함수 돌릴 때 사용한 다리 저장 배열 초기화하는 함수

int main() {
	int i, j;
	int **dari; // 다리 어디에 놓을지 저장할 이차원 배열 동적할당에 이용
	srand(time(NULL)); 

	dari = (int**)calloc(sizeof(int*), Y_NUM);
	for (i = 0; i < Y_NUM; i++) {
		dari[i] = (int*)calloc(sizeof(int), PEOPLE - 1);
	} // == dari[Y_NUM][PEOPLE - 1]
	
	for (i = 0; i < 100; i++) {
		mkdari(dari);
		printdari(dari);
		result(dari);
		clean(dari);
	} 

	system("pause");
	for(i = 0; i < Y_NUM; i++) {
		free(dari[i]); 
	}
	free(dari);
	return 0;
}

void mkdari(int **arr) {
	int i, j, k, comparison;
	int select_x, select_y; // 사다리 위치의 X, Y좌표 저장할 변수, (0, 0) ~ (Y_NUM - 1, PEOPLE - 2)
	
	for (i = 0; i < DARI_NUM; i++) {
		do {
			do {
				select_x = (rand() % (PEOPLE - 1));
				select_y = (rand() % Y_NUM);
			} while (arr[select_y][select_x] != 0); // 중복 방지 (다리 개수 늘 18개 유지)

			if (select_x == 0) { // X좌표 0일 때, 오른쪽 다리 유무만 고려하면 됨
				if (arr[select_y][select_x + 1] != 1) {
					arr[select_y][select_x] = 1;
				}
			}
			else if (select_x == PEOPLE - 2) { // X좌표 PEOPLE - 2일 때, 왼쪽 다리 유무만 고려하면 됨
				if (arr[select_y][select_x - 1] != 1) { 
					arr[select_y][select_x] = 1;
				}
			}
			else { // X좌표가 위의 경우가 아닐 때, 둘 다 고려해야 함
				if ((arr[select_y][select_x + 1] != 1) && (arr[select_y][select_x - 1] != 1)) {
					arr[select_y][select_x] = 1;
				}
			}

			comparison = 0;
			for (j = 0; j < Y_NUM; j++) { // 한 다리에 올 수 있는 최대 개수 판단
				if (arr[j][select_x] == 1) {
					comparison++;
				}
			}
			if (comparison > NUM_MAX) {
				arr[select_y][select_x] = 0;
			}

			for (j = 0; j < SERIES_MAX; j++) { // 연속성 판단 (다닥다닥 다리 올 수 없음)
			// 이 함수를 통해 다닥다닥 오는 개수를 변경 가능
				comparison = 0;
				if ((select_y - (SERIES_MAX - 1) + j >= 0) && (select_y + j < Y_NUM)) {
					for (k = j; k < j + SERIES_MAX; k++) {
						if (arr[select_y - (SERIES_MAX - 1) + k][select_x] == 1) {
							comparison++;
						} 	
					}
					if (comparison == SERIES_MAX) {
						arr[select_y][select_x] = 0;
						break;
					}
				}
			}

			comparison = 0; 
			for (j = 0; j < Y_NUM; j++) { // 연속성 판단 2 (최대 3개까지만 근처에 다른 다리들 없이 나름 연속으로 존재 가능)
				if (arr[j][select_x] == 1) {
					for (k = j; k < Y_NUM; k++){
						
						if (arr[k][select_x] == 1) {
							comparison++;
						}
						else if (((select_x != 0) && (arr[k][select_x - 1] == 1)) 
							|| ((select_x != PEOPLE - 2) && (arr[k][select_x + 1] == 1))) {
							comparison = 0;
						}
						if (comparison > SERIES_MAX_2) { 
							arr[select_y][select_x] = 0;
							break;
						}
					}
					break;
				}			
			} 
		} while (arr[select_y][select_x] == 0);
	}
}

void printdari(int **arr) {
	int i, j;
	printf("A          B          C          D          E\n|          |          |          |          |\n"); 
	for (i = 0; i < Y_NUM; i++) {
		for (j = 0; j < PEOPLE - 1; j++) { // 위에 0, 1로 표시한 다리 유무 출력
			if (arr[i][j] == 0) // 다리 저장 안 되어 있을 때 (== 0)
				printf("|          ");
			else // 다리 저장되어 있을 때 (== 1)
				printf("|----------");		
		}
		printf("|\n");
	}
	printf("|          |          |          |          |\n1          2          3          4          5\n\n");
}

void result(int **arr) {
	static int count[PEOPLE][PEOPLE + 1] = { 0 }; // static으로 저장, 여러 번 불러도 값 초기화 안 되도록 (100번 통계 위함)
	// count[시작(알파벳)][결과(숫자)], 결과 쪽 마지막 배열에는 각 결과 더한 값 저장
	int i, j, temp; // temp는 사다리 내려가며 위치 저장해두는 변수, A와 같은 줄이 0, E와 같은 줄이 4
	for (i = 0; i < PEOPLE; i++) {
		temp = i; // A부터 사다리 타기 시작
		for (j = 0; j < Y_NUM; j++) { // 알파벳에서부터 점점 내려오며(j), 양쪽(혹은 한쪽)의 다리 유무 확인
			if ((arr[j][temp] == 1) && (temp != PEOPLE - 1)) {
				temp++; // temp의 오른쪽에 사다리 있음 한 칸 오른쪽 이동
			}
			else if ((arr[j][temp - 1] == 1) && (temp != 0)) {
				temp--; 
			}
		}
		count[i][temp] = count[i][temp] + 1; // i는 abcde, temp는 12345 결정
	}
	for (i = 0; i < PEOPLE; i++) {
		printf("%d : ", i + 1);
		for(j = 0; j < PEOPLE; j++){
			printf("%c(%d) ", 'A' + j, count[j][i]);
		}
		count[i][PEOPLE]++;
		printf("\t: %d\n", count[i][PEOPLE]);
	}
	printf("\n"); 
}

void clean(int **arr) {
	int i, j;
	for (i = 0; i < Y_NUM; i++) {
		for (j = 0; j < PEOPLE - 1; j++) {
			arr[i][j] = 0; // 배열 모든 칸 초기화
		}
	}
} 