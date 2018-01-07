/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 10:02:16 2016 David Munoz
** Last update Thu Jun 16 20:28:52 2016 David Munoz
*/

#include "utils.h"
#include "palindrome.h"

void	help_option()
{
  my_putstr("USAGE\n");
  my_putstr("\t./palindrome -n number -p parlindrome ");
  my_putstr("[-b base] [-imin i] [-imax i]\n\nDESCRIPTION\n");
  my_putstr("\t-n nb\tinterger to be transformed (>=0)\n");
  my_putstr("\t-p pal\tparlindromic number to be obtained (incompatible with");
  my_putstr("the -n option) (>=0)\n\t-b base\tbase ");
  my_putstr("in wich the procedure will be executed (1<b<=10) [def: 10]\n");
  my_putstr("\t-imin i\tminimum number of iterations, included");
  my_putstr(" included (>=0) [def: 0]\n\t-imax i\tmaximum number");
  my_putstr("of iterations, included (>=0) [def: 100]\n");
}

int	help_option_check(int ac, char **av)
{
  if (ac == 2)
    {
      if (my_strncmp(av[1], "-h", 2) == PAL_OK)
	{
	  help_option();
	  exit(PAL_OK);
	}
    }
  return (cerr_exit("invalid argument\n", 84));
}
