#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

char* sum(char calc_X[41], char calc_Y[41], int opt);
char* subtraction(char calc_X[41], char calc_Y[41], int opt);
char* multiply(char calc_X[41], char calc_Y[41], int opt);
int sign(char s1, char s2); //부호 따지기.

int main()
{
    char X[41] = {0,}; //다 NULL문자로 차있어라.
    char Y[41] = {0,};
    char output[81] = {0,}; //앞을 0으로 하고, 0이 안나오는 시점부터 출력하면 된다.

    int digit_x, digit_y;

    int opt;

    printf("input X. ");
    scanf("%s", X);
    printf("input Y. ");
    scanf("%s", Y);

    opt = sign(X[0], Y[0]); //애초에 부호를 때고 주자.

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
    int length_X, length_Y;
    int round = 0; //올림수

    length_X = strlen(calc_X);
    length_Y = strlen(calc_Y);

    switch(opt) //계산 후 부호 출력 후 return.
    {
    case 1:
        /*for(int i=1;; i++) //이렇게 짜면 오버플로우 발생한다.
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
                else if((calc_X[length_X-i]==0 && calc_Y[length_Y-i]==0) || (calc_X[length_X-i]=='-' && calc_Y[length_Y-i]=='-')) // 0, 0이면 또는 둘다 - 문자면
                {
                    break;
                }
                else //0,숫자 또는 숫자,0이면
                {
                    answer[80-i] = calc_X[length_X-i] + calc_Y[length_Y-i] + round; //대입하기
                    round = 0; //round 초기화
                }
            }
        printf("-");*/
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

int sign(char s1, char s2)
{
    if(s1 == '-' && s2 == '-') return 1;
    else if(s1 == '-' && s2 == '+') return 2;
    else if(s1 == '+' && s1 == '-') return 3;
    else return 4;
}
