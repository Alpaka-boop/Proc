#include <assert.h>
#include <stdlib.h>

#include "stack.h"

void stack_init (STACK *st, size_t capacity)
{
    assert(st);

    st->size = 0;
    st->data = (elem_t *) calloc(capacity, sizeof(elem_t));
    st->capacity = capacity * (st->data != NULL);
}

void stack_push (STACK *st, elem_t value)
{
    if (st->size < st->capacity)
        st->data[st->size++] = value;
    else 
    {
        stack_resize(st);

        if (st->size < st->capacity)
            st->data[st->size++] = value;
    }
}

void stack_resize(STACK *st)
{
    assert(st);
    if (st->capacity == 0)
    {
        if (st->data == NULL)
        {
            st->data = (elem_t *) calloc(START_SIZE_OF_STACK, sizeof(elem_t));
            st->capacity = START_SIZE_OF_STACK * (st->data != NULL);
        }

        else
        {
            st->data = (elem_t *) realloc(st->data, START_SIZE_OF_STACK);
            st->capacity = START_SIZE_OF_STACK * (st->data != NULL);
        }
    }

    else if (st->size >= st->capacity)
    {
        st->data = (elem_t *) realloc(st->data, st->capacity * 4);
        
        if (st->data != NULL)
            st->capacity *= 4;
    }

    else if (st->size < st->capacity / 2)
    {
        st->data = (elem_t *) realloc(st->data, st->capacity / 2 + 1);

        if (st->data != NULL)
            st->capacity = st->capacity / 2 + 1;
    }
}

void stack_pop (STACK *st, elem_t *value)
{
    if (st->data != NULL && st->size >= 1)
    {
        *value = st->data[st->size - 1];
        st->data[st->size - 1] = DELITED_NUM;
        st->size--;
    }

    stack_resize(st);
}

void stack_delete (STACK *st)
{
    if (st->data != NULL)
    {
        st->size = 0;
        free(st->data);
        st->capacity = 0;
    }
}

void add (STACK *st)
{   
    if (st->size > 1 && st->data != NULL)
    {
        int num1 = 0;
        int num2 = 0;

        stack_pop(st, &num1);
        stack_pop(st, &num2);
        stack_push(st, num1 + num2);
    }

    stack_resize(st);
}

void sub (STACK *st)
{
    if (st->size > 1 && st->data != NULL)
    {
        int num1 = 0;
        int num2 = 0;

        stack_pop(st, &num1);
        stack_pop(st, &num2);
        stack_push(st, num1 - num2);
    }

    stack_resize(st);
}

void multi (STACK *st)
{   
    if (st->size > 1 && st->data != NULL)
    {
        int num1 = 0;
        int num2 = 0;

        stack_pop(st, &num1);
        stack_pop(st, &num2);
        stack_push(st, num1 * num2);
    }

    stack_resize(st);
}

void div (STACK *st)
{   
    if (st->size > 1 && st->data != NULL)
    {
        int num1 = 0;
        int num2 = 0;

        stack_pop(st, &num1);
        stack_pop(st, &num2);

        if (num1 != 0)
        {
            stack_push(st, num1 / num2);
        }

        else
        {
            stack_push(st, num2);
            stack_push(st, num1);
        }
    }

    stack_resize(st);
}

void out (STACK *st)
{   
    int value = 0;

    stack_pop(st, &value);
    printf("Answer: %i\n", value);
}
