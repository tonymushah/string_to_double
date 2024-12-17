#include "string_to_double.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int _TRUE = 0;

int _FALSE = 1;

void throw_error(char* message) {
    printf("%s\n", message);
    exit(1);
}

void not_implemented() {
    throw_error("The string to double function is not yet implemented!");
}

const char SQRT_OPERATOR = 'V';

const char PLUS_OPERATOR = '+';

const char MINUS_OPERATOR = '-';

const char DIVIDE_OPERATOR = '/';

const char MULTIPLY_OPERATOR = '*';

const char FLOAT_OPERATOR = '.';

int chars_size(char* chars) {
    int size = 0;
    char cursor = chars[0];
    while (cursor != '\0')
    {
        size++;
        cursor = chars[size];
    }
    return size;
}

void populate_char(char* left, char* right) {
    int cursor_index = 0;
    char cursor = right[cursor_index];
    while (cursor != '\0')
    {
        left[cursor_index] = cursor;
        cursor_index++;
        cursor = right[cursor_index];
    }
}

char* concat_chars(char* left, char* right) {
    int l_size = chars_size(left);
    int r_size = chars_size(right);
    int lr_size = l_size + r_size;
    char* new_chars = malloc((lr_size + 1) * sizeof(char));
    populate_char(new_chars, left);
    populate_char(&new_chars[l_size], right);
    new_chars[lr_size] = '\0';
    return new_chars;
}

void push_char(char** chars, char to_push){
    int chars_len = chars_size(*chars);
    char* new_chars = malloc((chars_len + 2) * sizeof(char));
    populate_char(new_chars, *chars);
    new_chars[chars_len] = to_push;
    new_chars[chars_len + 1] = '\0';
    free(*chars);
    *chars = new_chars;
}

int is_token(char token){
    if (token == SQRT_OPERATOR)
    {
        return _TRUE;
    }
    else if (token == PLUS_OPERATOR)
    {
        return _TRUE;
    }
    else if(token == MINUS_OPERATOR) {
        return _TRUE;
    }
    else if(token == DIVIDE_OPERATOR) {
        return _TRUE;
    }
    else if(token == MULTIPLY_OPERATOR){
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}



int char_to_int(char input){
    switch (input)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        throw_error("invalid char");
        break;
    }
}

int pow_i(int __x, int __y) {
    int res = 1;
    if (__y == 0)
    {
        return 1;
    }
    
    for (int i = 1; i <= __y; i++)
    {
        res = res * __x;
    }
    return res;
}

int chars_to_int(char* input) {
    int res = 0;
    int len = chars_size(input);
    for (int i = 0; i < len; i++)
    {
        res = res + (pow_i(10, i) * char_to_int(input[len - i - 1]));
    }
    return res;
}

char* until_next_token(char* input, int* cursor){
    return "0";
}

double string_to_double(char* input)
{
    double res = 0;
    not_implemented();
    return res;
}