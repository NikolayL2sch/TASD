#include "funcs.h"
#include "constants.h"

int main()
{
    big_float num_1, num_2, result;

    fill_big_float(&num_1);
    fill_big_float(&num_2);
    fill_big_float(&result);

    print_task();

    printf("Введите вещественное число:");
    print_field();

    rc = read_big_float(&num_1);
    printf("\n");
    if (rc == EXIT_SUCCESS)
    {
        print_b();
        rc = read_big_float(&num_float_2);
        printf("\n");
        if (rc == EXIT_SUCCESS)
        {
            res_float = multiple_big_float(num_float_1, num_float_2);
            if (res_float.order > ORDER_UP_OVERFLOW ||  res_float.order < ORDER_DOWN_OVERFLOW)
                rc = ORDER_OVERFLOW;
            else
            {
                printf("Результат: ");
                print_big_float(&res_float);
            }
        }
    }
    print_error(rc);
    return rc;
}
