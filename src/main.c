/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 10:02:16 2016 David Munoz
** Last update Fri Jun 17 21:21:01 2016 David Munoz
*/

#include "utils.h"
#include "palindrome.h"

int	go_right_arg(char **av, t_pal *pal)
{
  if (my_strncmp(av[1], "-n", 2) == PAL_OK)
    {
      if ((option_n(pal)) == PAL_ERR)
	return (cerr_zero("No ", "solution\n", PAL_ERR));
    }
  else if (my_strncmp(av[1], "-p", 2) == PAL_OK)
    {
      if ((option_p(pal)) == PAL_ERR)
	return (cerr_zero("No ", "solution\n", PAL_ERR));
    }
  return (PAL_OK);
}

int	main(int ac, char **av)
{
  t_pal *pal;

  if ((pal = malloc(sizeof(t_pal))) == NULL)
    return (cerr_exit(ERR_MALL, 84));
  memset(pal, 0, sizeof(t_pal));
  if (check_args(ac, av, pal) == PAL_ERR)
    return (84);
  if (go_right_arg(av, pal) == PAL_ERR)
    return (84);
  free(pal);
  return (PAL_OK);
}
