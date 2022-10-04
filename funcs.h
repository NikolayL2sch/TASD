#ifndef _FUNCS_H_
#define _FUNCS_H_

//big float struct
typedef struct
{
    char sign;
    short mantissa[MAX_ARRAY_SIZE];
    size_t size;
    int order;
} big_float;

//������� ��������� ���� ��������� big_float ���������� ����������
void fill_big_float(big_float *num);

/**������� ���������� ������(����������� ������������ �����)
���������� ��������� ��� ������ ��� ������� ��������� ����������**/
int read_big_float(big_float *number);

//������� ���������� ��������, ���� � �������� ������ 30 ������
void round_mantissa(big_float *num);

/**
������� ������� ������ ���� ����� ��������� �����
��������� � ���������� ��������� �� ����� ���� big_float
**/
void del_zero(big_float *num);

/**
������� ������� �� ���� ������� ���� ������ ������
���������: ��������� �� �������� ����� ���� big_float � ������ �������
**/
void shift_arr_right(short *arr, size_t n);

/**
������� �������� ������ ����� �� ����� �� ������� ����� ������ �� ����������� �����
���������: 
    - ��������� �� ��������� ���������� ����� ���� big_float
    - ����������� ��������� �� �����, �� ������ ��������
    - ����� �� ������� �����, ������ ���������
    - ����������� ����� ������� �����
**/
void multiply_digit(big_float *res, const big_float *num, short fg, short digit);

/**
������� ��������� ��� ����� ���� big_float
��������� ��� ����������� ��������� �� ��� ���������
��������� ����� big_float - ��������� �����
**/
big_float sum_big_float(const big_float *num1, const big_float *num2);

/**
������� �������� ��� ����� ��������� big_float
��������� ��� ����������� ��������� �� ��� ���������
��������� ����� big_float - ��������� ���������
**/
big_float multiply_big_float(big_float num1, big_float num2);

/**
������� ��������� ����� ����� ������
**/
void print_field(void);

/**
������� ��������� ����� �������
**/
void print_task();

/**
������� ������� ��������� �� ������
��������� ��� ������
**/
void print_error(short rc);

/**
������� ������ ����� ��������� big_float
��������� ��������� �� ����� big_float
**/
void print_big_float(big_float *number);

#endif //_FUNCS_H_
