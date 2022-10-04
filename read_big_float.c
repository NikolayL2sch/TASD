//файл с описанием процедур считывания и дефолтного заполнения числа типа big_float
#include "funcs.h"
#include "constants.h"

void fill_big_float(big_float *num)
{
    num->size = 0;
    num->order = 0;
    num->sign = '+';
    for (size_t i = 0; i < M_N; i++)
        num->mantissa[i] = 0;
}

int read_big_float(big_float *number)
{
    char str[MAX_STRING_FLOAT];
    short n = 0, m = 0;
    int order = 0, order_p = 0;
    bool was_point = false, sign = false, was_base = false, flag = false;
    size_t i = 0;

    //проверка правильности и корректирование считанного значения
    if (fgets(str, MAX_STRING_FLOAT + 2, stdin) == NULL)
        return EMPTY_STRING_ERROR;
    
    int str_len = strlen(str);
    if (str[str_len - 1] == '\n')
        str[str_len - 1] = '\0';
    
    if (str_len > MAX_STRING_FLOAT)
        return STRING_OVERFLOW;
    
    if (str_len == 0)
        return EMPTY_STRING_ERROR;
    
    if (str[0] == 'e' || str[0] == 'E')
        return EPS_ERR;
    
    // заполнение полей структуры
    if (str[0] == '-' || str[0] == '+')
    {
        number->sign = str[0];
        i++;
    } else
        number->sign = '+';
    sign = true;

    while (i < (M_N + was_point + sign + 1) && str[i] != '\0' && !was_base)
    {
        if ((str[i] == '.' || str[i] == ',') && !was_point)
        {
            was_point = true;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            was_base = true;
        }
        else if ('0'<= str[i] && str[i] <= '9')
        {

            if (str[i] == '0' && !flag)
            {
                if (was_point)
                    order_p--;
                i++;
                continue;
            }
            if (str[i] != '0')
            {
                if (!flag)
                    flag = true;
            }
            number->mantissa[m + n] = (short) (str[i] - '0');
            if (was_point)
                n++;
            else
                m++;
        }
        else
        {
            if (str[i] == '-' || str[i] == '+')
                return MANTISSA_SIGN_ERR;
            if (str[i] == '.' || str[i] == ',')
                return MANTISSA_POINT_ERR;
            return INCORRECT_NUM;
        }
        i++;
    }
    if (i - was_point - was_base - sign > M_N)
        return MANTISSA_OVERFLOW;
    
    number->size = (m + n);
    if (was_base)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            if (str[i] == '-')
                sign = true;
            i++;
        }
        for (; str[i] != '\0'; i++)
        {
            if ('0'<= str[i] && str[i] <= '9')
                order = order * 10 + (int) (str[i] - '0');
            else
            {
                if (str[i] == '-' || str[i] == '+')
                    return ORDER_SIGN_ERR;
                else if (str[i] == '.' || str[i] == ',')
                    return ORDER_POINT_ERR;
                else if (str[i] == 'e' || str[i] == 'E')
                    return EPS_ERR;
                return ORDER_INCORRECT;
            }
        }
        if (sign)
        {
            sign = false;
            order*= -1;
        }
    }
    if (number->size != 0)
        number->order = m + order + order_p;
    else
    {
        n = 1;
        number->size = 1;
    }

    return EXIT_SUCCESS;
}
