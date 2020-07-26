#include <stdlib.h>
#include "list.h"

void list_new(List *list, void *data)
{
    (*list) = (List)malloc(sizeof(List));
    (*list)->data = data;
}

void list_size(List list, int *size)
{
    (*size) = 0;
    if (list)
    {
        (*size)++;
        while (list->next)
        {
            (*size)++;
            list = list->next;
        }
    }
}

void list_push(List list, void *data)
{
    while (list->next)
    {
        list = list->next;
    }
    list_new(&(list->next), data);
}

void list_pop(List list)
{
    List *tracer = &list;
    while ((*tracer)->next)
    {
        tracer = &(*tracer)->next;
    }
    free((*tracer)->data);
    (*tracer)->data = NULL;
    free((*tracer));
    *tracer = NULL;
}

void list_insert(List *tracer, int index, List insert)
{
    if (!*tracer)
        return;
    while (index > 0)
    {
        tracer = &(*tracer)->next;
        index--;
        if(!*tracer)
            return;
    }
    if (!(*tracer))
        return;
    insert->next = (*tracer);
    (*tracer) = insert;
}

void list_get(List list, int index, List *result)
{
    *result = NULL;
    while (index > 0)
    {
        if (!list->next)
            return;
        list = list->next;
        index--;
    }
    *result = list;
}

void list_print(List list, void (*print)(void *))
{
    while (list)
    {
        print(list->data);
        list = list->next;
    }
}
