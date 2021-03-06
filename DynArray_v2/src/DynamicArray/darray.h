#ifndef _DARRAY_H_
#define _DARRAY_H_

#include <stdlib.h>
#include <assert.h>
#include <DynamicArray/debug.h>

typedef char* Item;

typedef struct darray{
    int end;
    int max;
    size_t expand_rate;
    Item** contents;
} DArray;

DArray* DArray_create_p(size_t initial_max);

DArray DArray_create(size_t initial_max);

void DArray_clear(DArray* array);

void DArray_destroy(DArray* array);

void DArray_clear_destroy(DArray* array);

int DArray_expand(DArray* array);

int DArray_contract(DArray* array);

int DArray_push(DArray* array, Item* item);

int DArray_push_(DArray* array, Item item);

Item* DArray_pop(DArray* array);

#define DArray_last(A) ((A)->contents[(A)->end-1])
#define DArray_first(A) ((A)->contents[0])
#define DArray_end(A) ((A)->end)
#define DArray_count(A) DArray_end(A)
#define DArray_max(A) ((A)->max)
#define DArray_free(E) free((E)->contents)
#define DEFAULT_EXPAND_RATE 300

static inline void DArray_set(DArray* array, int i, Item* item)
{
    check(i < array->max, "DArray attempt to set past max");
    if(i > array->end)
        array->end = i;
    array->contents[i] = item;

error:
    return;
}

static inline Item* DArray_get(DArray* array, int i)
{
    check(i < array->max, "DArray attempt to get past max.");

    return array->contents[i];

error:
    return NULL;
}

static inline Item* DArray_remove(DArray* array, int i)
{
    Item* item = array->contents[i];
    array->contents[i] = NULL;

    return item;
}

#endif // #ifndef _DARRAY_H_
