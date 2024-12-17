#include <stdio.h>
#include <stdlib.h>
#include "string_to_double.h"

int main()
{
    /* char** ss = _split("123.534", '.', 2);
    printf("%s ; %s\n", ss[0], ss[1]);
    printf("%d\n", chars_to_int("123"));
    printf("result = %lf", string_to_double("V2 + 1"));
    free(ss);
    */
    printf("%s\n", rm_spaces("2 V 3 * 4"));
    printf("%lf\n", parse_floats("123.534"));
    return 0;
}