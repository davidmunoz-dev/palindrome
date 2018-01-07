/*
** utils.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 11:24:52 2016 David Munoz
** Last update Fri Jun 17 22:37:13 2016 David Munoz
*/

#include "utils.h"

int	cerr_exit(char *log, int status)
{
  write(2, log, my_strlen(log));
  exit(status);
}

char	*int_to_char(int nb)
{
  char  *buff;

  buff = NULL;
  if ((buff = malloc(sizeof(char *) + 100)) == NULL)
    return (cerr_msg(ERROR, ERR_MALL));
  sprintf(buff, "%d", nb);
  return (buff);
}

int	revert_int(int nb)
{
  char  *buff;

  buff = NULL;
  if ((buff = malloc(sizeof(char *) + 100)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, PAL_ERR));
  sprintf(buff, "%d", nb);
  buff = my_revstr(buff);
  nb = atoi(buff);
  free(buff);
  return (nb);
}

int	palindrome_pair(char *str, int lenght)
{
  int   i;
  int   mid;

  i = 0;
  mid = lenght / 2;
  lenght--;
  while (str[i] == str[lenght] && i < mid)
    {
      i++;
      lenght--;
    }
  if (i == mid)
    return (PAL_OK);
  return (PAL_ERR);
}

int	check_palindrome(int nb)
{
  char	*str;
  int   lenght;

  if ((str = int_to_char(nb)) == NULL)
    return (PAL_ERR);
  lenght = my_strlen(str);
  if (palindrome_pair(str, lenght) == PAL_OK)
    {
      free(str);
      return (PAL_OK);
    }
  return (PAL_ERR);
}
