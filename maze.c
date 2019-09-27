#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_maze(char hor_l[11][9], char ver_l[12][8]);

int main()
{
	char hor[11][9] = { 0, };
	char ver[12][8] = { 0, };

	/*for (int ver_y = 0; ver_y < 12; ver_y++)
	{
		for (int ver_x = 0; ver_x < 8; ver_x++)
		{
			scanf("%d", &ver[ver_y][ver_x]);
		}
	}
	
	for (int hor_y = 0; hor_y < 11; hor_y++)
	{
		for (int hor_x = 0; hor_x < 9; hor_x++)
		{
			scanf("%d", &hor[hor_y][hor_x]);
		}
	}*/

	print_maze(hor, ver);
	return 0;
}

void print_maze(char hor_l[11][9], char ver_l[12][8])
{
	int x = 0, y = 0;

	printf("+---+---+---+---+---+---+---+---+---+\n");

	for (int plus_y = 0; plus_y < 11; plus_y++, y++)
	{
		//ver자리
		printf("|");

		for (int  x = 0; x < 8; x++)
		{
			if (ver_l[y][x] != 0)
				printf("   |");
			else
				printf("    ");
		}
		printf("   |\n");
		
		//hor자리

		printf("|");
		for (int plus_x = 0, x = 0; plus_x < 9; plus_x++, x++)
		{
			if (hor_l[y][x] != 0) //x는 0번부터 9번까지 검사
				printf("---+");
			else
				printf("   +");
		}
		printf("  |\n");
	}
	printf("+---+---+---+---+---+---+---+---+---+");
}