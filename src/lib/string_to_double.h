#ifndef STRING_TO_DOUBLE_H
#define STRING_TO_DOUBLE_H

int is_token(char token);
int chars_size(char* chars);
char* concat_chars(char* left, char* right);
char* until_next_token(char* input, int* cursor);
double string_to_double(char* input);
int chars_to_int(char* input);

#endif