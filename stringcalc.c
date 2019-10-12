#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

char* sum(char calc_X[41], char calc_Y[41], int opt);
char* subtraction(char calc_X[41], char calc_Y[41], int opt);
char* multiply(char calc_X[41], char calc_Y[41], int opt);
int unsign(char s1[41], char s2[41], int len_X, int len_Y); //부호 따지기.

int main()
{
    char X[41] = {0,}; //다 NULL문자로 차있어라.
    char Y[41] = {0,};
    char output[81] = {0,}; //앞을 0으로 하고, 0이 안나오는 시점부터 출력하면 된다.

    int digit_x, digit_y;
    int len_X, len_Y;
    int opt;

    printf("input X. ");
    scanf("%s", X); //문자열로 받기
    printf("input Y. ");
    scanf("%s", Y); //문자열로 받기

    len_X = strlen(calc_X);
    len_Y = strlen(calc_Y);

    opt = unsign(X, Y, len_X, len_Y); //애초에 부호 부분과 수 부분을 나눠서 주자. 부호를 떼고 opt를 얻고, 뒤로 밀어버리기.

    printf("X + Y = ");

    //printf("%c%s\n", sum(X, Y, opt)); //sum안에서 부호 출력하고, %c%s 출력하기. for문으로 문자대로 출력하기

    printf("X - Y = ");
    //printf("%c%s\n", subtraction(X, Y, opt));

    printf("X * Y = ");
    //printf("%c%s\n", multiply(X, Y, opt));
    return 0;
}

char* sum(char calc_X[41], char calc_Y[41], int opt)
{
    char answer[81] = {0,}; //부호는 따로 출력.
    int round = 0; //올림수

    switch(opt) //계산 후 부호 출력 후 return.
    {
    case 1:
        for(int i=1;; i++)
            {
                if(calc_X[41-i] && calc_Y[41-i]) //둘다 숫자면
                {
                    if((calc_X[41-i] - '0') + (calc_Y[41-i] - '0') + round >= 10)
                    {
                        answer[80-i] = (calc_X[41-i] - '0') + (calc_Y[41-i] - '0') + round - 10 + '0'; //줄여 주고
                        round = 1; // 올림수 증가
                    }
                    else
                    {
                        answer[80-i] = (calc_X[41-i] - '0') + (calc_Y[41-i] - '0') + round + '0'; //대입하기
                        round = 0; //round 초기화
                    }
                }
                else if(calc_X[41-i] == 0 && calc_Y[41-i] == 0) // 0, 0이면
                {
                    break;
                }
                else //0,숫자 또는 숫자,0이면
                {
                    answer[80-i] = calc_X[length_X-i] + calc_Y[length_Y-i] + round; //대입하기
                    round = 0; //round 초기화
                }
            }
        printf("-");
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:
        for(int i=1;; i++)
            {
                if(calc_X[length_X-i] && calc_Y[length_Y-i]) //둘다 숫자면
                {
                    if((calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round >= 10)
                    {
                        answer[80-i] = (calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round - 10 + '0'; //줄여 주고
                        round = 1; // 올림수 증가
                    }
                    else
                    {
                        answer[80-i] = (calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round + '0'; //대입하기
                        round = 0; //round 초기화
                    }
                }
                else if(calc_X[length_X-i]==0 && calc_Y[length_Y-i]==0) // 0, 0이면
                {
                    break;
                }
                else //0,숫자 또는 숫자,0이면
                {
                    answer[80-i] = calc_X[length_X-i] + calc_Y[length_Y-i] + round; //대입하기
                    round = 0; //round 초기화
                }
            }
        break;
    }
}

char* subtraction(char calc_X[41], char calc_Y[41], int opt)
{

}

char* multiply(char calc_X[41], char calc_Y[41], int opt)
{

}

int unsign(char s1[41], char s2[41], int len_X, int len_Y) //숫자 절댓값 씌워주기, 수 뒤로 밀어주기.
{
    int opt;
    int flag = 1;

    if(s1[0] == '-' && s2[0] == '-') opt = 1;
    else if(s1[0] == '-' && s2[0] == '+') opt = 2;
    else if(s1[0] == '+' && s1[0] == '-') opt = 3;
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
}
