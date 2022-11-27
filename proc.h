#ifndef PROC_H
#define PROC_H

#include <stdlib.h>

#include "stack.h"

int read_word (int **arg, int *max_arg_lenth, int *buffer, int *curr_char);
void proc (STACK *st, int *buffer, int buf_len);
size_t read_file (int **buffer);

#endif
