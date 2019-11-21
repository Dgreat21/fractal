/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:50:50 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/18 17:16:31 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** ************************************************************************** **
**                                      Include
** ************************************************************************** **
*/

# include <math.h>
# include "libft.h"
# include "complex.h"
# include "keys.h"
# include <mlx.h>
# include <OpenCL/opencl.h>

/*
** ************************************************************************** **
**                                      Define
** ************************************************************************** **
*/

# define LEN 100
# define WIDE 1000
# define LENGTH 1000

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

# define MAX_ITER			100
# define MAX_X				2.0
# define MIN_X				-2.0
# define MIN_Y				-2.0
# define MAX_Y				MIN_Y + (MAX_X - MIN_X) * LENGTH / WIDE
# define SHIFT_X			(MAX_X - MIN_X) / (WIDE - 1)
# define SHIFT_Y			(MAX_Y - MIN_Y) / (LENGTH - 1)
# define S_MANDELBROT		"MANDELBROT"
# define S_JULIA			"JULIA"
# define S_BSHP				"BURNING SHIP"
# define MANDELBROT			1
# define JULIA				2
# define BSHP				3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

/*
** ************************************************************************** **
**                              Definition and typedef
** ************************************************************************** **
*/

typedef char*		t_string;

typedef struct			s_cl
{
	char				*file;
	int					*i_arg;
	double				*f_arg;
	cl_mem				cl_data;
	cl_mem				cl_i_arg;
	cl_mem				cl_f_arg;
	cl_platform_id		pid;
	cl_device_id		d_id;
	cl_uint				ret_num_platforms;
	cl_context			cont;
	cl_command_queue	queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_uint				ret_num_devices;
}						t_cl;

typedef struct			s_argb
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		a;
}						t_argb;

typedef union			u_color
{
	int					hex_color;
	t_argb				rgb;
}						t_color;

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
	t_color				hue;
	t_color				color;
}						t_point;

enum					e_o{Y, X};

typedef struct			s_mlx
{
	int					wide;
	int					length;
	int					mid[2];
	void				*mp;
	void				*wp;
	void				*img;
	int					*data;
	int					bpp;
	int					line_size;
	int					endian;
}						t_mlx;

typedef struct			s_fractol
{
	t_mlx				*mlx;
	int					key;
	int					iter;
	int					color;
	int					pow;
	int					mouse;
	double				speed;
	double				ud;
	double				lr;
	double				minx;
	double				maxx;
	double				miny;
	double				maxy;
	double				shift_x;
	double				shift_y;
	double				zoom;
	t_point				mouse_pos;
	t_complex			cmplx;
	t_cl				*cl;
}						t_all;

/*
** *****************************************************************************
**                                   Function                                 **
** *****************************************************************************
*/

int						brightness(t_color hue, float k);

float					perc(float start, float end, float cur);

t_point					set_dot(float x, float y);

int						mouse_hand(int x, int y, void *param);

int						mouse_click(int button, int x, int y, void *param);

int						key_press(int key, void *param);

int						get_color(int max_iter, int iteration);

void					fractol(t_all *win);

void					hook_init(t_all *all);

void					draw(t_all *all);

t_all					*init();

void					mandelbrot(t_all *all);

void					julia(t_all *all);

void					burning_ship(t_all *all);

void					put_pixel(t_all *all, int x, int y, int iteration);

void					fill_arg(t_all *all, int *mem, double *dmem);

void					*create_buf(t_all *all);

void					*init_cl(t_all *all);

void					*run_fractol(t_all *f);

void					fill_background(int color, t_all *f);

void					*run_fractol(t_all *f);

#endif
