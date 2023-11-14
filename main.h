#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);
void print_char(int *char_count, va_list args_list);
void print_str(int *char_count, va_list args_list);
void print_integer(int *char_count, va_list args_list);

#endif
