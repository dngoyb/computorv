/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <ngbanza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:56:48 by ngbanza           #+#    #+#             */
/*   Updated: 2018/09/25 15:19:11 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int		ft_num_check(t_comp **head, double num, int exp)
{
	t_comp		*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->exp == exp)
		{
			tmp->num += num;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void			add_values(t_comp **head_ref, double num, int exp)
{
	t_comp		*tmp;

	if (!*head_ref)
	{
		*head_ref = (t_comp *)malloc(sizeof(t_comp));
		(*head_ref)->num = num;
		(*head_ref)->exp = exp;
		(*head_ref)->next = NULL;
		return ;
	}
	if (!ft_num_check(head_ref, num, exp))
	{
		tmp = (t_comp *)malloc(sizeof(t_comp));
		tmp->num = num;
		tmp->exp = exp;
		tmp->next = *head_ref;
		*head_ref = tmp;
	}
}

static int		delete_node(t_comp **head_ref)
{
	t_comp		*temp;
	t_comp		*prev;

	temp = *head_ref;
	if (temp != NULL && temp->num == 0)
	{
		*head_ref = temp->next;
		free(temp);
		return (1);
	}
	while (temp != NULL && temp->num != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	prev->next = temp->next;
	free(temp);
	return (1);
}

void			ft_clean(t_comp **head)
{
	int		ret;

	ret = delete_node(head);
	if (ret)
		ft_clean(head);
}
