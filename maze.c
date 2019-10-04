#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
main() : ������ �̷� �����͸� print_maze�� �����մϴ�.
	- ver[], hor[] : �̷��� ���� �����մϴ�.

print_maze() : �̷� �����͸� ������� �̷θ� ����մϴ�.
	- x , y : ����, ���θ� �ǹ��մϴ�.
	- digit_ver, digit_hor : �ڸ����� �����մϴ�.
*/

void print_maze(const unsigned char ver[12], const unsigned char hor[11], const unsigned short hor_end);

int main()
{
	//�̷� �����ʹ� binary�� �����մϴ�. �� �ڸ����� 0�� ���� ����, 1�� ���� ������ ��Ÿ���ϴ�.

	const unsigned char ver[12] = {0b00010001, //binary�� ���� ǥ���� 0b�Դϴ�.
							       0b00110011, //�迭�� �� ��� ����Ʈ�� 23����Ʈ�Դϴ�.
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

	const unsigned short hor_end = 0b00001001000; //�ּ� ����Ʈ�� �ڷ����� ����ϱ� ���� hor�� ������ ��ֹ��� �ٸ� binary�� �����մϴ�.

	print_maze(ver, hor, hor_end);
	return 0;
}

void print_maze(const unsigned char ver[12], const unsigned char hor[11], const unsigned short hor_end)
{
	int x = 0, y = 0;
	int digit_ver, digit_hor, digit_hor_last;
	int last_wall = 1;

	printf("+---+---+---+---+---+---+---+---+---+\n"); //�̹� ������ ù ��° ���̹Ƿ� ���ǹ��� ���� �ʽ��ϴ�.

	for (y = 0; y < 12; y++)
	{
		//ver�ڸ�

		printf("|");

		digit_ver = ver[y]; //digit_ver�� �� ���� ������ �Է��մϴ�.

		for (int x = 0; x < 8; x++)
		{
			digit_ver >>= (7 - x); //shift������ �̿��ؼ� �� �ڸ����� ���ڵ�(0,1)�� �����մϴ�.
			digit_ver %= 2;
			if (digit_ver == 1) //�ڸ����� 1�̸� ���� ���� ����մϴ�.
				printf("   |");
			else //digit�� 0�̸� ���� ���� ������� �ʽ��ϴ�.
				printf("    ");

			digit_ver = ver[y];
		}
		printf("   |\n");

		if (y == 11) break; //11���� ������ ������ ��µ˴ϴ�. ���� �ݺ����� Ż���մϴ�.

		//hor�ڸ�

		printf("+");

		digit_hor = hor[y]; //digit_hor�� �� ���� ������ �Է��մϴ�.

		for (int x = 0; x < 9; x++)
		{
			if (x == 8) //������ ���� ���� ó���մϴ�.
			{
				digit_hor_last = hor_end;
				digit_hor_last >>= (11 - last_wall);
				digit_hor = digit_hor_last;
				
				last_wall++;
			}
			else
			{
				digit_hor >>= (7 - x); //shift������ �̿��ؼ� �� �ڸ����� ���ڵ�(0,1)�� �����մϴ�.
			}
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
