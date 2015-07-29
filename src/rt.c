/*
** rt.c for  in /home/karst_j/Epitech/2014-2015/Igraph/MUL_2014_rtv1
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Thu Feb  5 14:44:11 2015 Julien Karst
** Last update Sun Mar 15 19:19:03 2015 Julien Karst
*/

#include "rt.h"

int		main()
{
  t_obj		*o;
  t_window	w;

  window_init(&w);
  creat_list(&o);
  remp_img(&w, o);
  gere_window(&w);
}

void		window_init(t_window *w)
{
  w->x = 500;
  w->y = 500;
  w->xs = 50;
  w->ys = 50;
  w->zs = 50;
  if ((w->mlx_ptr = mlx_init()) == NULL)
    my_exit2("Error -> Mlx_init Failed");
  w->win_ptr = mlx_new_window(w->mlx_ptr, w->x, w->y,
			      "Raytracer - V1 - Julien Karst");
  w->img_ptr = mlx_new_image(w->mlx_ptr, w->x, w->y);
  w->img_tab = (int*)mlx_get_data_addr(w->img_ptr, &(w->bpp),
				       &(w->sizeline), &(w->endian));
}

void		gere_window(t_window *w)
{
  mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
  mlx_hook(w->win_ptr, KeyPress, KeyPressMask, gere_key, w);
  mlx_expose_hook(w->win_ptr, gere_expose, w);
  mlx_loop(w->mlx_ptr);
}
