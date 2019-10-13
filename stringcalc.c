#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b));
#define LENGTH 42

void sum(char *X, char *Y, int opt, int wBig, int len_X, int len_Y);
void subtraction(char *X, char *Y, int opt, int wBig, int len_X, int len_Y);
void multiply(char *X, char *Y, int opt, int wBig, int len_X, int len_Y); //���ϱ� ��������. + ��ȣ�߰� ��Ź(��ȣ ��� ����)

int arrange(char * s1, char * s2, int len_X, int len_Y);

void make_integer(char *X, char *Y);
int isBig(char *X, char *Y);
void swap(char *X, char *Y);

int main()
{
	char X[42] = { 0, }; //�� 0���� ���־��.
	char Y[42] = { 0, };
	char output[81] = { 0, }; //���� 0���� �ϰ�, 0�� �ȳ����� �������� ����ϸ� �ȴ�.


	int len_X, len_Y;
	int opt;
	int wBig;

	printf("input X. ");
	scanf("%s", X); //���ڿ��� �ޱ�
	printf("input Y. ");
	scanf("%s", Y); //���ڿ��� �ޱ�

	len_X = strlen(X);
	len_Y = strlen(Y);
	//len_max�� +1�ؾ� �� �����ش�.

	opt = arrange(X, Y, len_X, len_Y); //���ʿ� ��ȣ �κа� �� �κ��� ������ ����. ��ȣ�� ���� opt(��ȣ�ɼ�)�� ���, �ڷ� �о������.(����)

	//len ����(��ȣ ���)
	switch (opt)
	{
	case 1:
		len_X--;
		len_Y--;
		break;
	case 2:
		len_X--;
		break;
	case 3:
		len_Y--;
		break;
	}

	make_integer(X, Y); //�񱳰� ���� ������ ������ֱ�, ������Ҵ� ��� ����
	wBig = isBig(X, Y); //�׻� X>Y�� ������ֱ�(��� ����� ǥ���ϸ� ��), wBig�� �ٲ������ ���θ� �ֱ�

	printf("X + Y = ");
	sum(X, Y, opt, wBig, len_X, len_Y);
	printf("X - Y = ");
	subtraction(X, Y, opt, wBig, len_X, len_Y);
	printf("X * Y = ");
	multiply(X, Y, opt, wBig, len_X, len_Y);

	return 0;
}

void sum(char *X, char *Y, int opt, int wBig, int len_X, int len_Y)
{
	char answer[81] = { 0, }; //��ȣ�� ���� ���.
	int round = 0; //�ø���
	int trig = 0;

	int len_max = MAX(len_X, len_Y);
	switch (opt) //��� �� ��ȣ ��� �� return.
	{
	case 1:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] + Y[42 - i] + round >= 10)
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		printf("-");
		break;
	case 2:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] - Y[42 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[42 - i] + 10 - Y[42 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[42 - i] + -Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig == 0)
		{
			printf("-");
		}
		break;
	case 3:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] - Y[42 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[42 - i] + 10 - Y[42 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[42 - i] + -Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig == 1)
		{
			printf("-");
		}
		break;
	case 4:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] + Y[42 - i] + round >= 10)
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		break;
	}

	//���, �տ������� 0�� �ƴϰ� �ٸ� ���ڰ� ������ �����Ѵٸ� trig = 1, ������ ���.
	for (int i = 0; i < 81; i++)
	{
		if (answer[i] != 0)
		{
			trig = i;
			break;
		}
		if (i == 80)
			trig = 80;
	}
	for (int j = trig; j < 81; j++)
	{
		printf("%d", answer[j]);
	}
	printf("\n");
}

