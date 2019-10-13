#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0 //전처리기는 ; 안붙인다
#include <stdio.h>
#include <string.h>


int main()
{
	//typedef unsigned int size_t;
	char word1[9] = { 0, };
	char word2[9] = { 0, };
	int pos1 = 0, pos2 = 0;
	size_t len1 = 0, len2 = 0;
	int flag = FALSE;
	int i, j;

	printf("Word? ");
	scanf("%s", word1);
	printf("Word? ");
	scanf("%s", word2);

	do
	{
		len1 = strlen(word1);
		len2 = strlen(word2);

		for (i = 0; i < len1; i++)
		{
			for (j = 0; j < len2; j++)
			{
				if (word1[i] == word2[j])
				{
					pos1 = i;
					pos2 = j;
					flag = TRUE;
					break;
				}
			}
			if (flag == TRUE)
			{
				break;
			}
		}

		if (flag == TRUE)
		{
			for (i = 0; i < len1; i++)
			{
				if (pos1 == i)
				{
					printf("(%c)", word1[i]);
				}
				else
				{
					printf("%c", word1[i]);
				}
			}

			printf(" - ");

			for (j = 0; j < len2; j++)
			{
				if (pos2 == j)
				{
					printf("(%c)", word2[j]);
				}
				else
				{
					printf("%c", word2[j]);
				}
			}
		}
		else
		{
			printf("no cross word");
		}

		strcpy(word1, word2);

		printf("\nWord? ");
		scanf("%s", word2);

		flag = FALSE;

	} while (strcmp(word2, "end"));

	return 0;
}
