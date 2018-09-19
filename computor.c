#include "computor.h"

char    *clear_space(char *str)
{
    int i;
    int j;
    char    *ret;

    i = 0;
    while (str[i] != '\0')
        i++;
    ret = (char *)malloc(sizeof(char) * (i + 1));
    i = -1;
    j = -1;
    while (str[++i] != '\0')
    {
        if (str[i] != ' ')
            ret[++j] = str[i];
    }
    ret[++j] = '\0';
    return (ret);
}

int     main(int ac, char **av)
{
    char    *s;
    t_comp  *num;

    num = NULL;
    if (ac == 2)
    {
        s = clear_space(av[1]);
        input_read(&num, s);
        ft_clean(&num);
        ft_execution(num);
    }
    return 0;
}

