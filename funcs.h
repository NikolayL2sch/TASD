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

/**
 * \fn void fill_big_float_default(big_float *num)
 * \brief ������� ��������� ���� ��������� big_float ���������� ����������
 *
 * \param [in, out] num ��������� �� big_float �����
 */
void fill_big_float(big_float *num);
/**
 * \fn int read_big_float(big_float *number)
 * \brief ������� ���������� ������(����������� ������������ �����)
 *
 * \param [in, out] number ��������� �� big_float �����
 * \return ���������� ��� ������ 0 ��� �� �������
 */
int read_big_float(big_float *number);

void round_mantissa(big_float *num);
/**
 * \fn void del_zero(big_float *num)
 * \brief ������� ������� ������ ���� ����� ��������� �����
 *
 * \param [in, out] num ��������� �� big_float �����
 */
void del_zero(big_float *num);
/**
 * \fn void del_zero(big_float *num)
 * \brief ������� ������� �� ���� ������� ���� ������ ������
 *
 * \param [in, out] arr ��������� �� �������� ����� big_float
 * \param [in] n ������ �������
 */
void swap_right_array(short *arr, size_t n);
/**
 * \fn void multiple_arr_to_int(big_float *res, const big_float *num, short fg, short digit)
 * \brief ������� �������� ������ ����� �� ����� �� ������� ����� ������ �� ����������� �����
 *
 * \param [in, out] res ��������� �� ��������� ���������� ����� ���� big_float
 * \param [in] num ����������� ��������� �� �����, �� ������ ��������
 * \param [in] fg ����� �� ������� �����, ������� ��������, ����� �������� ����� num
 * \param [in] digit ����������� ����� ������� �����
 */
void multiple_arr_to_int(big_float *res, const big_float *num, short fg, short digit);
/**
 * \fn big_float sum_big_float(const big_float *num1, const big_float *num2)
 * \brief ������� ��������� ��� ����� ��������� big_float
 *
 * \param [in] num1 ����������� ��������� �� ������ ����� �����
 * \param [in] num1 ����������� ��������� �� ������ ����� �����
 * \return ��������� ����� big_float - ��������� �����
 */
big_float sum_big_float(const big_float *num1, const big_float *num2);
/**
 * \fn big_float multiple_big_float(big_float num1, big_float num2)
 * \brief ������� �������� ��� ����� ��������� big_float
 *
 * \param [in] num1 ����������� ��������� �� ������ ����� �����
 * \param [in] num1 ����������� ��������� �� ������ ����� �����
 * \return ��������� ����� big_float - ��������� ���������
 */
big_float multiply_big_float(big_float num1, big_float num2);

/**
 * \fn void print_field();
 * \brief ������� ��������� ����� ����� ������
 */
void print_field();
/**
 * \fn void print_task()
 * \brief ������� ��������� ����� �������
 */
void print_task();
/**
 * \fn void print_error(short rc)
 * \brief ������� ������� ��������� �� ������
 *
 * \param [in] rc ��� ������
 */
void print_error(short rc);
/**
 * \fn void print_big_float(big_float *number)
 * \brief ������� ������ ����� ��������� big_float
 *
 * \param [in] number ��������� �� ����� big_float
 */
void print_big_float(big_float *number);

#endif //_FUNCS_H_
