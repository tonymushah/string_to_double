#ifndef STRING_TO_DOUBLE_H
#define STRING_TO_DOUBLE_H

int is_token(char token);
int chars_size(char *chars);
char *concat_chars(char *left, char *right);
char *until_next_token(char *input, int *cursor);
double string_to_double(char *input);
int chars_to_int(char *input);
double parse_floats(char *input);
char **_split(char *input, char to_split, int size);
char *rm_spaces(char *input);
double parse_sqrt(char *input);
int operator_numbers(char *input, char operator);
double parse_multiply(char *input);
double parse_division(char *input);
double parse_add(char *input);
double parse_substract(char *input);

#endif