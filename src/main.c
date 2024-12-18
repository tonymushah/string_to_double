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
    printf("%lf\n", parse_sqrt("2V3"));
    printf("%lf\n", parse_sqrt("2"));
    printf("%lf\n", parse_sqrt("V2"));
    printf("%d\n", operator_numbers("2 * 4 * 5", '*'));
    printf("%lf\n", parse_multiply("2 * 4 * 5"));
    printf("%lf\n", parse_division("2 * 3 / V6"));
    printf("%lf\n", parse_add("2 + 3 * V7"));
    printf("%lf\n", parse_substract("2 - 4 + 6 * 0"));
    printf("%lf\n", parse_substract("V2 / 2 + 1"));
    printf("%s\n", rm_envelloppe("((()))"));
    return 0;
}