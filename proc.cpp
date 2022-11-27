#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>

#include "proc.h"
#include "stack.h"

#define filename "test.code"

int read_word (int **arg, int *max_arg_lenth, int *buffer, int *curr_char)
{
    int arg_lenth = 0;

    for (arg_lenth = 0; 
          buffer[*curr_char] != ' ' && buffer[*curr_char] != '\n' && buffer[*curr_char] != EOF; 
          arg_lenth++, (*curr_char)++)

    {
        (*arg)[arg_lenth] = (char) buffer[*curr_char];

        if (arg_lenth < *max_arg_lenth - 2)
        {
            *arg = (int *) realloc(*arg, (size_t) *max_arg_lenth + 2);
            *max_arg_lenth *= 2;
        }

    }

    (*arg)[arg_lenth] = '\0';

    return arg_lenth;
}

void proc (STACK *st, int *buffer, int buf_len)
{
    enum cmd {
        HLT,
        PUSH,
        MUL, 
        ADD,
        SUB,
        DIV,
        OUT,
    };

    for (int i = 0; i < buf_len; i++)
    {
        int max_arg_len = 30;
        int *arg        = (int *) calloc(max_arg_len, sizeof(int));
        int wrd_len     = read_word(&arg, &max_arg_len, buffer, &i);

        switch (*arg)
        {
            case HLT:
                return;
            case PUSH:
                i++;
                wrd_len = read_word(&arg, &max_arg_len, buffer, &i);
                stack_push(st, *arg);
                break;
            case MUL:
                multi(st);
                break;
            case ADD:
                add(st);
                break;
            case SUB:
                sub(st);
                break;
            case DIV:
                div(st);
                break;
            case OUT:
                out(st);
                break;
            default:
                break;
        }
    }
}

size_t read_file (int **buffer)
{
    FILE *input_file = fopen(filename, "rb");

    assert(input_file);

    struct stat st = {};

    stat(filename, &st);

    size_t number_of_characters = st.st_size / sizeof(char);
    int i = 0;

    *buffer = (int *) calloc(number_of_characters + 1, sizeof(int));

    while (((*buffer)[i++] = fgetc(input_file)) != EOF) {;}

    fclose(input_file);

    return number_of_characters;
}
