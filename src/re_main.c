/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:35:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 05:22:06 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int		key_event(int key, void *wina)
//{
//	t_mlx	*win;
//
//	win = (t_mlx *)wina;
//	if (key == kVK_ANSI_Equal || key == kVK_ANSI_Minus)
//		zoom(key, win);
//	else if (key == kVK_ANSI_KeypadPlus || key == kVK_ANSI_KeypadMinus)
//		zoom_bits(key, win);
//	if (key >= kVK_ANSI_Z || key <= kVK_ANSI_V || key == kVK_ANSI_KeypadDecimal)
//		slave(key, win);
//	if (key == kVK_ANSI_Keypad0 || key > kVK_ANSI_A - 1 || key < kVK_ANSI_D + 1)
//		projection(key, win);
//	if (key >= kVK_ANSI_Keypad1 || key <= kVK_ANSI_Keypad9 || key == kVK_ANSI_O)
//		move(key, win);
//	if (key == kVK_ANSI_L || key == kVK_ANSI_M)
//		coloring(key, win);
//	if (key == kVK_ANSI_H || key == kVK_ANSI_N)
//		color(key, win);
//	ft_bzero(win->data, win->l * win->w * sizeof(int));
//	draw_map(win, win->list);
//	mlx_put_image_to_window(win->mp, win->wp, win->img, 0, 0);
//	return (0);
//}

//void	options(t_mlx *win)
//{
//	win->rotx = 0;
//	win->roty = 0;
//	win->rotz = 0;
//	win->opt.slave = 0;
//	win->opt.bit = 0;
//	win->opt.grad = 0;
//	win->opt.axis = 1;
//	win->low.hex_color = BLUE;
//	win->high.hex_color = RED;
//	win->opt.hue.hex_color = WHITE;
//	win->opt.color = 0;
//	win->scale = 2;
//	win->opt.left_right = 0;
//	win->opt.up_down = 0;
//}


