/*
** my_expose.c for  in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Thu Feb  5 15:19:58 2015 Julien Karst
** Last update Tue Feb 10 15:00:26 2015 Julien Karst
*/

#include "rt.h"

int     gere_expose(t_window *w)
{
  mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
  return (0);
}
