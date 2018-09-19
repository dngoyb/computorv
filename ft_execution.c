#include "computor.h"

static int     ft_exponent(t_comp *num)
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

static double  ft_root(double n)
{
  double    lo;
  double    hi;
  double    mid;
  int       i;

  i = 0;
  lo = 0;
  hi = n;
  while (i < 1000)
  {
      mid = (lo + hi) / 2;
      if (mid * mid == n) 
        return (mid);
      if (mid * mid > n){
          hi = mid;
      }
      else
      {
          lo = mid;
      }
  }
  return (mid);
}

static void    ft_math(double a, double b, double c, int exp)
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
        printf("%.3fX^2 + %.3fX^1 + %.3fX^0 = 0\n", a, b, c);
    else if (exp == 1)
        printf("%.3fX^1 + %.3fX^0 = 0\n", b, c);
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