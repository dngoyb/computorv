#ifndef COMPUTOR_H
# define COMPUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct      s_comp
{
    int             exp;
    double          num;
    struct s_comp   *next;
}                   t_comp;

void        add_values(t_comp **head_ref, double num, int exp);
void        ft_clean(t_comp **head);
void        input_read(t_comp **num, char *s);
void        ft_execution(t_comp *num);

#endif