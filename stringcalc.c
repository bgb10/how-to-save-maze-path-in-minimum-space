#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

char* sum(char calc_X[41], char calc_Y[41], int opt);
char* subtraction(char calc_X[41], char calc_Y[41], int opt);
char* multiply(char calc_X[41], char calc_Y[41], int opt);
int sign(char s1, char s2); //��ȣ ������.

int main()
{
    char X[41] = {0,}; //�� NULL���ڷ� ���־��.
    char Y[41] = {0,};
    char output[81] = {0,}; //���� 0���� �ϰ�, 0�� �ȳ����� �������� ����ϸ� �ȴ�.

    int digit_x, digit_y;

    int opt;

    printf("input X. ");
    scanf("%s", X);
    printf("input Y. ");
    scanf("%s", Y);

    opt = sign(X[0], Y[0]); //���ʿ� ��ȣ�� ���� ����.

    printf("X + Y = ");
    //printf("%c%s\n", sum(X, Y, opt)); //sum�ȿ��� ��ȣ ����ϰ�, %c%s ����ϱ�. for������ ���ڴ�� ����ϱ�
    printf("X - Y = ");
    //printf("%c%s\n", subtraction(X, Y, opt));
    printf("X * Y = ");
    //printf("%c%s\n", multiply(X, Y, opt));
    return 0;
}

char* sum(char calc_X[41], char calc_Y[41], int opt)
{
    char answer[81] = {0,}; //��ȣ�� ���� ���.
    int length_X, length_Y;
    int round = 0; //�ø���

    length_X = strlen(calc_X);
    length_Y = strlen(calc_Y);

    switch(opt) //��� �� ��ȣ ��� �� return.
    {
    case 1:
        /*for(int i=1;; i++) //�̷��� ¥�� �����÷ο� �߻��Ѵ�.
            {
                if(calc_X[length_X-i] && calc_Y[length_Y-i]) //�Ѵ� ���ڸ�
                {
                    if((calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round >= 10)
                    {
                        answer[80-i] = (calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round - 10 + '0'; //�ٿ� �ְ�
                        round = 1; // �ø��� ����
                    }
                    else
                    {
                        answer[80-i] = (calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round + '0'; //�����ϱ�
                        round = 0; //round �ʱ�ȭ
                    }
                }
                else if((calc_X[length_X-i]==0 && calc_Y[length_Y-i]==0) || (calc_X[length_X-i]=='-' && calc_Y[length_Y-i]=='-')) // 0, 0�̸� �Ǵ� �Ѵ� - ���ڸ�
                {
                    break;
                }
                else //0,���� �Ǵ� ����,0�̸�
                {
                    answer[80-i] = calc_X[length_X-i] + calc_Y[length_Y-i] + round; //�����ϱ�
                    round = 0; //round �ʱ�ȭ
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
                if(calc_X[length_X-i] && calc_Y[length_Y-i]) //�Ѵ� ���ڸ�
                {
                    if((calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round >= 10)
                    {
                        answer[80-i] = (calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round - 10 + '0'; //�ٿ� �ְ�
                        round = 1; // �ø��� ����
                    }
                    else
                    {
                        answer[80-i] = (calc_X[length_X-i] - '0') + (calc_Y[length_Y-i] - '0') + round + '0'; //�����ϱ�
                        round = 0; //round �ʱ�ȭ
                    }
                }
                else if(calc_X[length_X-i]==0 && calc_Y[length_Y-i]==0) // 0, 0�̸�
                {
                    break;
                }
                else //0,���� �Ǵ� ����,0�̸�
                {
                    answer[80-i] = calc_X[length_X-i] + calc_Y[length_Y-i] + round; //�����ϱ�
                    round = 0; //round �ʱ�ȭ
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
