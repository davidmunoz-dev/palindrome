/*
** base.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 18:10:17 2016 David Munoz
** Last update Fri Jun 17 22:52:35 2016 David Munoz
*/

#include "utils.h"
#include "palindrome.h"

int	binaire(int n, int base)
{
  int	s;
  int	i;

  s = 0;
  i = 0;
  while (n > 0)
    {
      s += (n%10) * my_power_rec(base,i);
      n /= 10;
      i++;
    }
  return (s);
}

int	convert_to_base(int base, int nb)
{
  char	*str;
  int	number;
  int	k;
  int	tmp;

  str = NULL;
  if ((str = malloc(sizeof(char *) + 100)) == NULL)
    return (-1);
  k = 0;
  while (nb != 0)
    {
      tmp = nb;
      nb = nb / base;
      if (nb * base == tmp)
	str[k++] = '0';
      else
	str[k++] = tmp - nb * base + 48;
    }
  str[k] = 0;
  str = my_revstr(str);
  number = atoi(str);
  free(str);
  return (number);
}
