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
        case EMPTY_STRING_ERROR:
            printf("������! ������� ������ ������!\n");
            break;
        case STRING_OVERFLOW:
            printf("������! ������������ �������� ���������� ��������� ��������!\n");
            break;
        case EPS_ERR:
            printf("������! � ����� ��������� ��������� ����������� \"e\" ���� ������ \"e\"!\n");
            break;
        case INCORRECT_NUM:
            printf("������! ����������� �������� ������������ �����!\n");
            break;
        case MANTISSA_SIGN_ERR:
            printf("������! �������� ��������� ������ ����� ��������� ��� � ����� �������� (���� ������ ���� ����)!\n");
            break;
        case MANTISSA_POINT_ERR:
            printf("������! � ������������ ����� ��������� ��������� ����� (� ��������)!\n");
            break;
        case MANTISSA_OVERFLOW:
            printf("������! � �������� ������ 30 ���������!\n");
            break;
        case ORDER_SIGN_ERR:
            printf("������! �������� ��������� ������ ����� �������� ��� � ����� ������� (���� ������ ���� ����)!\n");
            break;
        case ORDER_POINT_ERR:
            printf("������! � ������� �� ������ ���� �����!\n");
            break;
        case ORDER_OVERFLOW:
            printf("������! � ������� ������ 5 ����!\n");
            break;
        case ORDER_INCORRECT:
            printf("������! ������� ������ �������!\n");
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