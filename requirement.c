/*
** requirement.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:13:03 2016 David Munoz
** Last update Sat Jun 18 09:36:07 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>

int	my_factrec_synthesis(int nb)
{
  int	i;

  i = 0;
  if (nb >= 13 || nb < 0)
    return (0);
  else if (nb > 1 && nb < 13)
    {
      i = nb * my_factrec_synthesis(nb - 1);
      return (i);
    }
  else
    return (1);
  return (0);
}

int	my_squareroot_synthesis(int nb)
{
  int   a;

  a = 0;
  if (nb == 0 || nb == 1)
    return (nb);
  if (nb < 4)
    return (-1);
  while (a * a < nb)
    a++;
  if (a * a == nb)
    return (a);
  return (-1);
}
