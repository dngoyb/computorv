#include <stdio.h>
#include <stdlib.h>

typedef struct      s_comp
{
    int             exp;
    double          num;
    struct s_comp   *next;
}                   t_comp;

int         ft_num_check(t_comp **head, double num, int exp)
{
    t_comp  *tmp;

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

void        add_values(t_comp **head_ref, double num, int exp)
{
    t_comp  *tmp;

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

int		deleteNode(t_comp **head_ref) 
{
	t_comp *temp = *head_ref, *prev;
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

void	clean(t_comp **head)
{
	int ret;

	ret = deleteNode(head);
	if (ret)
		clean(head);
}

int     check_exponent(t_comp *num)
{
    int     high;

    high = 0;
    while (num)
    {
        if (num->exp > high)
            high = num->exp;
        num = num->next;
    }
    return (high);
}

double  ft_root(double n)
{
  double lo = 0, hi = n, mid;
  for(int i = 0 ; i < 1000 ; i++){
      mid = (lo+hi)/2;
      if(mid*mid == n) return mid;
      if(mid*mid > n){
          hi = mid;
      }else{
          lo = mid;
      }
  }
  return mid;
}

void    ft_math(double a, double b, double c, int exp)
{
    double  x1;
    double  x2;

    x1 = (-b + ft_root(b * b - 4 * a * c)) / (2 * a);
    x2 = (-b - ft_root(b * b - 4 * a * c)) / (2 * a);
    if (exp == 2)
        printf("%.3f\n%.3f\n", x1, x2);
    else
        printf("%.3f\n", (-c / b));
}

void    ft_print(double a, double b, double c, int exp)
{
    (exp == 2 || exp == 1) ? (printf("Reduced form: ")) : 0;
    if (exp == 2)
        printf("%.3fX^2%.3fX^1%.3fX^0 = 0\n", a, b, c);
    else if (exp == 1)
        printf("%.3fX^1%.3fX^0 = 0\n", b, c);
    else
        printf("can't solve: %d exponents\n", exp);
	(exp == 2 || exp == 1) ? ft_math(a, b, c, exp) : 0;
}

void    ft_execution(t_comp *num)
{
    int     exp;
    double  a;
    double  b;
    double  c;

    exp = check_exponent(num);
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

char    *clear_space(char *str)
{
    int i;
    int j;
    char    *ret;

    i = 0;
    while (str[i] != '\0')
        i++;
    ret = (char *)malloc(sizeof(char) * (1 + 1));
    i = -1;
    j = -1;
    while (str[++i] != '\0')
    {
        if (str[i] == ' ')
            ret[++j] = str[i];
    }
    ret[++j] = '\0';
    return (ret);
}

int    main(int c, char **av)
{
    t_comp  *values;

    values = NULL;
    if (c == 2 || c == 1)
    {
        add_values(&values, 1, 2);
		add_values(&values, -2, 1);
		add_values(&values, 1, 0);
		clean(&values);
        ft_execution(values);
    }    
    return 0;
}
