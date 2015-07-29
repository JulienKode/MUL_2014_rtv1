/*
** my_calc2.c for  in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Sun Mar 15 15:43:24 2015 Julien Karst
** Last update Sun Mar 15 21:41:08 2015 Julien Karst
*/

#include "rt.h"

void    make_trans(t_calc *c, t_obj *o)
{
  c->x1 += o->dx;
  c->y1 += o->dy;
  c->z1 += o->dz;
}

void	normal_trans(t_calc *c, t_obj *o)
{
  c->x1 -= o->dx;
  c->y1 -= o->dy;
  c->z1 -= o->dz;
}
