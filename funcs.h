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
 * \brief Функция заполняет поля стурктуры big_float дефолтными значениями
 *
 * \param [in, out] num укачатель на big_float число
 */
void fill_big_float(big_float *num);
/**
 * \fn int read_big_float(big_float *number)
 * \brief Функция считывания данных(специальных вещественных чисел)
 *
 * \param [in, out] number укачатель на big_float число
 * \return Возвращает код ошибки 0 или не нулевой
 */
int read_big_float(big_float *number);

void round_mantissa(big_float *num);
/**
 * \fn void del_zero(big_float *num)
 * \brief Функция убирает лишние нули после умножения чисел
 *
 * \param [in, out] num укачатель на big_float число
 */
void del_zero(big_float *num);
/**
 * \fn void del_zero(big_float *num)
 * \brief Функция свигает на один элемент весь массив вправо
 *
 * \param [in, out] arr укачатель на мантиссу числа big_float
 * \param [in] n размер массива
 */
void swap_right_array(short *arr, size_t n);
/**
 * \fn void multiple_arr_to_int(big_float *res, const big_float *num, short fg, short digit)
 * \brief Функция умножает первое число на цифру из второго числа исходя из разрядности цифры
 *
 * \param [in, out] res укачатель на результат умнложения числа типа big_float
 * \param [in] num константный указатель на число, на котрое умножают
 * \param [in] fg цифра из второго числа, которая передано, чтобы умножить число num
 * \param [in] digit разрядность цифры второго числа
 */
void multiple_arr_to_int(big_float *res, const big_float *num, short fg, short digit);
/**
 * \fn big_float sum_big_float(const big_float *num1, const big_float *num2)
 * \brief Функция суммирует два числа структуры big_float
 *
 * \param [in] num1 константный указатель на первое число суммы
 * \param [in] num1 константный указатель на второе число суммы
 * \return Возращает число big_float - результат суммы
 */
big_float sum_big_float(const big_float *num1, const big_float *num2);
/**
 * \fn big_float multiple_big_float(big_float num1, big_float num2)
 * \brief Функция умножает два числа структуры big_float
 *
 * \param [in] num1 константный указатель на первое число суммы
 * \param [in] num1 константный указатель на второе число суммы
 * \return Возращает число big_float - результат умножения
 */
big_float multiply_big_float(big_float num1, big_float num2);

/**
 * \fn void print_field();
 * \brief Функция формуриет текст перед вводом
 */
void print_field();
/**
 * \fn void print_task()
 * \brief Функция формуриет текст задания
 */
void print_task();
/**
 * \fn void print_error(short rc)
 * \brief Функция выводит сообщение об ошибке
 *
 * \param [in] rc код ошибки
 */
void print_error(short rc);
/**
 * \fn void print_big_float(big_float *number)
 * \brief Функция вывода числа структуры big_float
 *
 * \param [in] number указатель на число big_float
 */
void print_big_float(big_float *number);

#endif //_FUNCS_H_
