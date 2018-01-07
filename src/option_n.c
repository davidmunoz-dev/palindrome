/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 10:02:16 2016 David Munoz
** Last update Fri Jun 17 23:08:58 2016 David Munoz
*/

#include "utils.h"
#include "palindrome.h"


void	print_palindrome(t_pal *pal, int i, int res)
{
  int	leader;

  leader = 0;
  if (i <= pal->max)
    {
      leader = binaire(res, pal->base);
      printf("%d leads to ", pal->nb);
      printf("%d in %d iteration(s) in base %d\n", leader, i, pal->base);
      pal->solution = PAL_OK;
    }
}

int	option_n(t_pal *pal)
{
  int	rev;
  int	res;
  int	i;

  i = 0;
  pal->solution = 1;
  res = convert_to_base(pal->base, pal->nb);
  while (check_palindrome(res) != PAL_OK || i < pal->min)
    {
      rev = revert_int(res);
      res = rev + res;
      i++;
    }
  print_palindrome(pal, i, res);
  if (pal->solution == PAL_OK)
    return (PAL_OK);
  return (PAL_ERR);
}
