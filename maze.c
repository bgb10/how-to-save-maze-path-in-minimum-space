#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_maze(char hor_l[], char ver_l[]);

/*
binary�� 0b�� ����. shifting ���� ���?? 
�� �ٸ��� �׳� 0b���·� ������ ������ �Ŀ� 2���� �������� ������ �����ͼ� 1�̸� ����ϸ� �ȴ�.
������ ������ 0 ~ ���޼� �̿��ؼ� ���� ��
������ �ɰ��ٺ��� �� ����Ʈ ���� �� ���� �� ������, ȿ���������� �ʴ�.
1. shift������ ����ؼ� �ڸ����� �� ���������� ���·�?
2. ������������ array�� �޾Ƽ�(�׷� �ݴ����� array�� ��������) ��� 
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
		//ver�ڸ�
		printf("|");

		digit_ver = ver[y];

		for (int  x = 0; x < 8; x++)
		{
			for(int shift = 8; shift > 0; shift--)
			{
				digit_ver /= 2;
			}
			digit_ver %= 2;
			if (digit_ver == 1) //digit�� 1�̸�
				printf("   |");
			else //digit�� 0�̸�
				printf("    ");

		}
		printf("   |\n");
		
		//hor�ڸ�

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
	
	//ver11��
	printf("|");

	digit_ver = ver[11];

	for (int x = 0; x < 8; x++)
	{
		for(int shift = 8; shift > 0; shift--)
			{
				digit_ver /= 2;
			}
			digit_ver %= 2;
			if (digit_ver == 1) //digit�� 1�̸�
				printf("   |");
			else //digit�� 0�̸�
				printf("    ");
	}
	
	printf("   |\n");
	printf("+---+---+---+---+---+---+---+---+---+");
}