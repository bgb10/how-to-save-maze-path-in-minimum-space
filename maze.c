#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
main() : ������ �̷� �����͸� print_maze�� �����մϴ�.
	- ver[], hor[] : �̷��� ���� �����մϴ�.

print_maze() : �̷� �����͸� ������� �̷θ� ����մϴ�.
	- x , y : ����, ���θ� �ǹ��մϴ�.
	- digit_ver, digit_hor : �ڸ����� �����մϴ�.
*/

void print_maze(unsigned short hor[11], unsigned char ver[12]);

int main()
{
		//�̷� �����ʹ� binary�� �����մϴ�. �� �ڸ����� 0�� ���� ����, 1�� ���� ������ ��Ÿ���ϴ�.

    unsigned char ver[12] =  {0b00010001, //binary�� ���� ǥ���� 0b�Դϴ�.
															0b00110011, //�迭�� �� ��� ����Ʈ�� 34����Ʈ�Դϴ�.
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
	print_maze(hor, ver);
	return 0;
}

void print_maze(unsigned short hor[11], unsigned char ver[12])
{
	int x = 0, y = 0;
	int digit_ver, digit_hor;

	printf("+---+---+---+---+---+---+---+---+---+\n"); //�̹� ������ ù ��° ���̹Ƿ� ���ǹ��� ���� �ʽ��ϴ�.

	for (y = 0; y < 12; y++)
	{
		//ver�ڸ�

		printf("|");

		digit_ver = ver[y]; //digit_ver�� �� ���� ������ �Է��մϴ�.

		for (int  x = 0; x < 8; x++)
		{
			digit_ver >>= (7-x); //shift������ �̿��ؼ� �� �ڸ����� ���ڵ�(0,1)�� �����մϴ�.
			digit_ver %= 2;
			if (digit_ver == 1) //�ڸ����� 1�̸� ���� ���� ����մϴ�.
				printf("   |");
			else //digit�� 0�̸� ���� ���� ������� �ʽ��ϴ�.
				printf("    ");

      digit_ver = ver[y];
		}
		printf("   |\n");

		if(y==11) break; //11���� ������ ������ ��µ˴ϴ�. ���� �ݺ����� Ż���մϴ�.

		//hor�ڸ�

		printf("+");

		digit_hor = hor[y]; //digit_hor�� �� ���� ������ �Է��մϴ�.

		for (int x = 0; x < 9; x++)
		{
			digit_hor >>= (8-x); //shift������ �̿��ؼ� �� �ڸ����� ���ڵ�(0,1)�� �����մϴ�.
			digit_hor %= 2;
			if (digit_hor == 1)
				printf("---+"); //�ڸ����� 1�̸� ���� ���� ����մϴ�.
			else
				printf("   +"); //�ڸ����� 0�̸� ���� ���� ������� �ʽ��ϴ�.

      digit_hor = hor[y];
		}
		printf("\n");
	}

	printf("+---+---+---+---+---+---+---+---+---+"); //�̹� ������ ������ ���̹Ƿ� ���ǹ��� ���� �ʽ��ϴ�.

}
