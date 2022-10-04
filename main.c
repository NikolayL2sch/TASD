#include "funcs.h"
#include "constants.h"

int main()
{
    big_float num_1, num_2, result;

    int return_code = 0;

    big_float_default(&num_1);
    big_float_default(&num_2);
    big_float_default(&result);

    print_task();

    printf("Введите вещественное число:");
    print_field();

    return_code = read_big_float(&num_1);
    if (!return_code)
    {
        printf("\n");
        print_field();

        return_code = read_big_float(&num_2);
        if (!return_code)
        {
            printf("\n");
            result = multiply_big_float(num_1, num_2);
            if (result.order > ORDER_UP_OVERFLOW ||  result.order < ORDER_DOWN_OVERFLOW)
                return_code = ORDER_OVERFLOW;
            else
            {
                printf("Результат: ");
                print_big_float(&result);
            }
        }
    }
    
    print_error(return_code);
    return return_code;
}
