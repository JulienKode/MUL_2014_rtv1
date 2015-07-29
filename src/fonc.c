/*
** fonc.c for  in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Tue Feb 10 15:08:17 2015 Julien Karst
** Last update Mon Mar 16 07:51:30 2015 Julien Karst
*/

#include "rt.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

void    my_str2(char *str)
{
  write(2, str, my_strlen(str));
}

void    my_exit2(char *str)
{
  my_str2(str);
  my_str2("\n");
  exit(1);
}
