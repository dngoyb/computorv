#include "computor.h"

static double      concat(int a, int b){
    double c;
    c = (double)b;
    while( c > 1.0f ) 
        c *= 0.1f;
    c = (double)a + c;
    return (c); 
}

static int         first_num(char **s, int *sign, int *side)
{
    int first;

    first = 0;
    if (*(*s) == '=')
    {
        *side = -1;
        (*s)++;
    }
    if (*(*s) == '+' || *(*s) == '-')
    {
        *sign = (*(*s) == '-') ? -1 : 1;
        (*s)++;
    }
    while (isdigit(*(*s)))
    {
        first *= 10;
        first += *(*s) - '0';
        (*s)++;
    }
    return (first);
}

static double      float_number(char **s, int *side)
{
    int first;
    int last;
    int sign;

    sign = 1;
    last = 0;
    first = first_num(s, &sign, side);
    if (*(*s) == '.')
    {
        (*s)++;
        while (isdigit(*(*s)))
        {
            last *= 10;
            last += *(*s) - '0';
            (*s)++;
        }
    }
    return (concat(first, last) * sign * (*side));
}

static int     check_exponent(char **s)
{
    int exp;

    exp = 0;
    while (*(*s) == '*' || *(*s) == 'X' || *(*s) == '^')
        (*s)++;
    if (isdigit(*(*s)))
    {
        while (isdigit(*(*s)))
        {
            exp *= 10;
            exp += *(*s) - '0';
            (*s)++;
        }
    }
    else
        return (1);
    return (exp);
}

void    input_read(t_comp **num, char *s)
{
    double  n;
    int     side;
    int     exp;

    side = 1;
    while (*s)
    {
        n = float_number(&s, &side);
        if (*s == '+' || *s == '-')
            add_values(num, n, 0);
        else
        {
            exp = check_exponent(&s);
            add_values(num, n, exp);
        }
    }
}