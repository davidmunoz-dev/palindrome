/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 10:02:16 2016 David Munoz
** Last update Sat Jun 18 17:10:13 2016 David Munoz
*/

#include "utils.h"
#include "palindrome.h"

int	check_isnum(char **av, int i)
{
  if (av[i + 1] == NULL)
    return (cerr_exit("invalid argument\n", 84));
  if (av[i + 1][0] == '-')
    return (i);
  i++;
  if (my_str_isnum(av[i]) == 0)
    return (cerr_exit("invalid argument\n", 84));
  return (i);
}

int	scnd_check_option(char **av, t_pal *pal, int i)
{
  int	a;

  a = i;
  if (my_strncmp(av[i], "-b", 2) == PAL_OK)
    {
      if ((i = check_isnum(av, i)) == a)
	return (i);
      pal->base = atoi(av[i]);
    }
  else if (my_strncmp(av[i], "-imin", 5) == PAL_OK)
    {
      if ((i = check_isnum(av, i)) == a)
	return (i);
      pal->min = atoi(av[i]);
    }
  else if (my_strncmp(av[i], "-imax", 5) == PAL_OK)
    {
      if ((i = check_isnum(av, i)) == a)
	return (i);
      pal->max = atoi(av[i]);
    }
  else
    return (cerr_exit("invalid argument\n", 84));
  return (i);
}

int	check_option(char **av, t_pal *pal)
{
  int	i;

  i = 2;
  while (av[++i])
    i = scnd_check_option(av, pal, i);
  if (pal->base <= 1 || pal->base > 11)
    return (cerr_exit("invalid argument\n", 84));
  if (pal->min > pal->max)
    return (cerr_exit("invalid argument\n", 84));
  return (PAL_OK);
}

int	check_line(char **av, t_pal *pal)
{
  pal->base = 10;
  pal->min = 0;
  pal->max = 100;
  if (my_strncmp(av[1], "-n", 2) == PAL_OK
      || my_strncmp(av[1],"-p", 2) == PAL_OK)
    {
      if (my_str_isnum(av[2]) == 0)
	return (cerr_exit("invalid argument\n", 84));
      if ((pal->nb = atoi(av[2])) >= INT_MAX
	  || (pal->nb = atoi(av[2])) < 0)
	  return (cerr_exit("invalid argument\n", 84));
      pal->rev_nb = atoi(my_revstr(av[2]));
    }
  else
    return (cerr_exit("invalid argument\n", 84));
  check_option(av, pal);
  return (PAL_OK);
}


int	check_args(int ac, char **av, t_pal *pal)
{
  if (ac == 2)
    help_option_check(ac, av);
  else if (ac > 2)
    check_line(av, pal);
  else
    return (cerr_exit("invalid argument\n", 84));
  return (PAL_OK);
}
