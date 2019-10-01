// ���� ���� 1. �ٸ� 15�� �̻� 2. ���μ� ���� �ּ� 3�� ���μ� �ʿ� 3. ������ X
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DARI_NUM 18 // ���� �ٸ� ���� (��ٸ� �� �� ���� ��)
#define Y_NUM 16 // �ٸ� ���� ���� ��ġ�� Y�� ���� (X���� ��� �� - 1) 
#define PEOPLE 5 // ��� �� 
#define NUM_MAX 5 // (int)((DARI_NUM - 3) % (PEOPLE - 2)) // ���̻��� 4ĭ �� �� ĭ ���� �� �ִ� ���μ��� �ɸ�����, ���� �� ĭ���� �ּ� 3�� ���μ� ����
#define SERIES_MAX 2 // �ٸ��� ���� �ٿ� �ٴڴٴ� �پ� �ִ� �� ����, �������� ���� �� �Ұ���
#define SERIES_MAX_2 3 // ������ ���� �ִ� �� ����

void mkdari(int **arr); // �������� �ٸ� �����ϴ� �Լ�
void printdari(int **arr); // ��ٸ� ����ϴ� �Լ�
void result(int **arr); // ��ٸ� ��� ����ϰ� ���, �����ϴ� �Լ�
void clean(int **arr); // ���� �� �� �Լ� ���� �� ����� �ٸ� ���� �迭 �ʱ�ȭ�ϴ� �Լ�

int main() {
	int i, j;
	int **dari; // �ٸ� ��� ������ ������ ������ �迭 �����Ҵ翡 �̿�
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
	int select_x, select_y; // ��ٸ� ��ġ�� X, Y��ǥ ������ ����, (0, 0) ~ (Y_NUM - 1, PEOPLE - 2)
	
	for (i = 0; i < DARI_NUM; i++) {
		do {
			do {
				select_x = (rand() % (PEOPLE - 1));
				select_y = (rand() % Y_NUM);
			} while (arr[select_y][select_x] != 0); // �ߺ� ���� (�ٸ� ���� �� 18�� ����)

			if (select_x == 0) { // X��ǥ 0�� ��, ������ �ٸ� ������ ����ϸ� ��
				if (arr[select_y][select_x + 1] != 1) {
					arr[select_y][select_x] = 1;
				}
			}
			else if (select_x == PEOPLE - 2) { // X��ǥ PEOPLE - 2�� ��, ���� �ٸ� ������ ����ϸ� ��
				if (arr[select_y][select_x - 1] != 1) { 
					arr[select_y][select_x] = 1;
				}
			}
			else { // X��ǥ�� ���� ��찡 �ƴ� ��, �� �� ����ؾ� ��
				if ((arr[select_y][select_x + 1] != 1) && (arr[select_y][select_x - 1] != 1)) {
					arr[select_y][select_x] = 1;
				}
			}

			comparison = 0;
			for (j = 0; j < Y_NUM; j++) { // �� �ٸ��� �� �� �ִ� �ִ� ���� �Ǵ�
				if (arr[j][select_x] == 1) {
					comparison++;
				}
			}
			if (comparison > NUM_MAX) {
				arr[select_y][select_x] = 0;
			}

			for (j = 0; j < SERIES_MAX; j++) { // ���Ӽ� �Ǵ� (�ٴڴٴ� �ٸ� �� �� ����)
			// �� �Լ��� ���� �ٴڴٴ� ���� ������ ���� ����
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
			for (j = 0; j < Y_NUM; j++) { // ���Ӽ� �Ǵ� 2 (�ִ� 3�������� ��ó�� �ٸ� �ٸ��� ���� ���� �������� ���� ����)
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
		for (j = 0; j < PEOPLE - 1; j++) { // ���� 0, 1�� ǥ���� �ٸ� ���� ���
			if (arr[i][j] == 0) // �ٸ� ���� �� �Ǿ� ���� �� (== 0)
				printf("|          ");
			else // �ٸ� ����Ǿ� ���� �� (== 1)
				printf("|----------");		
		}
		printf("|\n");
	}
	printf("|          |          |          |          |\n1          2          3          4          5\n\n");
}

void result(int **arr) {
	static int count[PEOPLE][PEOPLE + 1] = { 0 }; // static���� ����, ���� �� �ҷ��� �� �ʱ�ȭ �� �ǵ��� (100�� ��� ����)
	// count[����(���ĺ�)][���(����)], ��� �� ������ �迭���� �� ��� ���� �� ����
	int i, j, temp; // temp�� ��ٸ� �������� ��ġ �����صδ� ����, A�� ���� ���� 0, E�� ���� ���� 4
	for (i = 0; i < PEOPLE; i++) {
		temp = i; // A���� ��ٸ� Ÿ�� ����
		for (j = 0; j < Y_NUM; j++) { // ���ĺ��������� ���� ��������(j), ����(Ȥ�� ����)�� �ٸ� ���� Ȯ��
			if ((arr[j][temp] == 1) && (temp != PEOPLE - 1)) {
				temp++; // temp�� �����ʿ� ��ٸ� ���� �� ĭ ������ �̵�
			}
			else if ((arr[j][temp - 1] == 1) && (temp != 0)) {
				temp--; 
			}
		}
		count[i][temp] = count[i][temp] + 1; // i�� abcde, temp�� 12345 ����
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
			arr[i][j] = 0; // �迭 ��� ĭ �ʱ�ȭ
		}
	}
} 