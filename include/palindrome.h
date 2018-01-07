/*
** palindrome.h for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:11:31 2016 David Munoz
** Last update Fri Jun 17 11:46:14 2016 David Munoz
*/

#ifndef PALINDROME_H_
# define PALINDROME_H_

typedef struct	s_pal
{
  int	nb;
  int	rev_nb;
  int	base;
  int	min;
  int	max;
  int	solution;
}		t_pal;

int     cerr_exit(char *log, int status);
/*
** check
*/
int     help_option_check(int ac, char **av);
int     check_args(int ac, char **av, t_pal *pal);

/*
** utils
*/
int     revert_int(int nb);
int     palindrome_pair(char *str, int lenght);
int     check_palindrome(int nb);

/*
** option
*/
int     option_n(t_pal *pal);
int	option_p(t_pal *pal);
int     convert_to_base(int base, int nb);
int     binaire(int n, int base);

#endif /* PALINDROME_H_ ! */