void subtraction(char *X, char *Y, int opt, int wBig, int len_X, int len_Y)
{
	char answer[81] = { 0, }; //��ȣ�� ���� ���.
	int round = 0; //�ø���

	int trig = 0;
	int len_max = MAX(len_X, len_Y);
	switch (opt) //��� �� ��ȣ ��� �� return.
	{
	case 1:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] - Y[42 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[42 - i] + 10 - Y[42 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[42 - i] + -Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig == 0)
		{
			printf("-");
		}
		break;
	case 2:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] + Y[42 - i] + round >= 10)
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig != 2) printf("-");
		break;
	case 3:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] + Y[42 - i] + round >= 10)
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[42 - i] + Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		break;
	case 4:
		for (int i = 1; i <= len_max + 1; i++)
		{
			if (X[42 - i] - Y[42 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[42 - i] + 10 - Y[42 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[42 - i] - Y[42 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig == 1)
		{
			printf("-");
		}
		break;
	}
	//���, �տ������� 0�� �ƴϰ� �ٸ� ���ڰ� ������ �����Ѵٸ� trig = 1, ������ ���.
	for (int i = 0; i < 81; i++)
	{
		if (answer[i] != 0)
		{
			trig = i;
			break;
		}
		if (i == 80)
			trig = 80;
	}
	for (int j = trig; j < 81; j++)
	{
		printf("%d", answer[j]);
	}
	printf("\n");
}

void multiply(char *X, char *Y, int opt, int wBig, int len_X, int len_Y)
{
	char answer[90] = { 0, }; //��ȣ�� ���� ���.
	char part[90] = { 0, };
	int b_round = 0; //�� �ø���
	int f_round = 0; //�� �ø���
	int round = 0;
	int trig = 0;

	for (int i = 1; i <= 42; i++) //��� üũ�ϱ�.
	{
		for (int j = 1; j <= 42; j++)
		{
			b_round = f_round;
			f_round = (X[42 - j] * Y[42 - i]) / 10;
			part[90 - j - i] = ((X[42 - j] * Y[42 - i]) % 10 + b_round) % 10; //88���� ����
			if (((X[42 - j] * Y[42 - i]) % 10 + b_round) / 10) f_round++;// �ø����� 1 �� �����ִ� ���
		}
		{
			//part�ϼ�, ���� ���ϱ�

			for (int p = 1; p <= 90; p++) //������ 0���� 90����(�˳�)
			{
				if (answer[90 - p] + part[90 - p] + round >= 10)
				{
					answer[90 - p] = answer[90 - p] + part[90 - p] + round - 10; //�ٿ� �ְ�
					round = 1; // �ø��� ����
				}
				else
				{
					answer[90 - p] = answer[90 - p] + part[90 - p] + round; //�����ϱ�
					round = 0; //round �ʱ�ȭ
				}
			}
			round = 0;
		}

		//part �ʱ�ȭ
		for (int k = 0; k < 90; k++)
			part[k] = 0;
	}

	//���, �տ������� 0�� �ƴϰ� �ٸ� ���ڰ� ������ �����Ѵٸ� trig = 1, ������ ���.
	for (int i = 0; i < 90; i++)
	{
		if (answer[i] != 0)
		{
			trig = i;
			break;
		}
		if (i == 89)
			trig = -1;
	}

	if ((opt == 2 || opt == 3) && trig != -1) printf("-");
	
	if (trig == -1)
	{
		printf("0");
	}
	else
	{
		for (int j = trig; j <= 88; j++)
		{
			printf("%d", answer[j]);
		}
	}
	printf("\n");
}

int arrange(char *s1, char *s2, int len_X, int len_Y) //��ȣ ���(���� ������ֱ�), �� �ڷ� �о��ֱ�.
{
	int opt;
	int flag = 0;

	if (s1[0] == '-' && s2[0] == '-') opt = 1;
	else if (s1[0] == '-' && s2[0] != '-') opt = 2;
	else if (s1[0] != '-' && s2[0] == '-') opt = 3;
	else opt = 4;

	if (s1[0] == '-')
	{
		s1[0] = 0;
	}

	for (int i = len_X - 1; i >= 0; i--) //len_X ���θ� �ű��.
	{
		s1[41 - flag] = s1[i]; //�迭 ��°�� �ű��(��ȣ ����), �� �ڴ� ������ null����.
		s1[i] = 0;
		flag++;
	}

	flag = 0;

	if (s2[0] == '-')
	{
		s2[0] = 0;
	}

	for (int i = len_Y - 1; i >= 0; i--)
	{
		s2[41 - flag] = s2[i];
		s2[i] = 0;
		flag++;
	}

	return opt;
}

void make_integer(char *X, char *Y)
{
	for (int i = 0; i < 42; i++)
	{
		if (X[i] != 0)
			X[i] -= '0';
		if (Y[i] != 0)
			Y[i] -= '0';
	}
}

int isBig(char *X, char *Y)
{
	for (int i = 0; i < 42; i++)
	{
		if (X[i] < Y[i])
		{
			swap(X, Y);
			return 1;
		}
		else if (X[i] > Y[i])
		{
			return 0;
		}
	}
	return 2; //���� ����
}

void swap(char *X, char *Y)
{
	int temp;
	for (int i = 0; i < 42; i++)
	{
		temp = X[i];
		X[i] = Y[i];
		Y[i] = temp;
	}
}