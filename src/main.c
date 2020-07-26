#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_data(void *data) {
    printf("%i\n", *(int*)data);
}

void *make_data(int num) {
    void *data = malloc(sizeof(int));
    *(int *)data = num;
    return data;
}

int main(void)
{
    List list = NULL;
    list_new(&list, make_data(0));
    for (int i = 1; i < 11; i++) {
        list_push(list, make_data(i));
    }

    List ins;
    list_new(&ins, make_data(55));
    list_insert(&list, 9, ins);

    list_print(list, print_data);

    return 0;
}
