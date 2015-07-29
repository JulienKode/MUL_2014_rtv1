/*
** my_calc.c for $ in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Tue Feb 10 15:17:00 2015 Julien Karst
** Last update Mon Mar 16 07:48:57 2015 Julien Karst
*/

#include "rt.h"

void		remp_img(t_window *w, t_obj *o)
{
  int	x;
  int	y;

  y = 0;
  x = 0;
  while (y != w->y)
    {
      while (x != w->x)
	{
	  my_put_pixel(w, x, y, calc(w, o, x, y));
	  x++;
	}
      x = 0;
      y++;
    }
  return ;
}

void		init_calc(t_calc *c, t_window *w, int x, int y)
{
  c->x1 = EYEX;
  c->y1 = EYEY;
  c->z1 = EYEZ;
  c->x2 = 100;
  c->y2 = (w->x / 2) - x;
  c->z2 = (w->y / 2) - y;
  c->x3 = 100;
  c->y3 = (w->x / 4) - x;
  c->z3 = (w->y / 4) - y;
  c->x4 = 200;
  c->y4 = (w->x / 1.5) - x;
  c->z4 = (w->y / 1.5) - y;
  return ;
}

void		my_plan(t_obj *o, int x, int y, t_window *w)
{
  double	z;

  w->p.z = ((w->y / 2) - y);
  if (z != 0)
    w->p.k = -w->c->z1 / w->p.z;
  else
    w->p.k = -1;
}

int		calc(t_window *w, t_obj *o, int x, int y)
{
  t_obj		cone;
  t_calc	c;

  w->o = o;
  w->cone = &cone;
  calc2(w, &c, x, y);
  if (o->k > 0 && (w->p.k <= 0 || o->k <= w->p.k) &&
      (o->next->k <= 0 || o->k <= o->next->k)
      && (cone.k <= 0 || o->k <= cone.k))
    return (0x7FC6BC);
  if (((w->p.k > 0 && o->k > w->p.k) || (o->k <= 0 && w->p.k > 0)) &&
      (o->next->k <= 0 || w->p.k < o->next->k)
      && (cone.k <= 0 || w->p.k < cone.k))
    return (0x002F2F);
  if (((o->next->k > 0 && o->k > o->next->k) ||
       (o->k <= 0 && o->next->k > 0)) &&
      (w->p.k <= 0 || o->next->k < w->p.k)
      &&  (cone.k <= 0 || o->next->k < cone.k))
    return (0x046380);
  if (((cone.k > 0 && o->k > cone.k) || (o->k <= 0 && cone.k > 0)) &&
      (o->next->k <= 0 || cone.k < o->next->k)
      && (w->p.k <= 0 || cone.k < w->p.k))
    return (0x333333);
  return (0x000000);
}

void		calc2(t_window *w, t_calc *c, int x, int y)
{
  w->c = c;
  w->cone->dx = 0;
  w->cone->dy = 0;
  w->cone->dz = 0;
  init_calc(w->c, w, x, y);
  sphere(w->c, w->o);
  cylindre(w->c, w->o->next);
  cone_f(w->c, w->cone);
  my_plan(w->o, x, y, w);
}
