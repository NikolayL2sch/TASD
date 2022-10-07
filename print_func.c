// Файл с функциями для формирования вывода

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
    printf("------------------------Умножение двух действительных чисел---------------------\n");
    printf("Формат ввода допускает ввод как целое, так и вещественного (в том числе и в экспонированном виде)\n +-M.Ne+-K\n");
    printf("Вывод в виде +-0.N+Me+-K\n");
    printf("Пределы ввода, сумма N, M не превышает 30 значимых цифр, а порядок K - 5 цифр!\n");
    printf("------------------------------------------------------------------------------\n");
}

void print_error(short rc)
{
    switch(rc)
    {
        case EMPTY_STRING_ERROR:
            printf("ОШИБКА! Введена пустая строка!\n");
            break;
        case STRING_OVERFLOW:
            printf("ОШИБКА! Переполнение возможно допустимых введенных значений!\n");
            break;
        case EPS_ERR:
            printf("ОШИБКА! В числе находятся несколько обозначений \"e\" либо только \"e\"!\n");
            break;
        case INCORRECT_NUM:
            printf("ОШИБКА! Некорректно записано вещественное число!\n");
            break;
        case MANTISSA_SIGN_ERR:
            printf("ОШИБКА! Записано несколько знаков перед мантиссой или в самой мантиссе (знак должен быть один)!\n");
            break;
        case MANTISSA_POINT_ERR:
            printf("ОШИБКА! В вещественном числе находятся несколько точек (в мантиссе)!\n");
            break;
        case MANTISSA_OVERFLOW:
            printf("ОШИБКА! В мантиссе больше 30 элементов!\n");
            break;
        case ORDER_SIGN_ERR:
            printf("ОШИБКА! Записано несколько знаков перед порядком или в самом порядке (знак должен быть один)!\n");
            break;
        case ORDER_POINT_ERR:
            printf("ОШИБКА! В порядке не должно быть точек!\n");
            break;
        case ORDER_OVERFLOW:
            printf("ОШИБКА! В порядке больше 5 цифр!\n");
            break;
        case ORDER_INCORRECT:
            printf("ОШИБКА! Неверно указан порядок!\n");
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