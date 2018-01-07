/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 10:02:16 2016 David Munoz
** Last update Fri Jun 17 20:09:11 2016 David Munoz
*/

#include "utils.h"
#include "palindrome.h"

void	aff_palindrome(t_pal *pal, int lead, int i)
{
  pal->solution = 0;
  printf("%d leads to ", lead);
  printf("%d in %d iteration(s) in base %d\n", pal->nb, i, pal->base);
}

int	search_palindrome(int lead, t_pal *pal)
{
  int	i;
  int	lead_base;
  int	rev;
  int	res;

  i = 0;
  res = lead;
  while (res <= pal->nb && i <= pal->max)
    {
      if (res == pal->nb && i >= pal->min)
	{
	  aff_palindrome(pal, lead, i);
	  return (PAL_OK);
	}
      lead_base = convert_to_base(pal->base, res);
      rev = revert_int(lead_base);
      res = lead_base + rev;
      res = binaire(res, pal->base);
      i++;
    }
  return (PAL_ERR);
}

int	option_p(t_pal *pal)
{
  int	lead;
  int	nb_base;

  pal->solution = lead = 1;
  nb_base = convert_to_base(pal->base, pal->nb);;
  if (check_palindrome(nb_base) == PAL_ERR)
    return (PAL_ERR);
  while (lead <= pal->nb)
    {
      search_palindrome(lead, pal);
      lead++;
    }
  if (pal->solution == 0)
    return (PAL_OK);
  return (PAL_ERR);
}
