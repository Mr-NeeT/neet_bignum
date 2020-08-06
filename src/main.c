#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

int main(void)
{
    Bigint num, num2;
    bigint_new(&num);
    bigint_new(&num2);

    bigint_parse_hexstring(&num, "ffffffffffffffffffffffff");
    bigint_copy(num, &num2);

    printf("Copy : \n");
    bigint_print(num);
    bigint_print(num2);
    printf("\n\n");

    printf("Add : \n");
    bigint_add(num2, &num);
    bigint_print(num);
    bigint_print(num2);
    printf("\n\n");

    return 0;
}
