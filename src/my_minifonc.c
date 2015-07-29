/*
** my_minifonc.c for  in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Tue Feb 10 15:12:26 2015 Julien Karst
** Last update Tue Feb 10 15:33:38 2015 Julien Karst
*/

#include "rt.h"

int	my_put_pixel(t_window *w, int x, int y, int color)
{
  if ((x >= 0 && x < w->x) && (y >= 0 && y < w->y))
    w->img_tab[y * w->x + x] = color;
  return (0);
}
