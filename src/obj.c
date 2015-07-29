/*
** obj.c for  in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Sun Mar 15 15:31:10 2015 Julien Karst
** Last update Mon Mar 16 07:53:02 2015 Julien Karst
*/

#include "rt.h"

void		sphere(t_calc *c, t_obj *o)
{
  make_trans(c, o);
  o->k = 0;
  o->a = pow(c->x2, 2) + pow(c->y2, 2) + pow(c->z2, 2);
  o->b = 2 * ((c->x1 * c->x2) + (c->y1 * c->y2) + (c->z1 * c->z2));
  o->r = pow(c->x1, 2) + pow(c->y1, 2) + pow(c->z1, 2) - pow(100, 2);
  o->d = pow(o->b, 2) - (4 * o->a * o->r);
  if (o->d >= 0)
    {
      o->k1 = ((o->b * -1) + sqrt(o->d)) / (2 * o->a);
      o->k2 = ((o->b * -1) - sqrt(o->d)) / (2 * o->a);
      if ((o->k1 > o->k2 && o->k2 >= 0) || (o->k1 < 0 && o->k2 >= 0))
	o->k = o->k2;
      else
	o->k = o->k1;
    }
  else
    o->k = -1;
  normal_trans(c, o);
}

void		cylindre(t_calc *c, t_obj *o)
{
  make_trans(c, o);
  o->k = 0;
  o->a = pow(c->x3, 2) + pow(c->y3, 2);
  o->b = 2 * ((c->x1 * c->x3) + (c->y1 * c->y3));
  o->r = pow(c->x1, 2) + pow(c->y1, 2) - pow(100, 2);
  o->d = pow(o->b, 2) - (4 * o->a * o->r);
  if (o->d >= 0)
    {
      o->k1 = ((o->b * -1) + sqrt(o->d)) / (2 * o->a);
      o->k2 = ((o->b * -1) - sqrt(o->d)) / (2 * o->a);
      if ((o->k1 > o->k2 && o->k2 >= 0) || (o->k1 < 0 && o->k2 >= 0))
	o->k = o->k2;
      else
	o->k = o->k1;
    }
  else
    o->k = -1;
  normal_trans(c, o);
}

void		cone_f(t_calc *c, t_obj *o)
{
  double	angle;
  double	ang;

  make_trans(c, o);
  angle = 50;
  ang = 90 - angle;
  ang = ang * M_PI / 180;
  o->a = pow(c->x4, 2) + pow(c->y4, 2) - (pow(c->z4, 2) * pow(tan(ang), 2));
  o->b = (2 * c->x4 * c->x1) + (2 * c->y4 * c->y1)
    + ((2 * c->z4 * c->z1) * pow(tan(ang), 2));
  o->r = pow(c->x1, 2) + pow(c->y1, 2) - (pow(c->z1, 2) * pow(tan(ang), 2));
  o->d = pow(o->b, 2) - (4 * o->a * o->r);
  if (o->d >= 0)
    {
      o->k1 = ((o->b * -1) + sqrt(o->d)) / (2 * o->a);
      o->k2 = ((o->b * -1) - sqrt(o->d)) / (2 * o->a);
      if ((o->k1 > o->k2 && o->k2 >= 0) || (o->k1 < 0 && o->k2 >= 0))
	o->k = o->k2;
      else
	o->k = o->k1;
    }
  else
    o->k = -1;
  normal_trans(c, o);
}
