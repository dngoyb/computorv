/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:56:20 by ngbanza           #+#    #+#             */
/*   Updated: 2018/09/25 14:34:01 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>

typedef struct		s_comp
{
	int				exp;
	double			num;
	struct s_comp	*next;
}					t_comp;

void				add_values(t_comp **head_ref, double num, int exp);
void				ft_clean(t_comp **head);
void				input_read(t_comp **num, char *s);
void				ft_execution(t_comp *num);
int					ft_abs(int x);

#endif
