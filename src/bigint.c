#include "bigint.h"
#include <stdio.h>
#include <stdlib.h>

/* All the interanl function. */
Bigint internal_next(Bigint bigint);
Bigint *internal_delete_if_not_empty(Bigint *bigint);
int internal_hexchar_to_int(char hexChar);
Bigint *internal_init_if_not_inited(Bigint *bigint);
Bigint *internal_insert_new_list_every_8_step(int step, Bigint *bigint);
Bigint *internal_insert_hexstring(char *hexstring, int hexStringPosition, Bigint *bigint);
void internal_bigint_print(Bigint bigint, int first);
int internal_add(unsigned int *a, unsigned int b);

void bigint_new(Bigint *bigint)
{
    void *data = malloc(sizeof(int));
    *(int *)data = 0x0;
    list_new(bigint, data);
}

void bigint_copy(Bigint src, Bigint *dest)
{
    if (src)
        dest = internal_delete_if_not_empty(dest);
    while (src)
    {
        bigint_new(dest);
        *(int *)(*dest)->data = *(int *)src->data;
        dest = &(*dest)->next;
        src = internal_next(src);
    }
}

void bigint_parse_hexstring(Bigint *bigint, char *hexstring)
{
    int index = 0;
    while (*(hexstring + index) != '\0')
    {
        bigint = internal_init_if_not_inited(bigint);
        bigint = internal_insert_new_list_every_8_step(index, bigint);
        bigint = internal_insert_hexstring(hexstring, index, bigint);

        index++;
    }
}

void bigint_print(Bigint bigint)
{
    internal_bigint_print(bigint, 1);
}

void bigint_add(Bigint a, Bigint *b)
{
    int isOverflow = 0;
    while (a)
    {
        if (!(*b))
            bigint_new(b);
        isOverflow = internal_add((unsigned int *)(*b)->data, *(unsigned int *)a->data + isOverflow);

        b = &(*b)->next;
        a = a->next;
    }

    if (isOverflow)
    {
        if (!(*b))
            bigint_new(b);
        internal_add((unsigned int *)(*b)->data, 0x1);
    }
}

Bigint internal_next(Bigint bigint)
{
    return bigint->next;
}

Bigint *internal_delete_if_not_empty(Bigint *bigint)
{
    if (*bigint)
        list_delete(bigint);
    return bigint;
}

int internal_hexchar_to_int(char hexChar)
{
    if (hexChar >= '0' && hexChar <= '9')
        return (int)(hexChar - '0');

    if (hexChar >= 'a' && hexChar <= 'f')
        return (int)(hexChar - 'a') + 0xa;

    return 0;
}

Bigint *internal_init_if_not_inited(Bigint *bigint)
{
    if (!*bigint)
        bigint_new(bigint);
    return bigint;
}

Bigint *internal_insert_new_list_every_8_step(int step, Bigint *bigint)
{
    if (step > 0 && step % 8 == 0)
    {
        void *data = malloc(sizeof(int));
        *(int *)data = 0;
        Bigint newbigint;
        bigint_new(&newbigint);
        newbigint->data = data;
        list_insert(bigint, 0, newbigint);
    }
    return bigint;
}

Bigint *internal_insert_hexstring(char *hexstring, int hexStringPosition, Bigint *bigint)
{
    int data = *(int *)((*bigint)->data);
    data = data << 0x4;
    data += internal_hexchar_to_int(*(hexstring + hexStringPosition));
    *(int *)((*bigint)->data) = data;
    return bigint;
}

void internal_bigint_print(Bigint bigint, int first)
{
    if (bigint->next)
        internal_bigint_print(bigint->next, 0);
    printf("%x ", *(int *)(bigint->data));
    if (first)
        printf("\n");
}

int internal_add(unsigned int *a, unsigned int b)
{
    int isOverflow = 0;
    if ((*a > 0) && (*a > INT32_MAX - b))
        isOverflow = 1;
    *a = *a + b;
    return isOverflow;
}
