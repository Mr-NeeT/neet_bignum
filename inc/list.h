#ifndef LIST_H
#define LIST_H

/**
 * @brief Simple single linked list data structure.
 * 
 */
typedef struct _list
{
    void *data;
    struct _list *next;
} * List;

/**
 * @brief Creating new list object.
 * 
 * @param list List reference.
 * @param data Data for the list.
 */
void list_new(List *list, void *data);

/**
 * @brief Get the list size from current head.
 * 
 * @param list List object.
 * @param result Result reference;
 */
void list_size(List list, int *result);

/**
 * @brief Push list with data to the tail of the list.
 * 
 * @param list List object.
 * @param data Data object.
 */
void list_push(List list, void *data);

/**
 * @brief Remove the tail of the list.
 * 
 * @param list List object.
 */
void list_pop(List list);

/**
 * @brief Insert list at specific index.
 * 
 * @param list List object reference.
 * @param index Index to be inserted.
 * @param insert New list object to be inserted.
 */
void list_insert(List *list, int index, List insert);

/**
 * @brief Retrieve the list object at specific index.
 * 
 * @param list List object.
 * @param index Index of the list to be retrieved.
 * @param result Retrieved list object reference;
 */
void list_get(List list, int index, List *result);

/**
 * @brief Print list data.
 * 
 * @param list List object.
 * @param print Data printing function.
 */
void list_print(List list, void (*print)(void *));

#endif
