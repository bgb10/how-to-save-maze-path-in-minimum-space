#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_maze(char hor_l[], char ver_l[]);

/*
binary는 0b로 쓴다. shifting 연산 사용?? 
매 줄마다 그냥 0b형태로 데이터 저장한 후에 2진수 단위마다 수들을 가져와서 1이면 출력하면 된다.
데이터 범위는 0 ~ 등비급수 이용해서 나온 값
하지만 쪼개다보면 뭐 바이트 수를 더 줄일 수 있지만, 효율적이지는 않다.
1. shift연산을 사용해서 자릿수를 다 내려버리는 형태로?
2. 나머지연산을 array에 받아서(그럼 반대모양의 array가 나오겠지) 출력 
*/
int main()
{
	unsigned short hor[11] = {0b011011000, 
							  0b110001000,
							  0b010110100,
							  0b001001010,
							  0b000011101,
							  0b010011110,
							  0b111001100,
							  0b001100111,
							  0b011011010,
							  0b010000100,
							  0b100000110};
	
	char ver[12] = 			 {0b00010001, 
							  0b00110011,
							  0b00101011,
							  0b11111101,
							  0b11010010,
							  0b01100001,
							  0b00110010,
							  0b10011001,
							  0b00101001,
							  0b01110001,
							  0b01010100};

	print_maze(hor, ver);
	return 0;
}

void print_maze(char hor, char ver)
{
	int x = 0, y = 0;
	int digit_ver, digit_hor;

	printf("+---+---+---+---+---+---+---+---+---+\n");

	for (y = 0; y < 11; y++)
	{
		//ver자리
		printf("|");

		digit_ver = ver[y];

		for (int  x = 0; x < 8; x++)
		{
			for(int shift = 8; shift > 0; shift--)
			{
				digit_ver /= 2;
			}
			digit_ver %= 2;
			if (digit_ver == 1) //digit이 1이면
				printf("   |");
			else //digit이 0이면
				printf("    ");

		}
		printf("   |\n");
		
		//hor자리

		printf("+");

		digit_hor = hor[y];

		for (int x = 0; x < 9; x++)
		{
			for(int shift = 9; shift > 0; shift--)
			{
				digit_hor /= 2;
			}
			digit_hor %= 2;

			if (digit_hor == 1)
				printf("---+");
			else
				printf("   +");

		}
		printf("\n");
	}
	
	//ver11줄
	printf("|");

	digit_ver = ver[11];

	for (int x = 0; x < 8; x++)
	{
		for(int shift = 8; shift > 0; shift--)
			{
				digit_ver /= 2;
			}
			digit_ver %= 2;
			if (digit_ver == 1) //digit이 1이면
				printf("   |");
			else //digit이 0이면
				printf("    ");
	}
	
	printf("   |\n");
	printf("+---+---+---+---+---+---+---+---+---+");
}