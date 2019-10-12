#define _CRT_SECURE_NO_WARNINGS
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
    char X[41] = {0,}; //다 0으로 차있어라.
    char Y[41] = {0,}; 
    char output[81] = {0,}; //앞을 0으로 하고, 0이 안나오는 시점부터 출력하면 된다.


    int len_X, len_Y;
    int opt;
	int wBig;

    printf("input X. ");
    scanf("%s", X); //문자열로 받기
    printf("input Y. ");
    scanf("%s", Y); //문자열로 받기

    len_X = strlen(X);
    len_Y = strlen(Y);
	//len_max는 +1해야 다 더해준다.

    opt = arrange(X, Y, len_X, len_Y); //애초에 부호 부분과 수 부분을 나눠서 주자. 부호를 떼고 opt(부호옵션)를 얻고, 뒤로 밀어버리기.(절댓값)
    make_integer(X, Y); //비교가 쉽게 정수를 만들어주기, 구성요소는 모두 정수
	wBig = isBig(X, Y); //항상 X>Y로 만들어주기(계산 결과만 표시하면 됨), wBig에 바뀌었는지 여부를 주기

	printf("X + Y = ");
	sum(X, Y, opt, wBig, len_X, len_Y);
    printf("X - Y = ");
	subtraction(X, Y, opt, wBig, len_X, len_Y);
    printf("X * Y = ");
	multiply(X, Y, opt, wBig, len_X, len_Y);
    
	return 0;
}

void sum(char *X, char *Y, int opt, int wBig, int len_X, int len_Y) //answer을 어떻게 할지...
{
    char answer[81] = {0,}; //부호는 따로 출력.
    int round = 0; //올림수
	int trig = 0;

	int len_max = MAX(len_X, len_Y);
    switch(opt) //계산 후 부호 출력 후 return.
    {
    case 1:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] + Y[41 - i] + round >= 10)
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //줄여 주고
				round = 1; // 올림수 증가
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
			}
		}
		printf("-");
        break;
    case 2:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] - Y[41 - i] + round < 0) //자리수 연산 값이 음수면
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //줄여 주고
				round = -1; // 내림수 발생
			}
			else
			{
				answer[81 - i] = X[41 - i] + - Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
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
			if (X[41 - i] - Y[41 - i] + round < 0) //자리수 연산 값이 음수면
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //줄여 주고
				round = -1; // 내림수 발생
			}
			else
			{
				answer[81 - i] = X[41 - i] + - Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
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
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //줄여 주고
				round = 1; // 올림수 증가
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
			}
		}
		break;
    }
	
	//출력, 앞에서부터 0이 아니고 다른 숫자가 나오기 시작한다면 trig = 1, 끝까지 출력.
	for (int i = 0; i < 81; i++)
	{
		if (answer[i] != 0)
		{
			trig = i;
			break;
		}
	}
	for (int j = trig; j < 81; j++)
	{
		printf("%d", answer[j]);
	}
	printf("\n");
}

void subtraction(char *X, char *Y, int opt, int wBig, int len_X, int len_Y)
{
	char answer[81] = { 0, }; //부호는 따로 출력.
	int round = 0; //올림수

	int trig = 0;
	int len_max = MAX(len_X, len_Y);
	switch (opt) //계산 후 부호 출력 후 return.
	{
	case 1:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] - Y[41 - i] + round < 0) //자리수 연산 값이 음수면
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //줄여 주고
				round = -1; // 내림수 발생
			}
			else
			{
				answer[81 - i] = X[41 - i] + -Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
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
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //줄여 주고
				round = 1; // 올림수 증가
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
			}
		}
		printf("-");
		break;
	case 3:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] + Y[41 - i] + round >= 10)
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round - 10; //줄여 주고
				round = 1; // 올림수 증가
			}
			else
			{
				answer[81 - i] = X[41 - i] + Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
			}
		}
		break;
	case 4:
		for (int i = 1; i <= len_max+1; i++)
		{
			if (X[41 - i] - Y[41 - i] + round < 0) //자리수 연산 값이 음수면
			{
				answer[81 - i] = X[41 - i] + 10 - Y[41 - i] + round; //줄여 주고
				round = -1; // 내림수 발생
			}
			else
			{
				answer[81 - i] = X[41 - i] + -Y[41 - i] + round; //대입하기
				round = 0; //round 초기화
			}
		}
		if (wBig == 1)
		{
			printf("-");
		}
		break;
	}
	//출력, 앞에서부터 0이 아니고 다른 숫자가 나오기 시작한다면 trig = 1, 끝까지 출력.
	for (int i = 0; i < 81; i++)
	{
		if (answer[i] != 0)
		{
			trig = i;
			break;
		}
	}
	for (int j = trig; j < 81; j++)
	{
		printf("%d", answer[j]);
	}
	printf("\n");
}

void multiply(char *X, char *Y, int opt, int wBig, int len_X, int len_Y)
{
	char answer[81] = { 0, }; //부호는 따로 출력.
	int round = 0; //올림수
	int trig = 0;

	for (int i = 1; i <= len_Y; i++)
	{
		for (int j = 1; j <= len_X; j++)
		{
			answer[81 - j - i] = ((X[41 - j - i] * Y[41 - j - i]) % 10 + round) % 10;
			round = (X[41 - j - i] * Y[41 - j - i]) / 10;
			if ((X[41 - j - i] * Y[41 - j - i]) % 10 + round / 10) round++;// 올림수를 1 더 더해주는 경우
		}
	}

	//출력, 앞에서부터 0이 아니고 다른 숫자가 나오기 시작한다면 trig 부터 끝까지 출력.
	for (int i = 0; i < 81; i++)
	{
		if (answer[i] != 0)
		{
			trig = i;
			break;
		}
	}

	for (int j = trig; j < 81; j++)
	{
		printf("%d", answer[j]);
	}
	printf("\n");
}

int arrange(char *s1, char *s2, int len_X, int len_Y) //부호 얻기(절댓값 만들어주기), 수 뒤로 밀어주기.
{
    int opt;
    int flag = 1;

    if(s1[0] == '-' && s2[0] == '-') opt = 1;
    else if(s1[0] == '-' && s2[0] != '-') opt = 2;
    else if(s1[0] != '-' && s2[0] == '-') opt = 3;
    else opt = 4;

    for(int i = len_X - 1; i >= 0; i--)
    {
        s1[41-flag] = s1[i];
        flag++;
    }

    if(s1[41-len_X] == '-')
    {
        s1[41-len_X] = 0;
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
		else
			continue;
	}
	return 0;
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