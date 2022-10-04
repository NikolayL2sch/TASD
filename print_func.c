/**
 * \file print_func.c
 * \brief ���� � ��������� ��� ������������ ������
 */
#include "funcs.h"
#include "constants.h"

void print_field(void)
{
    for (size_t i = 0; i < M_N; i++)
       printf(" ");
    printf("|");
    for (size_t i = 0; i < M_N + 1; i++)
       printf("\b");
}

void print_task(void)
{
    printf("------------------------��������� ���� �������������� �����---------------------\n");
    printf("������ ����� ��������� ���� ��� �����, ��� � ������������� (� ��� ����� � � ��������������� ����)\n +-M.Ne+-K\n");
    printf("����� � ���� +-0.N+Me+-K\n");
    printf("������� �����, ����� N, M �� ��������� 30 �������� ����, � ������� K - 5 ����!\n");
    printf("------------------------------------------------------------------------------\n");
}

void print_error(short rc)
{
    switch(rc)
    {
        case INCORRECT_FLOAT:
            printf("Warning! ����������� �������� ������������ �����!\n");
            break;
        case MANTISSA_OVERFLOW:
            printf("Warning! � �������� ������ 30 ���������!\n");
            break;
        case ORDER_OVERFLOW:
            printf("Warning! � ������� ������ 5 ����!\n");
            break;
        case M_POINT_ERR:
            printf("Warning! � ������������ ����� ��������� ��������� �����, � ��������!\n");
            break;
        case M_SIGN_ERR:
            printf("Warning! �������� ��������� ������ ����� ��������� ��� � ����� ��������!\n");
            break;
        case O_POINT_ERR:
            printf("Warning! � ������� �� ������ ���� �����!\n");
            break;
        case O_SIGN_ERR:
            printf("Warning! �������� ��������� ������ ����� �������� ��� � ����� �������!\n");
            break;
        case EPS_ERR:
            printf("Warning! � ����� ��������� ��������� ����������� \"e\" ���� ������ \"e\"!\n");
            break;
        case ORDER_INCORRECT:
            printf("Warning! � ������� ������!\n");
            break;
        case STRING_OVERFLOW:
            printf("Warning! ������������ �������� ���������� ��������� ��������!\n");
            break;
        case STRING_EMPTY:
            printf("Warning! ������� ������ ������!\n");
            break;
        default:
            break;
    }
}

void print_big_float(big_float *number)
{
    if (number->sign == '-')
        printf("%c", number->sign);
    printf("0.");
    if (number->size == 0)
        printf("0");
    else
        for (size_t i = 0; i < number->size; i++)
            printf("%hd", number->mantissa[i]);
    printf("e%d\n", number->order);
}