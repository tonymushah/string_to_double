#include "string_to_double.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int _TRUE = 0;

int _FALSE = 1;

void throw_error(char *message)
{
    printf("%s\n", message);
    exit(1);
}

void not_implemented()
{
    throw_error("The string to double function is not yet implemented!");
}

int chars_size(char *chars)
{
    int size = 0;
    char cursor = chars[0];
    while (cursor != '\0')
    {
        size++;
        cursor = chars[size];
    }
    return size;
}

void populate_char(char *left, char *right)
{
    int cursor_index = 0;
    char cursor = right[cursor_index];
    while (cursor != '\0')
    {
        left[cursor_index] = cursor;
        cursor_index++;
        cursor = right[cursor_index];
    }
}

char *concat_chars(char *left, char *right)
{
    int l_size = chars_size(left);
    int r_size = chars_size(right);
    int lr_size = l_size + r_size;
    char *new_chars = malloc((lr_size + 1) * sizeof(char));
    populate_char(new_chars, left);
    populate_char(&new_chars[l_size], right);
    new_chars[lr_size] = '\0';
    return new_chars;
}

void push_char(char **chars, char to_push)
{
    int chars_len = chars_size(*chars);
    char *new_chars = malloc((chars_len + 2) * sizeof(char));
    populate_char(new_chars, *chars);
    new_chars[chars_len] = to_push;
    new_chars[chars_len + 1] = '\0';
    free(*chars);
    *chars = new_chars;
}

char *init_empty_chars()
{
    char *new = malloc(sizeof(char));
    new[0] = '\0';
    return new;
}

char *rm_spaces(char *input)
{
    char *res = init_empty_chars();
    int cursor_index = 0;
    char cursor = input[cursor_index];
    while (cursor != '\0')
    {
        if (cursor != ' ')
        {
            push_char(&res, cursor);
        }
        cursor_index++;
        cursor = input[cursor_index];
    }
    return res;
}

const char SQRT_OPERATOR = 'V';

const char PLUS_OPERATOR = '+';

const char MINUS_OPERATOR = '-';

const char DIVIDE_OPERATOR = '/';

const char MULTIPLY_OPERATOR = '*';

const char FLOAT_OPERATOR = '.';

int is_token(char token)
{
    if (token == SQRT_OPERATOR)
    {
        return _TRUE;
    }
    else if (token == PLUS_OPERATOR)
    {
        return _TRUE;
    }
    else if (token == MINUS_OPERATOR)
    {
        return _TRUE;
    }
    else if (token == DIVIDE_OPERATOR)
    {
        return _TRUE;
    }
    else if (token == MULTIPLY_OPERATOR)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

int char_to_int(char input)
{
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

int pow_i(int __x, int __y)
{
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

int chars_to_int(char *input)
{
    int res = 0;
    int len = chars_size(input);
    for (int i = 0; i < len; i++)
    {
        res = res + (pow_i(10, i) * char_to_int(input[len - i - 1]));
    }
    return res;
}

char **init_chars_table(int size)
{
    char **new_table = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        new_table[i] = malloc(1 * sizeof(char));
        new_table[i][0] = '\0';
    }
    return new_table;
}

char **_split(char *input, char to_split, int size)
{
    char **splitted = init_chars_table(size);
    int splitted_index = 0;
    int cursor_index = 0;
    char cursor = input[cursor_index];
    while (cursor != '\0')
    {
        if (splitted_index > size)
        {
            // printf("%d;%d\n", splitted_index, size);
            break;
        }
        if (cursor == to_split)
        {
            splitted_index++;
        }
        else
        {
            push_char(&(splitted[splitted_index]), cursor);
        }
        cursor_index++;
        cursor = input[cursor_index];
    }
    return splitted;
}

void free_chars_table(char **chars_table, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(chars_table[i]);
    }
    free(chars_table);
}

double parse_floats(char *input)
{
    char **splitted = _split(input, FLOAT_OPERATOR, 2);
    double res = chars_to_int(splitted[0]) + (chars_to_int(splitted[1]) / pow(10, chars_size(splitted[1])));
    free_chars_table(splitted, 2);
    return res;
}

double parse_sqrt(char *input)
{
    char **splitted = _split(rm_spaces(input), SQRT_OPERATOR, 2);
    double left = parse_floats(splitted[0]);
    double right = sqrt(parse_floats(splitted[1]));
    double res;
    if (left != 0 && right == 0)
    {
        res = left;
    }
    else if (left == 0 && right != 0)
    {
        res = right;
    }
    else
    {
        res = left * right;
    }

    free_chars_table(splitted, 2);
    return res;
}

int operator_numbers(char *input, char operator)
{
    int env_count = 0;
    int count = 0;
    int cursor_index = 0;
    char cursor = input[cursor_index];
    while (cursor != '\0')
    {
        if (cursor == '(')
        {
            env_count++;
        }
        else if (cursor == ')')
        {
            env_count--;
        }
        if (env_count == 0)
        {
            if (cursor == operator)
            {
                count++;
            }
        }
        cursor_index++;
        cursor = input[cursor_index];
    }
    return count;
}

double parse_multiply(char *input)
{
    int multiply_number = operator_numbers(input, MULTIPLY_OPERATOR) + 1;

    char **_splitted = _split(rm_spaces(input), MULTIPLY_OPERATOR, multiply_number);
    double res = 1;
    for (int i = 0; i < multiply_number; i++)
    {

        res = res * parse_sqrt(_splitted[i]);
    }
    return res;
}

double parse_division(char *input)
{
    int division_number = operator_numbers(input, DIVIDE_OPERATOR) + 1;
    char **_splitted = _split(rm_spaces(input), DIVIDE_OPERATOR, division_number);
    double res = parse_multiply(_splitted[0]);
    for (int i = 1; i < division_number; i++)
    {
        res = res / parse_multiply(_splitted[i]);
    }
    return res;
}

double parse_add(char *input)
{
    int add_number = operator_numbers(input, PLUS_OPERATOR) + 1;
    char **_splitted = _split(rm_spaces(input), PLUS_OPERATOR, add_number);
    double res = 0;
    for (int i = 0; i < add_number; i++)
    {
        res = res + parse_division(_splitted[i]);
    }
    return res;
}

double parse_substract(char *input)
{
    int add_number = operator_numbers(input, MINUS_OPERATOR) + 1;
    char **_splitted = _split(rm_spaces(input), MINUS_OPERATOR, add_number);
    double res = parse_add(_splitted[0]);
    for (int i = 1; i < add_number; i++)
    {
        res = res - parse_add(_splitted[i]);
    }
    return res;
}

char *rm_envelloppe(char *input)
{
    char *res = init_empty_chars();
    int is_starting = 0;
    int env_count = 0;
    int cursor_index = 0;
    char cursor = input[cursor_index];
    while (cursor != '\0')
    {
        if (cursor == '(')
        {
            env_count++;
            if (is_starting == 0)
            {
                is_starting = 1;
            }
            else
            {
                push_char(&res, cursor);
            }
        }
        else if (cursor == ')')
        {
            env_count--;
            if (is_starting == 0)
            {
                is_starting = 1;
            }
            if (env_count != 0)
            {
                push_char(&res, cursor);
            }
        }
        if (is_starting == 1 && env_count == 0)
        {
            return res;
        }
        cursor_index++;
        cursor = input[cursor_index];
    }
    return res;
}

char *until_next_token(char *input, int *cursor)
{
    return "0";
}

double string_to_double(char *input)
{
    double res = 0;
    not_implemented();
    return res;
}
