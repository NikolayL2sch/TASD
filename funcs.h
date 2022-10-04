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

//Функция заполняет поля стурктуры big_float дефолтными значениями
void fill_big_float(big_float *num);

/**Функция считывания данных(специальных вещественных чисел)
Возвращает ненулевой код ошибки или нулевой успешного выполнения**/
int read_big_float(big_float *number);

//функция округления мантиссы, если в мантиссе больше 30 знаков
void round_mantissa(big_float *num);

/**
Функция убирает лишние нули после умножения чисел
Принимает и возвращает указатель на число типа big_float
**/
void del_zero(big_float *num);

/**
Функция свигает на один элемент весь массив вправо
Принимает: указатель на мантиссу числа типа big_float и размер массива
**/
void shift_arr_right(short *arr, size_t n);

/**
Функция умножает первое число на цифру из второго числа исходя из разрядности цифры
Принимает: 
    - указатель на результат умнложения числа типа big_float
    - константный указатель на число, на котрое умножают
    - цифру из второго числа, второй множитель
    - разрядность цифры второго числа
**/
void multiply_digit(big_float *res, const big_float *num, short fg, short digit);

/**
Функция суммирует два числа типа big_float
Принимает два константных указателя на два слагаемых
Возращает число big_float - результат суммы
**/
big_float sum_big_float(const big_float *num1, const big_float *num2);

/**
Функция умножает два числа структуры big_float
Принимает два константных указателя на два множителя
Возращает число big_float - результат умножения
**/
big_float multiply_big_float(big_float num1, big_float num2);

/**
Функция формуриет текст перед вводом
**/
void print_field(void);

/**
Функция формуриет текст задания
**/
void print_task();

/**
Функция выводит сообщение об ошибке
Принимает код ошибки
**/
void print_error(short rc);

/**
Функция вывода числа структуры big_float
Принимает указатель на число big_float
**/
void print_big_float(big_float *number);

#endif //_FUNCS_H_
