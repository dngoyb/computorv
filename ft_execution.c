/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <ngbanza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:48:31 by ngbanza           #+#    #+#             */
/*   Updated: 2018/09/25 15:03:07 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int		ft_exponent(t_comp *num)
{
	int		high;

	high = 0;
	while (num)
	{
		if (num->exp > high)
			high = num->exp;
		num = num->next;
	}
	return (high);
}

static double	ft_root(double n)
{
	double	lo;
	double	hi;
	double	mid;
	int		i;

	i = 0;
	lo = 0;
	hi = n;
	while (i < 1000)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid > n)
			hi = mid;
		else
			lo = mid;
	}
	return (mid);
}

static void		ft_math(double a, double b, double c, int exp)
{
	double	x1;
	double	x2;
	double	n;
	double	m;
	int		delta;

	delta = (b * b - 4 * a * c);
	n = -b / (2 * a);
	m = ft_root(ft_abs(delta)) / (2 * a);
	x1 = n + m;
	x2 = n - m;
	if (exp == 2)
	{
		if (delta >= 0)
			printf("%.3f\n%.3f\n", x1, x2);
		else
			printf("%.3f + %.3fi\n%.3f - %.3fi\n", n, m, n, m);
	}
	else
		printf("%.3f\n", (-c / b));
}

void			ft_print(double a, double b, double c, int exp)
{
	(exp == 2 || exp == 1) ? (printf("Reduced form: ")) : 0;
	if (exp == 2)
	{
		printf("%.3fX^2 + %.3fX^1 + %.3fX^0 = 0\n", a, b, c);
		printf("Polynomial degree: %d\n", exp);
		if ((b * b - 4 * a * c) > 0)
			printf("Discriminant is strictly positive \n");
		else if ((b * b - 4 * a * c) < 0)
			printf("Discriminant is strictly negative \n");
		else
			printf("Discriminant is strictly zero and \n");
	}
	else if (exp == 1)
	{
		printf("%.3fX^1 + %.3fX^0 = 0\n", b, c);
		printf("Polynomial degree: %d\n", exp);
	}
	else
	{
		printf("can't solve: %d exponents\n", exp);
		printf("The polynomial degree is greater than 2, I can't solve.\n");
	}
	(exp == 2 || exp == 1) ? ft_math(a, b, c, exp) : 0;
}

void			ft_execution(t_comp *num)
{
	int		exp;
	double	a;
	double	b;
	double	c;

	exp = ft_exponent(num);
	while (num)
	{
		if (num->exp == 2)
			a = num->num;
		if (num->exp == 1)
			b = num->num;
		if (num->exp == 0)
			c = num->num;
		num = num->next;
	}
	ft_print(a, b, c, exp);
}
