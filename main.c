/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:46:38 by ngbanza           #+#    #+#             */
/*   Updated: 2018/09/19 15:55:59 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static char    *clear_space(char *str)
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

