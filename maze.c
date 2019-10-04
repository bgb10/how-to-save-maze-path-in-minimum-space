#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
main() : 저장한 미로 데이터를 print_maze에 전달합니다.
	- ver[], hor[] : 미로의 벽을 저장합니다.

print_maze() : 미로 데이터를 기반으로 미로를 출력합니다.
	- x , y : 가로, 세로를 의미합니다.
	- digit_ver, digit_hor : 자릿수를 저장합니다.
*/

void print_maze(const unsigned char ver[12], const unsigned char hor[11], const unsigned short hor_end);

int main()
{
	//미로 데이터는 binary로 저장합니다. 각 자리수의 0은 벽이 없음, 1은 벽이 있음을 나타냅니다.

	const unsigned char ver[12] = {0b00010001, //binary의 저장 표현은 0b입니다.
							       0b00110011, //배열의 총 사용 바이트는 23바이트입니다.
							       0b00101011,
								   0b11111101,
								   0b11010010,
								   0b01100001,
								   0b00110010,
								   0b10011001,
								   0b10001000,
								   0b00101011,
								   0b01111001,
								   0b01010100};

	const unsigned char hor[11] = {0b01101100,
								   0b11000100,
								   0b01011010,
								   0b00100101,
								   0b00001110,
								   0b01001111,
								   0b11100110,
								   0b00110011,
								   0b01101101,
								   0b01000010,
								   0b10000011};

	const unsigned short hor_end = 0b00001001000; //최소 바이트의 자료형을 사용하기 위해 hor의 마지막 장애물은 다른 binary로 저장합니다.

	print_maze(ver, hor, hor_end);
	return 0;
}

void print_maze(const unsigned char ver[12], const unsigned char hor[11], const unsigned short hor_end)
{
	int x = 0, y = 0;
	int digit_ver, digit_hor, digit_hor_last;
	int last_wall = 1;

	printf("+---+---+---+---+---+---+---+---+---+\n"); //이미 정해진 첫 번째 줄이므로 조건문을 두지 않습니다.

	for (y = 0; y < 12; y++)
	{
		//ver자리

		printf("|");

		digit_ver = ver[y]; //digit_ver에 각 줄의 정보를 입력합니다.

		for (int x = 0; x < 8; x++)
		{
			digit_ver >>= (7 - x); //shift연산을 이용해서 각 자리수의 숫자들(0,1)을 구분합니다.
			digit_ver %= 2;
			if (digit_ver == 1) //자리수가 1이면 세로 벽을 출력합니다.
				printf("   |");
			else //digit이 0이면 세로 벽을 출력하지 않습니다.
				printf("    ");

			digit_ver = ver[y];
		}
		printf("   |\n");

		if (y == 11) break; //11줄은 세로줄 까지만 출력됩니다. 따라서 반복문을 탈출합니다.

		//hor자리

		printf("+");

		digit_hor = hor[y]; //digit_hor에 각 줄의 정보를 입력합니다.

		for (int x = 0; x < 9; x++)
		{
			if (x == 8) //마지막 줄은 따로 처리합니다.
			{
				digit_hor_last = hor_end;
				digit_hor_last >>= (11 - last_wall);
				digit_hor = digit_hor_last;
				
				last_wall++;
			}
			else
			{
				digit_hor >>= (7 - x); //shift연산을 이용해서 각 자리수의 숫자들(0,1)을 구분합니다.
			}
			digit_hor %= 2;
			if (digit_hor == 1)
				printf("---+"); //자리수가 1이면 가로 벽을 출력합니다.
			else
				printf("   +"); //자리수가 0이면 가로 벽을 출력하지 않습니다.

			digit_hor = hor[y];
		}
		printf("\n");
	}

	printf("+---+---+---+---+---+---+---+---+---+"); //이미 정해진 마지막 줄이므로 조건문을 두지 않습니다.

}
