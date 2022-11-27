#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <sys/types.h>

typedef int elem_t;


typedef struct STACK {
    size_t size;
    elem_t *data;
    size_t capacity;
} STACK;

#define DELITED_NUM 30

const int START_SIZE_OF_STACK = 30;

void stack_init   (STACK *st, size_t capacity);
void stack_push   (STACK *st, elem_t value);
void stack_pop    (STACK *st, elem_t *value);
void stack_delete (STACK *st);
void stack_resize (STACK *st);
void add          (STACK *st);
void sub          (STACK *st);
void multi        (STACK *st);
void div          (STACK *st);
void out          (STACK *st);

#endif 
