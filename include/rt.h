/*
** wolf.h for  in /home/karst_j/rendu/Wolf3D
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Fri Dec  5 14:59:53 2014 Julien Karst
** Last update Mon Mar 16 07:53:33 2015 Julien Karst
*/

#ifndef RT_H_
# define RT_H_

#define REFRESH_RATE 30

#define EYEX -300
#define EYEY 0
#define EYEZ 50

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include <X11/XKBlib.h>
#include "mlx_int.h"

typedef struct	s_plan
{
  double	k;
  double	z;
  int		color;
}		t_plan;

typedef struct	s_calc
{
  double	x1;
  double	y1;
  double	z1;
  double	x2;
  double	y2;
  double	z2;
  double	x3;
  double	y3;
  double	z3;
  double	x4;
  double	y4;
  double	z4;
  double	px;
  int		x;
  int		y;
}		t_calc;

typedef struct	s_obj
{
  int		type;
  double	px;
  double	py;
  double	pz;
  double	a;
  double	b;
  double	r;
  double	d;
  double	k;
  double	k1;
  double	k2;
  double	dx;
  double	dy;
  double	dz;
  int		color;
  struct s_obj 	*next;
}		t_obj;

typedef struct  s_window
{
  void          *mlx_ptr;
  void          *win_ptr;
  void          *img_ptr;
  int           *img_tab;
  int           bpp;
  int           sizeline;
  int           endian;
  int           color;
  int           x;
  int           y;
  int           xs;
  int           ys;
  int           zs;
  t_plan        p;
  t_calc	*c;
  t_obj		*o;
  t_obj		*cone;
}               t_window;

void		calc2(t_window *w, t_calc *c, int x, int y);
int		gere_key(int keycode, t_window *w);
int		gere_expose(t_window *w);
void		window_init(t_window *w);
void		gere_window(t_window *w);
void		my_exit2(char *str);
void		my_str2(char *str);
int		my_strlen(char *str);
void		remp_img(t_window *w, t_obj *o);
int		calc(t_window *w, t_obj *o,int x, int y);
void		init_calc(t_calc *c, t_window *w, int x, int y);
void		sphere(t_calc *c, t_obj *o);
void		creat_obj(t_obj **o);
void		init_obj(t_obj *o);
void		creat_list(t_obj **o);
void		init_obj_cyl(t_obj *o);
void		make_trans(t_calc *c, t_obj *o);
void		normal_trans(t_calc *c, t_obj *o);
void		init_obj_cone(t_obj *o);
void		cone_f(t_calc *c, t_obj *o);

#endif /* RT_H_ */
