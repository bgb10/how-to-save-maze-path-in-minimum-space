#define _CRT_SECURE_NO_WARNINGS //-0�� �ֳ�����...
#include <stdio.h>
#include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b));

void sum(char *X, char *Y, int opt, int wBig, int len_X, int len_Y);
void subtraction(char *X, char *Y, int opt, int wBig, int len_X, int len_Y);
void multiply(char *X, char *Y, int opt, int wBig, int len_X, int len_Y);

int arrange(char * s1, char * s2, int len_X, int len_Y);

void make_integer(char *X, char *Y);
int isBig(char *X, char *Y);
void swap(char *X, char *Y);

int main()
{
    char X[41] = {0,}; //�� 0���� ���־��.
    char Y[41] = {0,}; 
    char output[81] = {0,}; //���� 0���� �ϰ�, 0�� �ȳ����� �������� ����ϸ� �ȴ�.


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

void sum(char *X, char *Y, int opt, int wBig, int len_X, int len_Y) //answer�� ��� ����...
{
    char answer[81] = {0,}; //��ȣ�� ���� ���.
    int round = 0; //�ø���
	int trig = 0;

	int len_max = MAX(len_X, len_Y);
    switch(opt) //��� �� ��ȣ ��� �� return.
    {
    case 1:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] + Y[41 - i] + round >= 10)
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if(wBig != 2) printf("-");
        break;
    case 2:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] - Y[41 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[41 - i] + - Y[41 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig == 0)
		{
			printf("-");
		}
        break;
    case 3:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] - Y[41 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[41 - i] + - Y[41 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig == 1)
		{
			printf("-");
		}
        break;
    case 4:  
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] + Y[41 - i] + round >= 10)
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //�����ϱ�
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
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] - Y[41 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[41 - i] + -Y[41 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig == 0)
		{
			printf("-");
		}
		break;
	case 2:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] + Y[41 - i] + round >= 10)
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		if (wBig != 2) printf("-");
		break;
	case 3:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] + Y[41 - i] + round >= 10)
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}
		break;
	case 4:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] - Y[41 - i] + round < 0) //�ڸ��� ���� ���� ������
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //�ٿ� �ְ�
				round = -1; // ������ �߻�
			}
			else
			{
				answer[81 - i] = X[41 - i] - Y[41 - i] + round; //�����ϱ�
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
	char answer[81] = { 0, }; //��ȣ�� ���� ���.
	char part[81] = { 0, };
	int b_round = 0; //�� �ø���
	int f_round = 0; //�� �ø���
	int round = 0;
	int trig = 0;

	for (int i = 1; i <= len_Y + 1; i++)
	{
		for (int j = 1; j <= len_X + 1; j++)
		{
			b_round = f_round;
			f_round = (X[42 - j - i] * Y[41 - i]) / 10;
			part[82 - j - i] = ((X[42 - j - i] * Y[41 - i]) % 10 + b_round) % 10;
			if (((X[42 - j - i] * Y[41 - i]) % 10 + b_round)/10) f_round++;// �ø����� 1 �� �����ִ� ���
		}
		
		{
			if (answer[81 - i] + part[81 - i] + round >= 10)
			{
				answer[81 - i] = answer[81 - i] + part[81 - i] + round - 10; //�ٿ� �ְ�
				round = 1; // �ø��� ����
			}
			else
			{
				answer[81 - i] = answer[81 - i] + part[81 - i] + round; //�����ϱ�
				round = 0; //round �ʱ�ȭ
			}
		}

		//part �ʱ�ȭ
		for (int i = 0; i < 81; i++)
			part[i] = 0;
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

int arrange(char *s1, char *s2, int len_X, int len_Y) //��ȣ ���(���� ������ֱ�), �� �ڷ� �о��ֱ�.
{
    int opt;
    int flag = 1;

    if(s1[0] == '-' && s2[0] == '-') opt = 1;
    else if(s1[0] == '-' && s2[0] != '-') opt = 2;
    else if(s1[0] != '-' && s2[0] == '-') opt = 3;
    else opt = 4;

    for(int i = len_X - 1; i >= 0; i--)
    {
        s1[41 - flag] = s1[i];
		s1[i] = 0;
        flag++;
    }

    if(s1[41 - len_X] == '-')
    {
        s1[41 - len_X] = 0;
    }

	flag = 1;

	for (int i = len_Y - 1; i >= 0; i--)
	{
		s2[41 - flag] = s2[i];
		s2[i] = 0;
		flag++;
	}

	if (s2[41 - len_Y] == '-')
	{
		s2[41 - len_Y] = 0;
	}

	return opt;
}

void make_integer(char *X, char *Y)
{
    for(int i=0;i<41;i++)
    {
        if(X[i] != 0)
            X[i] -= '0';
        if(Y[i] != 0)
            Y[i] -= '0';
    }
}

int isBig(char *X, char *Y)
{
	for (int i = 0; i < 41; i++)
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
	for (int i = 0; i < 41; i++)
	{
		temp = X[i];
		X[i] = Y[i];
		Y[i] = temp;
	}
}