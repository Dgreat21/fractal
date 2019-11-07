/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:50:50 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/07 01:25:37 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

/*
** ************************************************************************** **
** Include
** ************************************************************************** **
*/

# include <math.h>
# include "libft/libft.h"
# include "complex/complex.h"

/*
** ************************************************************************** **
** Define
** ************************************************************************** **
*/

# define LEN 100
# define PI 3.14159265359
# define WIDE 1600
# define LENGTH 1440

# define AQUA 0x00ffff
# define BLACK 0x000000
# define BLUE 0x0000ff
# define FUCHSIA 0xff00ff
# define GRAY 0x808080
# define GREEN 0x008000
# define LIME 0x00ff00
# define MAROON 0x800000
# define NAVY 0x000080
# define OLIVE 0x808000
# define PURPLE 0x800080
# define RED 0xff0000
# define SILVER 0xc0c0c0
# define TEAL 0x008080
# define WHITE 0xffffff
# define YELLOW 0xffff00

# define MAX_ITER		100
# define MAX_X			2.0
# define MIN_X			-2.0
# define MIN_Y			-2.0
# define MAX_Y			MIN_Y + (MAX_X - MIN_X) * LENGTH / WIDE
# define SHIFT_X		(MAX_X - MIN_X) / (WIDE - 1)
# define SHIFT_Y		(MAX_Y - MIN_Y) / (LENGTH - 1)
# define REPEATS		30

/*
** ************************************************************************** **
** Definition and typedef
** ************************************************************************** **
*/

typedef char*		t_string;

typedef struct		s_argb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_argb;

typedef union		u_color
{
	int				hex_color;
	t_argb			rgb;
}					t_color;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	t_color			hue;
	t_color			color;
}					t_point;

enum				e_o{Y, X};

typedef struct		s_mlx
{
	int				wide;
	int				length;
	int				mid[2];
	void			*mp;
	void			*wp;
	void			*img;
	int				*data;
	int				bpp;
	int				lsize;
	int				endian;
}					t_mlx;

//
//typedef struct		s_opt
//{
//	short 			rot;
//	short			slave;
//	short			bit;
//	short			grad;
//	short			color;
//	short			axis;
//	t_color			hue;
//	int				left_right;
//	int				up_down;
//}					t_opt;
//
//enum				e_o{Y, X};
//
//typedef struct		s_mlx
//{
//	void			*mp;
//	void			*wp;
//	int				w;
//	int				l;
//	int				mid[2];
//	t_point			map;
//	unsigned int	scale;
//	struct s_opt	opt;
//	t_point			**list;
//	int				bpp;
//	int				lsize;
//	int				endian;
//	t_color			low;
//	t_color			high;
//	double			rotx;
//	double			roty;
//	double			rotz;
//	char			*data;
//	void			*img;
//}					t_mlx;

typedef struct		s_cmplx
{
	int				key;
	double			c_x;
	double			c_y;
	double			z_x;
	double			z_y;
	double			sqr_z_x;
	double			sqr_z_y;
}					t_cmplx;

typedef struct		s_fractol
{
	t_mlx			*mlx;
	int				key;
	int				it;
	int				mouse;
	int				color;
	double			speed;
	double			ud;
	double			lr;
	double			minx;
	double			maxx;
	double			miny;
	double			maxy;
	double			shift_x;
	double			shift_y;
	double			zoom;
	t_cmplx			*cmplx;
//	t_complex		*cmplx;
}					t_all;



//typedef struct		s_line
//{
//	t_point			d0;
//	t_point			d1;
//	short			dir;
//	float			k;
//	short			show;
//}					t_line;

/*
** ************************************************************************** **
** Function
** ************************************************************************** **
*/

/*
**					main.c
*/

t_mlx				*window(int w, int l);

/*
**					fdf.c
*/

int					brightness(t_color hue, float k);

void				pixel_img(t_mlx *win, t_point dot);

void				pixel_c(t_mlx win, t_point dot);

float				perc(float start, float end, float cur);

//int					grad(float k, t_line l, float x);

/*
**					draw_lines.c
*/

//void				dot_md(t_mlx *win, t_line l);
//
//void				brez(t_mlx *win, t_line l);
//
//void				drawer(t_mlx *win, t_line l);
//
//void				drawer_grad(t_mlx *win, t_line l);

/*
**					struct.c
*/

t_point				set_dot(float x, float y);

t_point				set_dot_c(float x, float y, int hue);

t_point				set_xyz(float x, float y, char *z_color, int color);

void				swap_glist(t_point *a, t_point *b);

//t_line				line(t_point a, t_point b);

/*
**					debug.c
*/

void				vard(char *s, t_point a);

void				vardot(char *s, t_point a);

void				each_dot(t_mlx win, t_point **tab,
		void (*f)(char *, t_point));

/*
**					lines.c
*/

//void				draw_map(t_mlx *win, t_point **map);

/*
**					projection.c
*/

/*
**					events.c
*/

//void				zoom(int key, t_mlx *win);
//
//void				zoom_bits(int key, t_mlx *win);
//
//int					key(int key);
//
//void				projection(int key, t_mlx *win);
//
//void				move(int key, t_mlx *win);
//
//void				slave(int key, t_mlx *win);
//
//void				coloring(int key, t_mlx *win);
//
//void				color(int key, t_mlx *win);

/*
**					handler.c
*/

void				fractol(t_all *win);

#endif
