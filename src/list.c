/*
** list.c for  in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Mon Mar  2 15:19:51 2015 Julien Karst
** Last update Sun Mar 15 21:43:30 2015 Julien Karst
*/

#include "rt.h"

void	creat_list(t_obj **o)
{
  *o = NULL;
  creat_obj(o);
  init_obj(*o);
  creat_obj(o);
  init_obj_cyl((*o)->next);
}

void	creat_obj(t_obj **o)
{
  t_obj	*new;

  if ((new = malloc(1 * sizeof(t_obj))) == NULL)
    exit(1);
  new->next = NULL;
  if (*o == NULL)
    *o = new;
  else
    (*o)->next = new;
}

void	init_obj(t_obj *o)
{
  o->color = 0xFF0000;
  o->type = 1;
  o->dx = 50;
  o->dy = -150;
  o->dz = 0;
}

void    init_obj_cyl(t_obj *o)
{
  o->color = 0xD40200;
  o->type = 2;
  o->dx = 0;
  o->dy = 0;
  o->dz = 0;
}

void    init_obj_cone(t_obj *o)
{
  o->color = 0xD40200;
  o->type = 3;
  o->dx = 0;
  o->dy = 0;
  o->dz = 0;
}
